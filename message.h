#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QTcpSocket>
#include "SocketHandler.h"

class Message : public QObject
{
    Q_OBJECT

private:
    std::unique_ptr<QTcpSocket> sock;
    QString serverIp;
    quint16 serverPort;
public:
    Message(QString ip, quint16 port);

signals:
    void messageReady(QString message);
public slots:
    void sendData(QString message);
private slots:
    void dataRecieved();
    void error(QAbstractSocket::SocketError err);
};

#endif // MESSAGE_H
