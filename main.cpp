#include "mainwindow.h"
#include <QApplication>

bool connectMySQL();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!connectMySQL())
        return -1;

    MainWindow w;
    w.show();

    int r = a.exec();
    if(r == 773)
    {
        QProcess::startDetached(qApp->applicationFilePath(), QStringList());
        return 0;
    }
    return r;
}

bool connectMySQL()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("xxx.xxx.xxx.xxx");
    db.setport(0);
    db.setDatabaseName("sharebookcase");
    db.setUserName("xxxxx");
    db.setPassword("xxxxx");

    if(!db.open())
    {
        QMessageBox::critical(0, QString::fromLocal8Bit("Error Info"),
                              QString::fromLocal8Bit("Can not connect the Database"),
                              QString::fromLocal8Bit("Close"));
        return 0;
    }
    else
    {
        qDebug()<<"Database connection successful";
        return 1;
    }
}
