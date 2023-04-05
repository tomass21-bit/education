#include "mainwindow.h"

#include <QApplication>
#include <QLocalSocket>
#include <QSqlDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSqlDatabase d;
    QLocalSocket n;
    w.show();
    return a.exec();
}
