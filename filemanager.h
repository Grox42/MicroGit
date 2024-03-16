#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "monitoredfile.h"
#include "logger.h"

#include <QObject>
#include <QTimer>
#include <QVector>

class FileManager: public QObject
{
    Q_OBJECT
private:
    QTimer *timer;
    QVector<MonitoredFile> files;
    Logger *logger;
public:
    FileManager(QObject *parent = nullptr);
    void start(qint32 mSec) const;
    void stop() const;
    void addFile(const QString &path);
    void removeFile(const QString &path);
signals:
    void print(qint32 index, const MonitoredFile &monitoredFile);
public slots:
    void checking() const;
};

#endif // FILEMANAGER_H
