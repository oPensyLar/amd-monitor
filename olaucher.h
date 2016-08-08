#ifndef OLAUCHER_H
#define OLAUCHER_H

#include <QObject>
#include <QDebug>
#include <QProcess>
#include <iostream>
#include <QTimer>


using namespace std;

class oPrograms
{

public:
    QString pathExec;
    QStringList args;

};


class oLaucher : public QObject
{    
    Q_OBJECT

    QStringList args;


public:
    int GetTempGpu();
    int ChkProc(qint64 pid);
    int GetParamAtiConfig(QStringList *arguments);
    int GetPathUtils(int flag, oPrograms *dats);

signals:


//private slots:
public slots:
    //Stdout    
    void ReadStdOutAtiConfig();

    //Errors
    void launchErrorCrunch(QProcess::ProcessError err);
    void launchingError(QProcess::ProcessError err);

    //StdErr
    void ReadStdErrAtiConfig();
    

};

#endif // OLAUCHER_H
