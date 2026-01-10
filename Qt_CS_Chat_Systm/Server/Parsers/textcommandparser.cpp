#include "textcommandparser.h"

ParsedCommand TextCommandParser::parse(const QString &input)
{
    ParsedCommand cmd;

    QString trimmed = input.trimmed();
    if (trimmed.isEmpty())
        return cmd;

    // Command name = first word
    int spaceIndex = trimmed.indexOf(' ');
    if (spaceIndex == -1) {
        cmd.name = trimmed.toUpper();
        return cmd;
    }

    cmd.name = trimmed.left(spaceIndex).toUpper();

    QString rest = trimmed.mid(spaceIndex + 1);

    // Split first semicolon (for WRITE/APPEND)
    int semicolonIndex = rest.indexOf(';');
    if (semicolonIndex != -1) {
        QString argsPart = rest.left(semicolonIndex);
        cmd.data = rest.mid(semicolonIndex + 1);
        cmd.args = argsPart.split(',', Qt::SkipEmptyParts);
    } else {
        cmd.args = rest.split(',', Qt::SkipEmptyParts);
    }

    return cmd;
}
