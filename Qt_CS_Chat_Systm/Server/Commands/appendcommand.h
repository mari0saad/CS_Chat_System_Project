#ifndef APPENDCOMMAND_H
#define APPENDCOMMAND_H

#include "fileservice.h"
#include "iservercommand.h"

class AppendCommand : public IServerCommand
{
public:
    explicit AppendCommand(const QString& rawLine);
    QString execute(ClientContext& context) override;

private:
    QString filename;
    QString data;
    FileService fileService;
};

#endif // APPENDCOMMAND_H
