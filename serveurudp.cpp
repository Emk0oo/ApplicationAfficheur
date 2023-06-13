#include "serveurudp.h"

ServeurUDP::ServeurUDP()
{
    // Creer un socket udp
      socket= new QUdpSocket();

      // Configuration de l'adresse et le port
       socket->bind(QHostAddress::Any, 4000); //QHostAddress::Any --> nécessaire pour configurer le serveur sur un port

       // Connecté le signal à un slot
       connect(socket, SIGNAL(readyRead()), this, SLOT(donneeArrive()));
       qDebug() << "Serveur UDP en écoute:";
}


ServeurUDP::~ServeurUDP(){

    delete socket;
}

void ServeurUDP::donneeArrive()
{
    qDebug() << "reception";
    while (socket->hasPendingDatagrams()) {
        // Read the next datagram

        datagram.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        qDebug() << "Datagram recu : " << datagram;

        emit ordreRecu(datagram);
    }

}


QByteArray ServeurUDP::getDatagram()
{
    return datagram;
}
