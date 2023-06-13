#include "afficheur.h"
#include <QDebug>
Afficheur::Afficheur()
{
    if (serie->isOpen()==true) {

        qDebug()<< "open";
    }
    else {
        qDebug()<<"pas open";
        emit connexionNok();
    }

    connect(this, SIGNAL(tramePrete(QByteArray)), this, SLOT(envoyerTrame(QByteArray)));
}
void Afficheur::genererTrame(QByteArray val)
{
    qDebug() << "Signal déclenché, méthode genererTrame()";
    int i;
    for (i=0;i<5;i++){
        trame[i]=0x00;
    }
    trame.append(0x01);
    trame.append(0x7A); //'z';
    trame.append(0x30); //'0';
    trame.append(0x30); //'0';
    trame.append(0x02); //2
    trame.append(0x41); //'A';
    trame.append(0x41); //'A';
    trame.append(val); //on récupère les char du textEdit
    trame.append(0x04);

    qDebug() << "trame crée" << val;

    emit tramePrete(trame);

}


