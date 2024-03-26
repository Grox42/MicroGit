#include "filemanager.h"

FileManager::FileManager(QObject *parent): QObject{parent} {}

FileManager& FileManager::getInstance()
{
    static FileManager instance;
    return instance;
}

qint32 FileManager::search(const QString &path) const
{
    QFileInfo newFile(path);
    for (qint32 i {0}; i < files.length(); i++)
        if (files[i].absoluteFilePath() == newFile.absoluteFilePath())
            return i;
    return -1;
}

void FileManager::addFile(const QString &path)
{
    if (search(path) < 0)
        files.append(MonitoredFile(path));
}

void FileManager::removeFile(const QString &path)
{
    qint32 index {search(path)};
    if (index >= 0)
        files.removeAt(index);
}

void FileManager::updateing()
{
    for (qint32 i {0}; i < files.length(); i++)
        if (files[i].update())
            emit modified(i, files[i]);
}
