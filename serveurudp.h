#ifndef SERVEURUDP_H
#define SERVEURUDP_H
#include <QUdpSocket>
#include <QObject>
#include <iostream>
#include <QThread>
#include <QtNetwork/QUdpSocket>

class ServeurUDP : public QObject
{
    Q_OBJECT
public:
    explicit ServeurUDP();
    virtual ~ServeurUDP();
    QUdpSocket *socket;
    QByteArray message;
    QByteArray datagram;
public slots:
        void donneeArrive();
        QByteArray getDatagram();
signals:
     void ordreRecu(QByteArray);
};

#endif // SERVEURUDP_H
