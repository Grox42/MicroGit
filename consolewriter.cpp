#include "consolewriter.h"
#include <QTextStream>

ConsoleWriter::ConsoleWriter(QObject *parent): QObject{parent}
{
    outHundle = GetStdHandle(STD_OUTPUT_HANDLE);

    QTextStream out(stdout);
    out.setFieldWidth(10);
    out << Qt::left;
    for (qint32 i {0}; i < title.length() - 1; i++)
        out << title[i];
    out << qSetFieldWidth(40) << title[title.length() - 1] << Qt::endl;

    pos.X = 0;
    pos.Y = 1;
    SetConsoleCursorPosition(outHundle, pos);
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
        return QString().setNum(newSize, 'g', 1) + prefix[index] + 'b';
    else
        return QString().setNum(newSize, 'g', 1) + 'b';
}

void ConsoleWriter::write(qint32 index, const MonitoredFile &monitoredFile)
{
    pos.X = 0;
    pos.Y = index + 1;

    QTextStream out(stdout);
    out.setFieldWidth(10);
    out << Qt::left;
    out << pos.Y << monitoredFile.fileName() << (monitoredFile.exists() ? "exists" : "not exist");
    QString size{sizeToString(monitoredFile.size())};
    out << size;
    out.setFieldWidth(40);
    out << monitoredFile.absolutePath();
}
