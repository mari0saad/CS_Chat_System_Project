#include "commanddispatcher.h"
#include "commanddispatcher.h"
#include "iservercommand.h"
#include "authcommand.h"
#include "clientcontext.h"
#include "createcommand.h"
#include "writecommand.h"
#include "appendcommand.h"
#include "readcommand.h"
#include "renamecommand.h"
#include "listcommand.h"
#include "deletecommand.h"
#include "infocommand.h"


QString CommandDispatcher::dispatch(const QString &line, ClientContext &context)
{
    const bool isAuthCommand = line.startsWith("AUTH ");

    if (!context.authenticated && !isAuthCommand) {
        return "ERROR 401 Unauthorized\n";
    }

    auto command = createCommand(line);

    if (!command) {
        return "ERROR 400 Unknown command\n";
    }

    return command->execute(context);

}

std::unique_ptr<IServerCommand> CommandDispatcher::createCommand(const QString &line)
{
    if (line.startsWith("AUTH ")) {
        return std::make_unique<AuthCommand>(line);
    }

    if (line.startsWith("CREATE ")) {
        return std::make_unique<CreateCommand>(line);
    }

    if (line.startsWith("WRITE ")) {
        return std::make_unique<WriteCommand>(line);
    }
    if (line.startsWith("APPEND ")) {
        return std::make_unique<AppendCommand>(line);
    }
    if (line.startsWith("READ ")) {
        return std::make_unique<ReadCommand>(line);
    }
    if (line.startsWith("LIST"))
        return std::make_unique<ListCommand>();

    if (line.startsWith("DELETE "))
        return std::make_unique<DeleteCommand>(line);

    if (line.startsWith("RENAME "))
        return std::make_unique<RenameCommand>(line);

    if (line.startsWith("INFO "))
        return std::make_unique<InfoCommand>(line);

    return nullptr;
}
