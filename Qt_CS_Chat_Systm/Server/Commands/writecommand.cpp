#include "writecommand.h"
#include "clientcontext.h"

WriteCommand::WriteCommand(const QString &rawLine)
{
    int delimeter = rawLine.indexOf(';');
    if(delimeter != -1)
    {
        filename = rawLine.mid(QString("WRITE ").length(), delimeter - QString("WRITE ").length()).trimmed();
        data = rawLine.mid(delimeter +1 );
    }
}

QString WriteCommand::execute(ClientContext &context)
{
    QString errorMessage;
    if (!fileService.writeFile(filename, data, errorMessage)) {
        return "ERROR 500 " + errorMessage + "\n";
    }
    return "OK data written successfully\n";
}


