#include "consolewriter.h"
#include <QTextStream>

ConsoleWriter::ConsoleWriter(QObject *parent): QObject{parent}
{
    SetConsoleTitle(L"MicroGit");

    QVector<QString> title { "index", "Name", "Status", "Size", "Path" };

    QTextStream out(stdout);
    out << Qt::left;
    for (qint32 i {0}; i < title.length() - 1; i++)
        out << qSetFieldWidth(sizes[i]) << title[i];
    out << Qt::reset << title.last() << Qt::endl;
}

QString ConsoleWriter::sizeToString(qint64 size) const
{
    char prefix[] { 'K', 'M', 'G', 'T', 'P', 'E' };
    qint32 index = -1;
    qreal newSize {static_cast<qreal>(size)};
    while (newSize >= 1024) {
        newSize /= 1024;
        index++;
    }
    if (index > -1 && index < 6)
        return QString().setNum(newSize, 'd', 1) + ' ' + prefix[index] + 'b';
    else
        return QString().setNum(newSize, 'd', 1) + " b";
}

void ConsoleWriter::write(qint32 index, const MonitoredFile &monitoredFile)
{
    SetConsoleCursorPosition(hundle, {0, static_cast<qint16>(index + 1)});

    QVector<QString> data {
        QString().setNum(index),
        monitoredFile.fileName(),
        monitoredFile.exists() ? "exists" : "not exist",
        sizeToString(monitoredFile.size()),
        monitoredFile.filePath()
    };

    QTextStream out(stdout);
    out << Qt::left;
    for (qint32 i {0}; i < data.length() - 1; i++)
        out << qSetFieldWidth(sizes[i]) << data[i];
    out << Qt::reset << data.last() << Qt::endl;
}
