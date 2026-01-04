#include "createcommand.h"



CreateCommand::CreateCommand(const QString &rawLine)
{
    filename = rawLine.mid(QString("CREATE ").length()).trimmed();
}

QString CreateCommand::execute(ClientContext &context)
{
    QString errorMessage;
    if (!fileService.createFile(filename, errorMessage)) {
        return "ERROR 500 " + errorMessage + "\n";
    }
    return "OK file created successfully\n";
}
