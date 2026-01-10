#ifndef CLIENTCONTEXT_H
#define CLIENTCONTEXT_H

#include <QString>
#include "fileservice.h"
#include "authservice.h"

struct ClientContext {
    bool isAuthenticated = false;
    QString username;
    FileService* fileService;
    AuthService* authService;
};
#endif // CLIENTCONTEXT_H
