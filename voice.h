#ifndef VOICE_H
#define VOICE_H

#include <QObject>
#include <QTcpSocket>
#include <QAudioInput>
#include "SocketHandler.h"
/*
class Voice : public QObject
{
    Q_OBJECT

private:
    std::unique_ptr<QTcpSocket> sock;
    QAudioInput audioIn;
    QString serverIp;
    quint16 serverPort;
public:
    Voice(QString ip, quint16 port);

signals:
    void messageReady(QString message);
public slots:
    void sendData(QString message);
private slots:
    void dataRecieved();
    void error(QAbstractSocket::SocketError err);
};
*/
#endif // VOICE_H
