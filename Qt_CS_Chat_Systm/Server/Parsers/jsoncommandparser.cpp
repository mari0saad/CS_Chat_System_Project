#include "jsoncommandparser.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QString>

ParsedCommand JsonCommandParser::parse(const QString &input)
{
    ParsedCommand cmd;

    QJsonParseError err;
    auto doc = QJsonDocument::fromJson(input.toUtf8(), &err);

    if (err.error != QJsonParseError::NoError || !doc.isObject()) {
        cmd.name = "INVALID";
        return cmd;
    }

    QJsonObject obj = doc.object();

    cmd.name = obj.value("command").toString().toUpper();

    QJsonArray argsArray = obj.value("args").toArray();
    for (auto val : argsArray) {
        cmd.args.append(val.toString());
    }

    return cmd;
}
