# Qt_CS_Chat_Systm.pro

TEMPLATE = app
TARGET = Qt_CS_Chat_Systm

# Include common settings
include(common.pri)

# Sources
SOURCES += \
    Client/client.cpp \
    Server/clientsession.cpp \
    Server/server.cpp \
    main.cpp

# Headers
HEADERS += \
    Client/client.h \
    Server/clientsession.h \
    Server/server.h
