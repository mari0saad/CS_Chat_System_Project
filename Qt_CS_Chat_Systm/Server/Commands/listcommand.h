#ifndef LISTCOMMAND_H
#define LISTCOMMAND_H

#include "iservercommand.h"
#include "fileservice.h"

class ListCommand : public IServerCommand
{
public:
    QString execute(ClientContext&) override;

private:
    FileService fileService;
};

#endif // LISTCOMMAND_H
