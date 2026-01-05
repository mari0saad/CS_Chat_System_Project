#include "deletecommand.h"


DeleteCommand::DeleteCommand(const QString& rawLine)
{
    filename = rawLine.mid(QString("DELETE ").length()).trimmed();
}

QString DeleteCommand::execute(ClientContext&)
{
    QString error;
    if (!fileService.deleteFile(filename, error)) {
        return "ERROR 404 " + error + "\n";
    }
    return "OK file deleted\n";
}
