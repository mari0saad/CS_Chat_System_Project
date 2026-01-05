#include "infocommand.h"

InfoCommand::InfoCommand(const QString& rawLine)
{
    filename = rawLine.mid(QString("INFO ").length()).trimmed();
}

QString InfoCommand::execute(ClientContext&)
{
    qint64 size;
    QDateTime modified;
    QString error;
    if (!fileService.fileInfo(filename, size, modified, error)) {
        return "ERROR 404 " + error + "\n";
    }
    return QString("OK size=%1 modified=%2\n").arg(size).arg(modified.toString(Qt::ISODate));
}
