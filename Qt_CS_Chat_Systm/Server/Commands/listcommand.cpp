#include "listcommand.h"


QString ListCommand::execute(ClientContext &)
{
    QStringList files;
    QString errorMessage;
    if (!fileService.listFiles(files, errorMessage)) {
        return "ERROR 500 " + errorMessage + "\n";
    }
    QString response = "OK " + QString::number(files.size()) + "\n";
    for (const QString& f : files) {
        response += f + "\n";
    }
    return response;
}
