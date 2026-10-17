#ifndef SQEX_SOCKET_SOCKETWINSOCK_H
#define SQEX_SOCKET_SOCKETWINSOCK_H

#include "Sqex/Socket/SocketBase.h"

namespace Sqex {
namespace Socket {

class SocketWinsock : public SocketBase {
public:
    static void Startup();
    static void Cleanup();

    s32 Close();
    s32 Create(s32 arg0);
    s32 Send(const char* arg0, s32 arg1);
    s32 Recv(char* arg0, s32 arg1);

    virtual s32 Set_Non_Blocking();
    virtual s32 Bind(const sockaddr* arg0, s32 arg1);
    virtual s32 Listen(s32 arg0);
    virtual SOCKET Accept();
    virtual s32 Connect(const sockaddr* arg0, s32 arg1, s32 arg2);
    virtual s32 Send_To(const char* arg0, s32 arg1, const sockaddr* arg2, s32 arg3);
    virtual s32 Recv_From(char* arg0, s32 arg1, sockaddr* arg2, s32* arg3);
    virtual s32 Get_Peer_Name(sockaddr* arg0, s32* arg1);
    virtual s32 Get_Sock_Name(sockaddr* arg0, s32* arg1);
    virtual s32 Set_Send_Timeout(s32 arg0);
    virtual s32 Set_Recv_Timeout(s32 arg0);
    virtual s32 Set_Multicast_Interface(const char* arg0);
    virtual s32 pollConnect_();

protected:
    bool nonBlocking;
};

} // namespace Socket
} // namespace Sqex

#endif
