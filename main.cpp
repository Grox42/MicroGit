#include "filemanager.h"
#include "consolewriter.h"
#include "logger.h"
#include <QCoreApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTimer timer;
    ConsoleWriter consoleWriter;
    Logger logger;

    QObject::connect(
        &timer, &QTimer::timeout,
        &FileManager::getInstance(),&FileManager::updateing);
    QObject::connect(
        &FileManager::getInstance(), &FileManager::modified,
        &consoleWriter, &ConsoleWriter::write);
    QObject::connect(
        &FileManager::getInstance(), &FileManager::modified,
        &logger, &Logger::log);

    FileManager::getInstance().addFile("resources/file1.txt");
    FileManager::getInstance().addFile("resources/file2.txt");
    FileManager::getInstance().addFile("resources/file3.txt");

    timer.start(100);
    return a.exec();
}
