#ifndef MONITOREDFILE_H
#define MONITOREDFILE_H

#include <QFileInfo>
#include <QString>

class MonitoredFile: public QFileInfo
{
    Q_OBJECT
private:
    bool oldExists {false};
    qint64 oldSize {0};
public:
    MonitoredFile(const QString &path);
    bool check();
};

#endif // MONITOREDFILE_H
