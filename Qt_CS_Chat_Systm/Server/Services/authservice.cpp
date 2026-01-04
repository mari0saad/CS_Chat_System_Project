#include "authservice.h"


AuthService::AuthService()
{

}

AuthService::Result AuthService::authenticate(const QString &username, const QString &password) const
{
    if (username != "admin") {
           return Result::InvalidUsername;
       }

       if (password != "123") {
           return Result::InvalidPassword;
       }

       return Result::Success;
}
