#include "filemanager.h"

FileManager::FileManager(QObject *parent): QObject{parent} {}

void FileManager::addFile(const QString &path)
{
    files.append(MonitoredFile(path));
}

void FileManager::removeFile(qint32 index)
{
    files.removeAt(index);
}

void FileManager::updateing()
{
    for (qint32 i {0}; i < files.length(); i++)
        if (files[i].update())
            emit modified(i, files[i]);
}
