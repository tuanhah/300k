#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<connect_mysql.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_textEdit_textChanged();

    void on_le_search_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    connect_mysql connect;

};

#endif // MAINWINDOW_H
