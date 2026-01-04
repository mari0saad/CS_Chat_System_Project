#ifndef COMMANDDISPATCHER_H
#define COMMANDDISPATCHER_H

#include <QString>
#include <memory>

struct ClientContext;
class IServerCommand;

class CommandDispatcher
{
public:
    QString dispatch(const QString& line, ClientContext& context);

private:
    std::unique_ptr<IServerCommand> createCommand(const QString& line);
};

#endif // COMMANDDISPATCHER_H
