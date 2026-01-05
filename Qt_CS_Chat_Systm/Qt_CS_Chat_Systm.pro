# Qt_CS_Chat_Systm.pro

TEMPLATE = app
TARGET = Qt_CS_Chat_Systm

# Include common settings
include(common.pri)

# Sources
SOURCES += \
    Client/client.cpp \
    Server/Commands/appendcommand.cpp \
    Server/Commands/authcommand.cpp \
    Server/Commands/createcommand.cpp \
    Server/Commands/deletecommand.cpp \
    Server/Commands/infocommand.cpp \
    Server/Commands/listcommand.cpp \
    Server/Commands/readcommand.cpp \
    Server/Commands/renamecommand.cpp \
    Server/Commands/writecommand.cpp \
    Server/Core/commanddispatcher.cpp \
    Server/Services/authservice.cpp \
    Server/Services/fileservice.cpp \
    Server/clientsession.cpp \
    Server/server.cpp \
    main.cpp

# Headers
HEADERS += \
    Client/client.h \
    Server/Commands/appendcommand.h \
    Server/Commands/authcommand.h \
    Server/Commands/createcommand.h \
    Server/Commands/deletecommand.h \
    Server/Commands/infocommand.h \
    Server/Commands/listcommand.h \
    Server/Commands/readcommand.h \
    Server/Commands/renamecommand.h \
    Server/Commands/writecommand.h \
    Server/Core/clientcontext.h \
    Server/Core/commanddispatcher.h \
    Server/Core/iservercommand.h \
    Server/Core/serverconfig.h \
    Server/Services/authservice.h \
    Server/Services/fileservice.h \
    Server/clientsession.h \
    Server/server.h
