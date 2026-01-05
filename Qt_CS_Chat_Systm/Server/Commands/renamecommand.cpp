#include "renamecommand.h"

RenameCommand::RenameCommand(const QString& rawLine)
{
    int delimeter = rawLine.indexOf(';');
    if (delimeter != -1) {
        oldName = rawLine.mid(QString("RENAME ").length(), delimeter - QString("RENAME ").length()).trimmed();
        newName = rawLine.mid(delimeter + 1).trimmed();
    }
}

QString RenameCommand::execute(ClientContext&)
{
    QString error;
    if (!fileService.renameFile(oldName, newName, error)) {
        return "ERROR 500 " + error + "\n";
    }
    return "OK file renamed\n";
}
