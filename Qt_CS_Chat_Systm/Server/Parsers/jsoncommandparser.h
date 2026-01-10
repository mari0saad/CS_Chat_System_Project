#ifndef JSONCOMMANDPARSER_H
#define JSONCOMMANDPARSER_H

#include "icommandparser.h"

class JsonCommandParser : public ICommandParser {
public:
    ParsedCommand parse(const QString& input) override;
};

#endif // JSONCOMMANDPARSER_H
