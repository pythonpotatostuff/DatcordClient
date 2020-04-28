#ifndef SOCKETS_H
#define SOCKETS_H
#include <QTcpSocket>

namespace Sockets
{
    void connectTo(QTcpSocket& sock, QString ip, quint16 port);
}

#endif // SOCKETS_H
