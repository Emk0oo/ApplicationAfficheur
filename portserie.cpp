#include "portserie.h"
#include <QDebug>
PortSerie::PortSerie()
{
    qDebug()<< "serie";
    const QString PORT = "/dev/ttyUSB0"; // chemin vers le port série !!!!!
    serie = new QSerialPort(PORT);

    // configuration de la liaison
    serie->setBaudRate(QSerialPort::Baud9600);
    serie->setDataBits(QSerialPort::Data8);
    serie->setParity(QSerialPort::NoParity);
    serie->setStopBits(QSerialPort::OneStop);
    serie->setFlowControl(QSerialPort::NoFlowControl);
    serie->open(QIODevice::ReadWrite);
}

void PortSerie::envoyerTrame(QByteArray trame){
    serie->write(trame);
}

bool PortSerie::isConnect(){
    if (serie->isOpen()==true){
        return true;
    }
    else return false;
}
