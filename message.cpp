#include "message.h"
#include "Sockets.h"

Message::Message(QString ip, quint16 port) : serverIp(ip), serverPort(port)
{
    sock = std::make_unique<QTcpSocket>();
    connect(sock.get(), &QAbstractSocket::readyRead, this, &Message::dataRecieved);
    connect(sock.get(), QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &Message::error);
    Sockets::connectTo(*sock.get(), serverIp, serverPort);
}


void Message::sendData(QString message)
{
    if(sock.get()->state() == QAbstractSocket::ConnectedState)
    {
        int bytesWritten = 0;
        while(bytesWritten < message.size())
        {
            qint64 ret = sock.get()->write(message.mid(bytesWritten).toUtf8());
            if(ret == -1)
            {
                return;
                //TODO what to do if fail
            }
            bytesWritten += ret;
        }
    }
}


void Message::dataRecieved()
{
    QString data = sock.get()->readAll();
    qDebug() << "[MSG] [RECV]" << data << "\n";
    emit messageReady(data);
}


void Message::error(QAbstractSocket::SocketError err)
{
    qDebug() << "[MSG] [ERR] " << err << "\n";
}
