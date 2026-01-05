#include "appendcommand.h"



AppendCommand::AppendCommand(const QString &rawLine)
{
    int delimeter = rawLine.indexOf(';');
    if(delimeter != -1)
    {
        filename = rawLine.mid(QString("APPEND ").length(), delimeter - QString("APPEND ").length()).trimmed();
        data = rawLine.mid(delimeter +1 );
    }
}

QString AppendCommand::execute(ClientContext &context)
{
    QString errorMessage;
    if (!fileService.appendFile(filename, data, errorMessage)) {
        return "ERROR 500 " + errorMessage + "\n";
    }
    return "OK data appended successfully\n";
}
