#include "commanddispatcher.h"
#include "commanddispatcher.h"
#include "iservercommand.h"
#include "authcommand.h"
#include "clientcontext.h"




QString CommandDispatcher::dispatch(const QString &line, ClientContext &context)
{
    auto command = createCommand(line);
    if (!command) {
            return "ERROR 400\n";
        }
    return command->execute(context);
}

std::unique_ptr<IServerCommand> CommandDispatcher::createCommand(const QString &line)
{
    if (line.startsWith("AUTH ")) {
            return std::make_unique<AuthCommand>(line);
        }
    return nullptr;
}
