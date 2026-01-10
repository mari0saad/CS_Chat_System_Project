#include "appendcommand.h"

#define REQUIRE_AUTH(ctx) \
    if (!(ctx)->isAuthenticated) return "ERROR 401 Unauthorized";


QString AppendCommand::execute(ClientContext *context, const ParsedCommand &cmd)
{
    REQUIRE_AUTH(context);

    if (cmd.args.size() != 1)
        return "ERROR 400 Missing filename";

    return context->fileService->appendFileCmd(cmd.args[0], cmd.data);
}
