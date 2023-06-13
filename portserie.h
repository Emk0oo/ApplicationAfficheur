#ifndef PORTSERIE_H
#define PORTSERIE_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
class PortSerie : public QObject
{
    Q_OBJECT

public:
    PortSerie();
    QSerialPort *serie;
    bool isConnect();


public slots:
    void envoyerTrame(QByteArray trame);
};


#endif // PORTSERIE_H
