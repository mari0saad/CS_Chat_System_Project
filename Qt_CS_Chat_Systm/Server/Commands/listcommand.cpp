#include "listcommand.h"

#define REQUIRE_AUTH(ctx) \
    if (!(ctx)->isAuthenticated) return "ERROR 401 Unauthorized";


QString ListCommand::execute(ClientContext *context, const ParsedCommand &cmd)
{
    REQUIRE_AUTH(context);

    return context->fileService->listFilesCmd();
}
