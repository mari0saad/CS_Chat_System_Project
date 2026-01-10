#ifndef COMMANDREGISTRY_H
#define COMMANDREGISTRY_H

#include "iservercommand.h"
#include "parsedcommand.h"
#include <QMap>
#include <functional>
#include <memory>

using CommandFactory = std::function<std::unique_ptr<IServerCommand>()>;

class CommandRegistry {
public:
    void registerCommand(const QString& name, CommandFactory factory)
    {
        registry[name.toUpper()] = factory;
    }

    std::unique_ptr<IServerCommand> createCommand(const ParsedCommand& cmd) const
    {
        auto it = registry.find(cmd.name.toUpper());
        if (it != registry.end()) {
            return it.value()();
        }
        return nullptr;
    }

private:
    QMap<QString, CommandFactory> registry;
};


#endif // COMMANDREGISTRY_H
