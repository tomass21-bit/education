#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   QMessageBox message;
   message.setText("Hello Graphic World");
   message.exec();
    return a.exec();
}
