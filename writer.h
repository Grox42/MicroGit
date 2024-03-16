#ifndef WRITER_H
#define WRITER_H

#include "monitoredfile.h"

#include <QObject>
#include  <QTextStream>

class Writer: public QObject
{
    Q_OBJECT
private:
    const QString title[3] {"Path", "Status", "Size"};
public:
    Writer(QObject *parent = nullptr);
public slots:
    void printing(qint32 index, const MonitoredFile &monitoredFile);
};

#endif // WRITER_H
