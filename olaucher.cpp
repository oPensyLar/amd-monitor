#include "olaucher.h"

oLaucher::oLaucher(QObject *parent) : QObject(parent)
{    
    procAtiConfig = new QProcess();
}



void oLaucher::launchErrorCrunch(QProcess::ProcessError err)
{

}


int oLaucher::GetPathUtils(int flag, oPrograms *dats)
{

    switch(flag)
    {
        case 6:        
            dats->pathExec = "aticonfig";
        break;        
    }

    return 0;
}


int oLaucher::GetParamAtiConfig(QStringList *arguments)
{

    *arguments << "--odgt";   

    return 0;
}


void oLaucher::ReadStdOutAtiConfig()
{

    QString strTmp = procAtiConfig->readAllStandardOutput();
    //qDebug() << strTmp;
    QStringList list = strTmp.split(" ");

    if(list.size()<13)
    {
        //qDebug() << "[!] malformated Temp GPU" << strTmp;
        return;
    }   

        double grados = list.at(30).toDouble();

    qDebug() << "[+] GPU Temp" << grados;
    
    if(grados>70 && ChkProc(procPyrit->processId())==1)
    {
    }       

        if(grados<55 && ChkProc(procPyrit->processId())==2)
        {
        }
        

}




int oLaucher::ChkProc(qint64 pid)
{


    QFile fProc("/proc/" + QString::number(pid) + "/status");

    if(fProc.open(QIODevice::ReadOnly))
    {
        QTextStream in(&fProc);     
        QString strTmp;

        strTmp = in.readAll();

        if(strTmp.contains("running") || strTmp.contains("sleeping"))
            return 1;

            else
                return 2;               

        fProc.close();
    }

    else
        return -1;


    //return 0;
}



void oLaucher::ReadStdErrAtiConfig()
{

}



int oLaucher::GetTempGpu()
{
     oPrograms dats;

    GetPathUtils(6, &dats);
    GetParamAtiConfig(&dats.args);


    connect(procAtiConfig, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(launchErrorCrunch(QProcess::ProcessError)));
    connect(procAtiConfig, SIGNAL(readyReadStandardOutput()), this, SLOT(ReadStdOutAtiConfig()));
    connect(procAtiConfig, SIGNAL(readyReadStandardError()), this, SLOT(ReadStdErrAtiConfig()));
    connect(procAtiConfig, SIGNAL(error(QProcess::ProcessError)), this, SLOT(launchingError(QProcess::ProcessError)));

    qDebug() << "[+] Get Temp GPU [AtiConfig]";    
    procAtiConfig->start(dats.pathExec, dats.args);
    procAtiConfig->waitForFinished(-1);

    return 0;
}
