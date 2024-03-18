#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "monitoredfile.h"
#include <QObject>
#include <QTimer>
#include <QVector>

class FileManager: public QObject
{
    Q_OBJECT
private:
    QTimer *timer;
    QVector<MonitoredFile> files;
public:
    FileManager(QObject *parent = nullptr);
    void start(qint32 mSec = 100) const;
    void stop() const;
    void addFile(const QString &path);
    void removeFile(qint32 index);
signals:
    void modified(qint32 index, const MonitoredFile &monitoredFile);
public slots:
    void checking();
};

#endif // FILEMANAGER_H
