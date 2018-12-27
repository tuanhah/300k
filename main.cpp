#include "mainwindow.h"
#include <QApplication>
#include <sqlite3.h>
#include<connection.h>
#include<iostream>
#include <QDebug>
using namespace std;
static const QString path = "CSDL_MUONG1.db";


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection con(path);
//    con.createTable();
//    con.search("d");
    if (con.isOpen())
        {
            con.search("sd");


        }
        else
        {
            qDebug() << "Database is not open!";
        }

    w.show();

    return a.exec();
}
