#include "Sqex/Socket/SocketWinsock.h"
#include <mswsock.h>
#include <ws2tcpip.h>
#include <iostream>

namespace Sqex {
namespace Socket {

s32 SocketWinsock::Close() {
    closesocket(socketHandle);
    return 0;
}

s32 SocketWinsock::Set_Non_Blocking() {
    u_long enable = 1;
    if (!nonBlocking) {
        ioctlsocket(socketHandle, FIONBIO, &enable);
        nonBlocking = true;
    }
    return 0;
}

s32 SocketWinsock::Recv_From(char* arg0, s32 arg1, sockaddr* arg2, s32* arg3) {
    s32 result = recvfrom(socketHandle, arg0, arg1, 0, arg2, arg3);
    if (result == SOCKET_ERROR) {
        switch (WSAGetLastError()) {
        case WSAEWOULDBLOCK:
        case WSAECONNRESET:
            return -1;
        }
        return -1;
    }
    return result;
}

s32 SocketWinsock::Get_Peer_Name(sockaddr* arg0, s32* arg1) {
    if (getpeername(socketHandle, arg0, arg1) == 0) {
        return 0;
    }
    switch (WSAGetLastError()) {
    case -1:
    case WSAENOTSOCK:
        return WSAENOTSOCK;
    case WSAENOTCONN:
        return WSAENOTCONN;
    }
    return 0x1000;
}

s32 SocketWinsock::Get_Sock_Name(sockaddr* arg0, s32* arg1) {
    if (getsockname(socketHandle, arg0, arg1) == 0) {
        return 0;
    }
    switch (WSAGetLastError()) {
    case -1:
    case WSAENOTSOCK:
        return WSAENOTSOCK;
    case WSAEINVAL:
        return WSAEINVAL;
    }
    return 0x1000;
}

s32 SocketWinsock::Set_Send_Timeout(s32 arg0) {
    if (setsockopt(socketHandle, SOL_SOCKET, SO_SNDTIMEO, reinterpret_cast<const char*>(&arg0), sizeof(arg0)) == 0) {
        return 0;
    }
    switch (WSAGetLastError()) {
    case -1:
    case WSAENOTSOCK:
        return WSAENOTSOCK;
    case WSAEINVAL:
        return WSAEINVAL;
    }
    return 0x1000;
}

s32 SocketWinsock::Set_Recv_Timeout(s32 arg0) {
    if (setsockopt(socketHandle, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<const char*>(&arg0), sizeof(arg0)) == 0) {
        return 0;
    }
    switch (WSAGetLastError()) {
    case -1:
    case WSAENOTSOCK:
        return WSAENOTSOCK;
    case WSAEINVAL:
        return WSAEINVAL;
    }
    return 0x1000;
}

s32 SocketWinsock::Set_Multicast_Interface(const char* arg0) {
    u_long address = inet_addr(arg0);
    if (setsockopt(socketHandle, IPPROTO_IP, IP_MULTICAST_IF, reinterpret_cast<const char*>(&address), sizeof(address)) == 0) {
        return 0;
    }
    switch (WSAGetLastError()) {
    case -1:
    case WSAENOTSOCK:
        return WSAENOTSOCK;
    case WSAEINVAL:
        return WSAEINVAL;
    }
    return 0x1000;
}

void SocketWinsock::Cleanup() {
    WSACleanup();
}

s32 SocketWinsock::Create(s32 arg0) {
    BOOL enable = TRUE;
    unk_08 = arg0;
    s32 type = arg0 ? SOCK_DGRAM : SOCK_STREAM;
    socketHandle = socket(AF_INET, type, 0);
    if (socketHandle == INVALID_SOCKET) {
        return -1;
    }
    if (type == SOCK_DGRAM) {
        BOOL new_behavior = FALSE;
        DWORD bytes_returned;
        if (WSAIoctl(
            socketHandle,
            SIO_UDP_CONNRESET,
            &new_behavior,
            sizeof(new_behavior),
            NULL,
            0,
            &bytes_returned,
            NULL,
            NULL
        ) == SOCKET_ERROR) {
            DWORD error = WSAGetLastError();
            if (error != WSAEWOULDBLOCK) {
                std::cerr << "Error: WSAIoctl(SIO_UDP_CONNRESET) " << error << std::endl;
                return -1;
            }
        }
    }
    else {
        if (setsockopt(socketHandle, IPPROTO_TCP, TCP_NODELAY, reinterpret_cast<const char*>(&enable), sizeof(enable)) < 0) {
            std::cerr << "Error: TCP_NODELAY Fail." << WSAGetLastError() << std::endl;
        }
    }
    return 0;
}

s32 SocketWinsock::Bind(const sockaddr* arg0, s32 arg1) {
    BOOL enable = TRUE;
    if (setsockopt(socketHandle, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<const char*>(&enable), sizeof(enable)) < 0) {
        std::cerr << "Error: SO_REUSEADDR Fail." << WSAGetLastError() << std::endl;
    }
    s32 result = bind(socketHandle, arg0, arg1);
    if (result != 0) {
        std::cerr << "Error: bind(), " << WSAGetLastError() << std::endl;
        return result;
    }
    return 0;
}

s32 SocketWinsock::Listen(s32 arg0) {
    s32 result = listen(socketHandle, arg0);
    if (result < 0) {
        std::cerr << "Error: listen fail. " << WSAGetLastError() << std::endl;
    }
    return result;
}

SOCKET SocketWinsock::Accept() {
    SOCKET result = accept(socketHandle, NULL, NULL);
    if (result == INVALID_SOCKET) {
        s32 error = WSAGetLastError();
        switch (error) {
        case WSAEINTR:
            std::cerr << "Info: accept(): Interrupte " << error << std::endl;
            return 0;
        case WSAECONNABORTED:
            std::cerr << "Info: accept(): Connection Aborted " << error << std::endl;
            return 0;
        case WSAEWOULDBLOCK:
            std::cerr << "Info: accept(): EWOULDBLOCK " << error << std::endl;
            return 0;
        default:
            std::cerr << "Error: accept(): INVALID_SOCKET " << error << std::endl;
            return INVALID_SOCKET;
        }
    }
    return result;
}

s32 SocketWinsock::Connect(const sockaddr* arg0, s32 arg1, s32 arg2) {
    s32 result = connect(socketHandle, arg0, arg1);
    if (result == SOCKET_ERROR) {
        if (WSAGetLastError() != WSAEWOULDBLOCK) {
            std::cerr << "Error: connect()," << WSAGetLastError() << std::endl;
            return -1;
        }
        return -2;
    }
    return result;
}

s32 SocketWinsock::Send(const char* arg0, s32 arg1) {
    s32 result = send(socketHandle, arg0, arg1, 0);
    if (result < 0) {
        if (WSAGetLastError() != WSAEWOULDBLOCK) {
            std::cerr << "Error: send()," << WSAGetLastError() << std::endl;
            return -1;
        }
        return 0;
    }
    return result;
}

s32 SocketWinsock::Recv(char* arg0, s32 arg1) {
    s32 result = recv(socketHandle, arg0, arg1, 0);
    if (result == SOCKET_ERROR) {
        if (WSAGetLastError() != WSAEWOULDBLOCK) {
            std::cerr << "Error: recv()," << WSAGetLastError() << std::endl;
            return -1;
        }
        return -2;
    }
    return result;
}

s32 SocketWinsock::Send_To(const char* arg0, s32 arg1, const sockaddr* arg2, s32 arg3) {
    s32 result = sendto(socketHandle, arg0, arg1, 0, arg2, arg3);
    if (result == SOCKET_ERROR) {
        if (WSAGetLastError() != WSAEWOULDBLOCK) {
            std::cerr << "Error: sendto()," << WSAGetLastError() << std::endl;
            return -1;
        }
        return 0;
    }
    return result;
}

s32 SocketWinsock::pollConnect_() {
    s32 error = 0;
    s32 length = sizeof(error);
    if (getsockopt(socketHandle, SOL_SOCKET, SO_ERROR, reinterpret_cast<char*>(&error), &length) < 0) {
        std::cerr << "pollConnect_(): ret = " << error << std::endl;
        return -1;
    }
    return error;
}

void SocketWinsock::Startup() {
    WSADATA data;
    // BUG: Reads wVersion even if WSAStartup fails
    WSAStartup(MAKEWORD(2, 0), &data);
    if (data.wVersion != MAKEWORD(2, 0)) {
        std::cerr << "Warning: WSAStartup(),Wrong version" << std::endl;
    }
}

} // namespace Socket
} // namespace Sqex
