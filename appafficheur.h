#ifndef APPAFFICHEUR_H
#define APPAFFICHEUR_H

#include "serveurudp.h"
#include "afficheur.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AppAfficheur; }
QT_END_NAMESPACE

class AppAfficheur : public QMainWindow
{
    Q_OBJECT

public:
    AppAfficheur(QWidget *parent = nullptr);
    ~AppAfficheur();
    ServeurUDP *monServeur;
    Afficheur monAfficheur;

private:
    Ui::AppAfficheur *ui;
    QString monString;

public slots:
    void ordreConsole(QByteArray);

signals:
    void connexionOk();
    void connexionNok();
};
#endif // APPAFFICHEUR_H
