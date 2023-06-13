#include "appafficheur.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppAfficheur w;
    w.show();
    return a.exec();
}
