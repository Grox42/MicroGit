#include "filemanager.h"
#include "consolewriter.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileManager fileManager;
    ConsoleWriter consoleWriter;
    QObject::connect(&fileManager, &FileManager::modified, &consoleWriter, &ConsoleWriter::write);
    return a.exec();
}
