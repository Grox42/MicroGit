#include "filemanager.h"
#include "writer.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileManager fileManager;
    Writer writer;
    QObject::connect(&fileManager, &FileManager::modified, &writer, &Writer::write);
    return a.exec();
}
