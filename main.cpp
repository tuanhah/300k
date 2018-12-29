#include "mainwindow.h"
#include <QApplication>
#include <sqlite3.h>

#include<connect_mysql.h>
#include<iostream>
#include <QDebug>
using namespace std;
static const QString path = "CSDL_MUONG1.db";


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;



    w.show();

    return a.exec();
}
