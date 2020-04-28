#include "SocketHandler.h"


bool SocketHandler::connectTo(QTcpSocket* const sock, QString ip, quint16 port)
{
    sock->connectToHost(ip, port);
    if(!messageSock->waitForConnected(5000))
    {
        return false;
    }
    return true;
}


SocketHandler::SocketHandler() :
    messageSock(std::make_unique<QTcpSocket>()),
    voiceSock(std::make_unique<QTcpSocket>()),
    videoSock(std::make_unique<QTcpSocket>())
{
    serverIp = "127.0.0.1";
    serverPort = 6969;

    if(!connectTo(messageSock.get(), serverIp, serverPort))
    {
    }
    if(!connectTo(voiceSock.get(), serverIp, serverPort))
    {
    }
    if(!connectTo(videoSock.get(), serverIp, serverPort))
    {
    }
}


SocketHandler::~SocketHandler()
{
}


QTcpSocket& SocketHandler::getMessageSock() const
{
    return *messageSock;
}


QTcpSocket& SocketHandler::getVoiceSock() const
{
    return *voiceSock;
}


QTcpSocket& SocketHandler::getVideoSock() const
{
    return *videoSock;
}


SocketHandler& SocketHandler::getInstance()
{
    static SocketHandler instance;
    return instance;
}

