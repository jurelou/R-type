#ifndef    __CROSSPLATFORMSOCKETS__HPP__
#define    __CROSSPLATFORMSOCKETS__HPP__

#ifdef __GNUC__

#ifdef SERVER
    #include "UnixSocket.hpp"
    #include "UnixServerSocket.hpp"

    class UnixServerSocket;
    typedef UnixServerSocket SocketMonitor;
    typedef UnixSocket MySocket;
#else
	#include    <sys/socket.h>
	#include    <sys/select.h>
	#include    <netinet/in.h>
	#include    <arpa/inet.h>
    #include	"SfmlSocket.hpp"
    typedef   SfmlSocket MySocket;
#endif

#elif defined _WIN64 || _WIN32

#ifdef SERVER

	#include "WindowsSocket.hpp"
	#include "WindowsServerSocket.hpp"

	class WindowsServerSocket;
	typedef WindowsSocket MySocket;
	typedef WindowsServerSocket SocketMonitor;
#else
	#pragma once
	#pragma comment (lib, "Ws2_32.lib")
	#pragma comment (lib, "Mswsock.lib")
	#pragma comment (lib, "AdvApi32.lib")
	
	#include	<winsock2.h>
	#include	"SfmlSocketWindows.hpp"
	typedef SfmlSocketWindows MySocket;
#endif

#endif
#endif