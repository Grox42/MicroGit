#include "monitoredfile.h"

MonitoredFile::MonitoredFile(const QString &path): QFileInfo(path)
{
    oldExists = exists();
    oldSize = size();
}

bool MonitoredFile::check()
{
    bool isModified {false};

    if (oldExists != exists()) {
        oldExists = !oldExists;
        isModified = true;
    }

    qint64 newSize {size()};
    if (oldSize != newSize) {
        oldSize = newSize;
        isModified = true;
    }

    return isModified;
}