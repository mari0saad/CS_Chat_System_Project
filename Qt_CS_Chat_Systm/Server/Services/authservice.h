#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <QString>


class AuthService
{
public:
    AuthService();
    enum class Result
     {
         Success,
         InvalidUsername,
         InvalidPassword
     };
     Result authenticate(const QString& username, const QString& password) const;
};

#endif // AUTHSERVICE_H
