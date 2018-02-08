#ifndef    __CROSSPLATFORMCLOCK__HPP__
#define    __CROSSPLATFORMCLOCK__HPP__

#ifdef __GNUC__

#include "UnixClock.hpp"

typedef UnixClock Clock;

#elif defined _WIN32

/*# include "WindowsSocket.hpp"
# include "WindowsServerSocket.hpp"

class WindowsServerSocket;
typedef WindowsSocket MySocket;
typedef WindowsServerSocket SocketMonitor;
*/


#endif
#endif      /* __CROSSPLATFORMCLOCK__HPP__ */