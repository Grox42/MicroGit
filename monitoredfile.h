#ifndef MONITOREDFILE_H
#define MONITOREDFILE_H

#include <QFileInfo>
#include <QString>

class MonitoredFile: public QFileInfo
{
private:
    bool oldExists {false};
    qint64 oldSize {-1};
public:
    MonitoredFile(const QString &path);
    bool check();
};

#endif // MONITOREDFILE_H
