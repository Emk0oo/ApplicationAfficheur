#include "appafficheur.h"
#include "ui_appafficheur.h"
#include <iostream>

AppAfficheur::AppAfficheur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AppAfficheur)
{
    ui->setupUi(this);
    monServeur= new ServeurUDP();

    connect(monServeur, SIGNAL(ordreRecu(QByteArray)), &monAfficheur, SLOT(genererTrame(QByteArray)));
    connect(monServeur, SIGNAL(ordreRecu(QByteArray)), this, SLOT(ordreConsole(QByteArray)));

    if(monAfficheur.isConnect()==true){
        ui->console->setTextColor(Qt::green);
        ui->console->setText("Connexion établie");
    }else{
        ui->console->setTextColor(Qt::red);
        ui->console->setText("La connexion a échoué");
    }
}


AppAfficheur::~AppAfficheur()
{
    delete ui;
}

void AppAfficheur::ordreConsole(QByteArray message){
    monString=QString(message);
    ui->console->setTextColor(Qt::black);
    ui->console->setText(monString);
}

