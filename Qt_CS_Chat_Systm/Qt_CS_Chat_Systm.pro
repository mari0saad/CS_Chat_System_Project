# Qt_CS_Chat_Systm.pro

TEMPLATE = app
TARGET = Qt_CS_Chat_Systm

# Include common settings
include(common.pri)

# Sources
SOURCES += \
    Client/client.cpp \
    Server/Commands/authcommand.cpp \
    Server/Core/commanddispatcher.cpp \
    Server/Services/authservice.cpp \
    Server/clientsession.cpp \
    Server/server.cpp \
    main.cpp

# Headers
HEADERS += \
    Client/client.h \
    Server/Commands/authcommand.h \
    Server/Core/clientcontext.h \
    Server/Core/commanddispatcher.h \
    Server/Core/iservercommand.h \
    Server/Services/authservice.h \
    Server/clientsession.h \
    Server/server.h
