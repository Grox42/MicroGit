#ifndef CONSOLEWRITER_H
#define CONSOLEWRITER_H

#include "monitoredfile.h"
#include "windows.h"
#include <QObject>
#include <QVector>

class ConsoleWriter: public QObject
{
    Q_OBJECT
private:
    QVector<QString> title { "index", "Name", "Status", "Size", "Path" };
    QVector<qint32> sizes {        6,     18,       12,     12,     60 };
    HANDLE hundle {GetStdHandle(STD_OUTPUT_HANDLE)};
    COORD pos {0, 0};
public:
    ConsoleWriter(QObject *parent = nullptr);
    QString sizeToString(qint64 size) const;
public slots:
    void write(qint32 index, const MonitoredFile &monitoredFile);
};

#endif // CONSOLEWRITER_H
