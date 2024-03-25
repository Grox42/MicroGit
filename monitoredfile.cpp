#include "monitoredfile.h"

MonitoredFile::MonitoredFile(const QString &path): QFileInfo(path) {}

bool MonitoredFile::update()
{
    bool isModified {false};

    refresh();

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
