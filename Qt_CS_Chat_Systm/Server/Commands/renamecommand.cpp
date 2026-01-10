#include "renamecommand.h"

#define REQUIRE_AUTH(ctx) \
    if (!(ctx)->isAuthenticated) return "ERROR 401 Unauthorized";

QString RenameCommand::execute(ClientContext *context, const ParsedCommand &cmd)
{
    REQUIRE_AUTH(context);

    if (cmd.args.size() != 2)
        return "ERROR 400 RENAME requires old;new";

    return context->fileService->renameFileCmd(cmd.args[0], cmd.args[1]);
}
