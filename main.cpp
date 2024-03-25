#include "filemanager.h"
#include "consolewriter.h"
#include <QCoreApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTimer timer;
    FileManager fileManager;
    ConsoleWriter consoleWriter;
    QObject::connect(&timer, &QTimer::timeout, &fileManager, &FileManager::updateing);
    QObject::connect(&fileManager, &FileManager::modified, &consoleWriter, &ConsoleWriter::write);
    return a.exec();
}
