#include "filemanager.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileManager fileManager;
    return a.exec();
}
