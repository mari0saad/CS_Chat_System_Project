#ifndef CLIENTCONTEXT_H
#define CLIENTCONTEXT_H

#include <QString>

struct ClientContext
{
    bool authenticated = false;
    QString username;
};

#endif // CLIENTCONTEXT_H
