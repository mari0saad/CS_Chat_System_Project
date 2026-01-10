#ifndef ICOMMANDPARSER_H
#define ICOMMANDPARSER_H

#include "parsedcommand.h"
#include <QString>

class ICommandParser {
public:
    virtual ~ICommandParser() = default;
    // Parse raw input into ParsedCommand
    virtual ParsedCommand parse(const QString& input) = 0;
};

#endif // ICOMMANDPARSER_H
