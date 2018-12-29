#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include <QDebug>
#include<connect_mysql.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_textChanged()
{

}

void MainWindow::on_le_search_textChanged(const QString &arg1)
{
    connect_mysql connect;
    if (connect.isOpen()){
        QList<QString> rs;
        ui->lw_result->clear();
        QString word = ui->le_search->text();
        rs= connect.search(word);
        for (int i = 0; i < rs.size(); ++i) {
            ui->lw_result->addItem(rs[i]);
        }

    }
}
