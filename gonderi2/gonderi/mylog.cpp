#include "mylog.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include<QFile>
#include<QtCore>
#include <QIODevice>

#include <QTime>
#include <QTimer>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QDir>
#include <QFileInfoList>
#include <iostream>
#include <QVector>
#include <QThread>




mylog::mylog(QObject *parent)
    : QObject{parent}
{

}


bool mylog::Log_Create()
{
        qDebug()<<QDir::currentPath();
    if(!QDir(Logs_file).exists())
       {
         QDir().mkdir(Logs_file);
       }


    double adet=sayi;
    int secim = freq.toInt();
    double tekrars=tekrar;



    if(secim==1)
    {

    int i=0;
    while(1)
    {

        filename = QString(Logs_file + "/%1_%2.txt").arg(QDate::currentDate().toString("dd_MM_yyyy"))
                                                   .arg(QTime::currentTime().toString("hh_mm_ss"));


        QDateTime t1=QDateTime::currentDateTimeUtc();
        QFile file(filename);

        if(file.open(QIODevice::WriteOnly |QIODevice::Append))
         {
            QTextStream stream(&file);
            stream << t1.isValid() << t1.toString("     ss      ");

         }
        else
            return false;


        QThread::sleep(1*tekrars);

        t1=QDateTime::currentDateTimeUtc();


        i++;
        if(i >= adet)
        {
            QDir dir;
                    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
                    dir.setSorting(QDir::Time | QDir::Reversed);
                    dir.setPath(Logs_file);

            QFileInfoList list = dir.entryInfoList();
            if (list.size() >= sayi)
             {
                for (int i = 0; i < (list.size() - sayi+1); i++)
                 {
                   QString path = list.at(i).absoluteFilePath();
                   QFile file(path);
                   file.remove();
                   QFile file1(filename);

                }



            }

        }

    }


    }



    else if(secim==2){

        int i=0;
        while(1){
            filename = QString(Logs_file + "/%1_%2.txt").arg(QDate::currentDate().toString("dd_MM_yyyy"))
                                                       .arg(QTime::currentTime().toString("hh_mm_ss"));


            QDateTime t1=QDateTime::currentDateTimeUtc();
            QFile file(filename);

            if(file.open(QIODevice::WriteOnly |QIODevice::Append))
             {
                QTextStream stream(&file);
                stream << t1.isValid() << t1.toString("     mm      ");

             }
            else
                return false;



            QThread::sleep(1*60*tekrars);
            t1=QDateTime::currentDateTimeUtc();

            i++;
            if(i >= adet)
            {
                QDir dir;
                        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
                        dir.setSorting(QDir::Time | QDir::Reversed);
                        dir.setPath(Logs_file);

                QFileInfoList list = dir.entryInfoList();
                if (list.size() >= sayi)
                 {
                    for (int i = 0; i < (list.size() - sayi+1); i++)
                     {
                       QString path = list.at(i).absoluteFilePath();
                       QFile file(path);
                       file.remove();
                       QFile file1(filename);

                    }


                }

            }
        }

}



    else if(secim==3){


        int i=0;
        while(1){
            filename = QString(Logs_file + "/%1_%2.txt").arg(QDate::currentDate().toString("dd_MM_yyyy"))
                                                       .arg(QTime::currentTime().toString("hh_mm_ss"));


            QDateTime t1=QDateTime::currentDateTimeUtc();
            QFile file(filename);

            if(file.open(QIODevice::WriteOnly |QIODevice::Append))
             {
                QTextStream stream(&file);
                stream << t1.isValid() << t1.toString("     hh      ");

             }
            else
                return false;


            QThread::sleep(1*60*60*tekrars);

            t1=QDateTime::currentDateTimeUtc();

            i++;
            if(i >= adet)
            {
                QDir dir;
                        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
                        dir.setSorting(QDir::Time | QDir::Reversed);
                        dir.setPath(Logs_file);

                QFileInfoList list = dir.entryInfoList();
                if (list.size() >= sayi)
                 {
                    for (int i = 0; i < (list.size() - sayi+1); i++)
                     {
                       QString path = list.at(i).absoluteFilePath();
                       QFile file(path);
                       file.remove();
                       QFile file1(filename);

                    }



                }

            }

}
    }
}


void mylog::read()
{

    QString jsonStr;
    QString paths = QDir::currentPath();
    paths.append("/config/config.json");
    QString path =paths;

     QFile file( path );
        if(file.open( QIODevice::ReadOnly | QIODevice::Text ) )
        {
            jsonStr = file.readAll();


            QJsonDocument mydoc = QJsonDocument::fromJson(jsonStr.toUtf8());
            QJsonObject myobj = mydoc.object();

            for(auto it = myobj.begin(); it != myobj.end(); it++)
            {
                QString mystr = it.key().toUtf8();
                mystr.append(it.value().toString());

             if( myobj.contains( mystr ) )
                {
                    QJsonObject obj = myobj.value( mystr ).toObject();
                    QStringList keys = obj.keys();
                    qDebug()<<obj;
                    QJsonValue value = obj.value("zamantürü" );
                    freq = value.toString();
                    qDebug()<<"freq"<<freq;
                    QJsonValue value1 = obj.value("dosyafrekansı" );
                    tekrar = value1.toDouble();
                    qDebug()<<"tekrar"<<tekrar;
                    QJsonValue value2 = obj.value("dosyasayısı" );
                    sayi = value2.toDouble();
                    qDebug()<<"sayi"<<sayi;

                     }
                }
              }
}

