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
    fileManager.addFile("../resources/file1.txt");
    fileManager.addFile("../resources/file2.txt");
    fileManager.addFile("../resources/file3.txt");
    timer.start(100);
    return a.exec();
}
