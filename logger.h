#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>

class Logger: public QObject
{
    Q_OBJECT
private:
    QFile *file;
public:
    Logger(QObject *parent = nullptr);
};

#endif // LOGGER_H
