#ifndef OLAUCHER_H
#define OLAUCHER_H

#include <QObject>
#include <QDebug>
#include <QFile>
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


public:
    explicit oLaucher(QObject *parent = 0);
    int GetTempGpu();

private:

    QStringList args;
    QProcess *procAtiConfig;
    QProcess *procExecutable;

    int ChkProc(qint64 pid);
    int GetParamAtiConfig(QStringList *arguments);
    int GetPathUtils(int flag, oPrograms *dats);

signals:

//private slots:
public slots:

    //Stdout    
    void ReadStdOutAtiConfig();

    //Errors
    void launchingError(QProcess::ProcessError err);

    //StdErr
    void ReadStdErrAtiConfig();
    

};

#endif // OLAUCHER_H
