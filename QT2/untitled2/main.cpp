#include <QCoreApplication>

#include <QLocalSocket>
#include <QSqlDatabase>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase d;
    QLocalSocket n;
    return a.exec();
}
