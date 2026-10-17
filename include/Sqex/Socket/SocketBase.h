#ifndef SQEX_SOCKET_SOCKETBASE_H
#define SQEX_SOCKET_SOCKETBASE_H

#include <winsock2.h>
#include "Sqex/Thread/Mutex.h"
#include "types.h"

namespace Sqex {
namespace Socket {

class SocketBase {
public:
    virtual ~SocketBase() {
    }

    virtual s32 Set_Non_Blocking() = 0;
    virtual s32 func_00D43550(s32 arg0) = 0;
    virtual s32 func_00D44140() = 0;
    virtual s32 Bind(const sockaddr* arg0, s32 arg1) = 0;
    virtual s32 Listen(s32 arg0) = 0;
    virtual SOCKET Accept() = 0;
    virtual s32 Connect(const sockaddr* arg0, s32 arg1, s32 arg2) = 0;
    virtual s32 func_00D44610(const char* arg0, s32 arg1) = 0;
    virtual s32 func_00D44690(char* arg0, s32 arg1) = 0;
    virtual s32 Send_To(const char* arg0, s32 arg1, const sockaddr* arg2, s32 arg3) = 0;
    virtual s32 Recv_From(char* arg0, s32 arg1, sockaddr* arg2, s32* arg3) = 0;
    virtual s32 Get_Peer_Name(sockaddr* arg0, s32* arg1) = 0;
    virtual s32 Get_Sock_Name(sockaddr* arg0, s32* arg1) = 0;
    virtual s32 Set_Send_Timeout(s32 arg0) = 0;
    virtual s32 Set_Recv_Timeout(s32 arg0) = 0;
    virtual s32 Set_Multicast_Interface(const char* arg0) = 0;
    virtual s32 pollConnect_() = 0;

protected:
    SOCKET socketHandle;
    s32 unk_08;
    Thread::Mutex mutex;
};

} // namespace Socket
} // namespace Sqex

#endif
