#include "logger.h"
#include <QTextStream>
#include <QDateTime>

Logger::Logger(QObject *parent): QObject{parent}
{
    file = new QFile(this);
    file->setFileName("../Logs.txt");
    if (file->open(QIODevice::WriteOnly))
        file->close();
}

void Logger::log(qint32 index, const MonitoredFile &monitoredFile)
{
    QVector<QString> data {
        QString().setNum(index, 16),
        monitoredFile.exists() ? "1" : "0",
        QString().setNum(monitoredFile.size(), 16),
        monitoredFile.filePath(),
        QDateTime::currentDateTime().toString("dd.mm.yy hh:mm:ss.zzz")
    };

    if (!file->open(QIODevice::Append))
        return;

    QTextStream out(file);
    for (const QString &str : data)
        out <<  str << ' ';
    out << Qt::endl;

    file->close();
}
