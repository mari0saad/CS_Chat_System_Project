#include "commanddispatcher.h"
#include "commanddispatcher.h"
#include "iservercommand.h"
#include "authcommand.h"
#include "clientcontext.h"
#include "createcommand.h"



QString CommandDispatcher::dispatch(const QString &line, ClientContext &context)
{
//    auto command = createCommand(line);
//    if (!command) {
//            return "ERROR 400 'Unkown Command'\n";
//        }
//    return command->execute(context);
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
    return nullptr;
}
