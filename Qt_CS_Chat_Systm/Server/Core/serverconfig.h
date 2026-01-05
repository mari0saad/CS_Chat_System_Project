#ifndef SERVERCONFIG_H
#define SERVERCONFIG_H

#include <QString>
#include <QDir>

namespace ServerConfig {
    const QString ROOT_DIR = "server_data";
    // Ensure sandbox exists at startup
    inline void ensureSandboxExists()
    {
        QDir dir(ROOT_DIR);
        if (!dir.exists()) {
            if (!dir.mkpath(".")) {
                qFatal("Cannot create server sandbox directory: %s",
                       qUtf8Printable(dir.absolutePath()));
            }
        }
    }
}

#endif // SERVERCONFIG_H
