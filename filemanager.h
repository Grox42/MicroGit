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
    qint32 search(const QString &path) const;
    FileManager(QObject *parent = nullptr);
public:
    static FileManager& getInstance();
    void addFile(const QString &path);
    void removeFile(const QString &path);
signals:
    void modified(qint32 index, const MonitoredFile &monitoredFile);
public slots:
    void updateing();
};

#endif // FILEMANAGER_H
