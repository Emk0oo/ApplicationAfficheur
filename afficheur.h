#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include "portserie.h"
#include <QByteArray>
#include <QObject>

class Afficheur : public PortSerie
{
    Q_OBJECT
public:
    Afficheur();

public slots:
    void genererTrame(QByteArray);

private:
    QByteArray trame;

signals:
    void tramePrete(QByteArray);
    void connexionOk();
    void connexionNok();

};


#endif // AFFICHEUR_H
