#include "writecommand.h"
#include "clientcontext.h"

#define REQUIRE_AUTH(ctx) \
    if (!(ctx)->isAuthenticated) return "ERROR 401 Unauthorized";


QString WriteCommand::execute(ClientContext *context, const ParsedCommand &cmd)
{
    REQUIRE_AUTH(context);
    if (cmd.args.size() != 1)
        return "ERROR 400 Missing filename";
    return context->fileService->writeFileCmd(cmd.args[0], cmd.data);
}
