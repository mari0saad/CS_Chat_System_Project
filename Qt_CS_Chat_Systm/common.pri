# common.pri

# Qt modules
QT += core network
QT -= gui

# C++ standard
CONFIG += c++17 console
CONFIG -= app_bundle

# Include paths
INCLUDEPATH += \
    $$PWD/Client \
    $$PWD/Server \
    $$PWD/Server/Core \
    $$PWD/Server/Commands \
    $$PWD/Server/Services \
    $$PWD/Server/Parsers

