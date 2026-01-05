#include "readcommand.h"


ReadCommand::ReadCommand(const QString &rawLine)
{
    filename = rawLine.mid(QString("READ ").length()).trimmed();
}

QString ReadCommand::execute(ClientContext &context)
{
    QString fileContent;
    QString errorMessage;
    if (!fileService.readFile(filename, fileContent, errorMessage)) {
        return "ERROR 404 " + errorMessage + "\n";
    }
    QByteArray data = fileContent.toUtf8();
    QString response;
    response += "OK " + QString::number(data.size()) + "\n";
    response += fileContent + "\n";
    return response;
}
