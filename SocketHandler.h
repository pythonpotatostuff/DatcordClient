#ifndef SOCKETHANDLER_H
#define SOCKETHANDLER_H

#include <QTcpSocket>


class SocketHandler
{
private:
    SocketHandler();
    std::unique_ptr<QTcpSocket> messageSock;
    std::unique_ptr<QTcpSocket> voiceSock;
    std::unique_ptr<QTcpSocket> videoSock;
    QString serverIp;
    quint16 serverPort;

    bool connectTo(QTcpSocket* const sock, QString ip, quint16 port);
public:
    ~SocketHandler();
    static SocketHandler& getInstance();

    SocketHandler(const SocketHandler&) = delete;
    void operator=(const SocketHandler&) = delete;

    QTcpSocket& getMessageSock() const;
    QTcpSocket& getVoiceSock() const;
    QTcpSocket& getVideoSock() const;
};


#endif

