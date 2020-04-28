#include "Sockets.h"

void Sockets::connectTo(QTcpSocket& sock, QString ip, quint16 port)
{
    sock.connectToHost(ip, port);
}
