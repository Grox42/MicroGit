#ifndef WRITER_H
#define WRITER_H

#include "monitoredfile.h"
#include "windows.h"
#include <QObject>
#include <QVector>

class Writer: public QObject
{
    Q_OBJECT
private:
    QVector<QString> title { "index", "Name", "Status", "Size", "Path" };
    HANDLE outHundle;
    COORD pos;
public:
    Writer(QObject *parent = nullptr);
    QString sizeToString(qint64 size) const;
public slots:
    void write(qint32 index, const MonitoredFile &monitoredFile);
};

#endif // WRITER_H
