#ifndef    __CROSSPLATFORMTHREADS__HPP__
#define    __CROSSPLATFORMTHREADS__HPP__

#ifdef __GNUC__

# include "UnixThreads.hpp"

typedef UnixThreads Thread;

#elif defined _WIN32

/*# include "WindowsSocket.hpp"
# include "WindowsServerSocket.hpp"

class WindowsServerSocket;
typedef WindowsSocket MySocket;
typedef WindowsServerSocket SocketMonitor;
*/


#endif
#endif      /* __CROSSPLATFORMTHREADS__HPP__ */