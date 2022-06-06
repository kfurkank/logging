#ifndef MYLOG_H
#define MYLOG_H

#include <QObject>
#include <QDebug>
#include <QDate>
#include <QTime>
#include <QDir>



class mylog : public QObject
{
    Q_OBJECT
public:
    explicit mylog(QObject *parent = nullptr);

    QString freq;
    double  sayi;
    QString filename;
    double tekrar;
    const QString Logs_file = QDir::currentPath();


    bool Log_Create();
    void read();






};

#endif // MYLOG_H
