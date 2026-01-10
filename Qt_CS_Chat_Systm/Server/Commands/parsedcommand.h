#ifndef PARSEDCOMMAND_H
#define PARSEDCOMMAND_H

#include <QString>
#include <QStringList>

struct ParsedCommand {
    QString name;       // Command name
    QStringList args;   // Arguments with delimeter as semicolon
    QString data;       // Extra data for WRITE/APPEND
};

#endif // PARSEDCOMMAND_H
