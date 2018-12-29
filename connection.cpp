#include "connection.h"
#include <sqlite3.h>
#include<iostream>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

using namespace std;
connection::connection(const QString & path)
{
    m_db = QSqlDatabase :: addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
    if (!m_db.open())
       {
          qDebug() << "Error: connection with database fail";
       }
       else
       {
          qDebug() << "Database: connection ok";

       }
}
connection::~connection()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool connection::search(const QString& name){

    bool success = false;
    if (!name.isEmpty())
        {
//            QString str= m_db.databaseName();
            QSqlQuery querySelect;

            querySelect.prepare("Select * from tbl_word where id=1");

            querySelect.bindValue(":name", name);
            qDebug() << m_db.tables();



//            QSqlQuery query("SELECT * FROM tbl_word where id =1");

//               if (query.next()) {

//                   qDebug() << "1";
//                   QString name = query.value(0).toString();
//                   qDebug()<<name;


//               }


//
            if (querySelect.exec())
                {
                    if (querySelect.first())
                    {
                        QString vl = querySelect.value(1).toString();
//
                        qDebug() << vl ;

                    }
                    else{
                        qDebug()<<querySelect.lastQuery();
                    }
            }
            else

            {
                qDebug() << "search failed: " << querySelect.lastError();
            }
        }
        else
        {
            qDebug() << "add person failed: name cannot be empty";
        }

        return success;
}


bool connection::isOpen()
{
    return m_db.isOpen();
}


bool connection::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE tbl_word1(id INTEGER PRIMARY KEY AUTO_INCREMENT, word TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'tbl_word': one might already exist.";
        success = false;
    }

    return success;
}

bool connection::addData(const QString& word)
{
    bool success = false;

    if (!word.isEmpty())
    {
        QSqlQuery queryAdd;
//        queryAdd.prepare("DELETE FROM tbl_word WHERE word = (:word)");
        queryAdd.prepare("INSERT INTO tbl_word (word) VALUES (:word)");
        queryAdd.bindValue(":word", word);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add person failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add person failed: name cannot be empty";
    }

    return success;
}


