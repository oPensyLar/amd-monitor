#include <QCoreApplication>
#include <QDebug>
#include "olaucher.h"

#ifdef Q_OS_LINUX
    #include <unistd.h>
#endif

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);    

    oLaucher launch;


    while(true)
    {
        launch.GetTempGpu();        

        #ifdef Q_OS_LINUX
            usleep(100000);
        #endif

    }


    return a.exec();
}
