#include "filemanager.h"

FileManager::FileManager(QObject *parent): QObject{parent}
{
    timer = new QTimer(this);
}

void FileManager::start(qint32 mSec) const { timer->start(mSec); }

void FileManager::stop() const { timer->stop(); }

void FileManager::addFile(const QString &path)
{
    files.append(MonitoredFile(path));
}

void FileManager::removeFile(qint32 index)
{
    files.removeAt(index);
}

void FileManager::checking()
{
    for (qint32 i {0}; i < files.length(); i++)
        if (files[i].check())
            emit modified(i, files[i]);
}
