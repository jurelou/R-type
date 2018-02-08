#ifndef     __ISOCKET__HPP__
#define     __ISOCKET__HPP__

#include    <string>
#include    <iostream>
//class Server;


class       ISocket
{
public:
    virtual ~ISocket(){};

    virtual bool		Connect(const std::string& host, const std::string& port) = 0;
    virtual bool		ConnectFd(int fd) = 0;

    virtual int 		recv(char **data) = 0;
    virtual int	    	sendv(const std::string& data) = 0;

    virtual void		setUDP(const bool& val) = 0;
    virtual bool		isUDP() const = 0;
    virtual void        setBlocking(bool _) = 0;
    virtual void		setHost(const std::string& ip) = 0;
    virtual const       std::string& getHost() const = 0;

    //for debug
    virtual struct sockaddr_in            getSource() const = 0;
    virtual int         getSocket() const = 0;
};

typedef std::pair<ISocket *, ISocket *> TcpUdpPair;

#endif    /* __ISOCKET__HPP__ */
