#include <QCoreApplication>
#include<QString>
#include<QDebug>
#include <QFile>
#include<QThread>
#include<QTime>
#include <QElapsedTimer>
#include <QTextStream>

#include "mylog.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    mylog w;
    w.read();
    w.Log_Create();


    return a.exec();
}
