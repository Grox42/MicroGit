#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "monitoredfile.h"
#include <QObject>
#include <QVector>

class FileManager: public QObject
{
    Q_OBJECT
private:
    QVector<MonitoredFile> files;
public:
    FileManager(QObject *parent = nullptr);
    void addFile(const QString &path);
    void removeFile(qint32 index);
signals:
    void modified(qint32 index, const MonitoredFile &monitoredFile);
public slots:
    void updateing();
};

#endif // FILEMANAGER_H
