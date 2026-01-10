#ifndef TEXTCOMMANDPARSER_H
#define TEXTCOMMANDPARSER_H

#include "icommandparser.h"

class TextCommandParser : public ICommandParser {
public:
    ParsedCommand parse(const QString& input) override;
};

#endif // TEXTCOMMANDPARSER_H
