# common.pri

# Qt modules
QT += core network
QT -= gui

# C++ standard
CONFIG += c++17 console
CONFIG -= app_bundle

# Include warnings for deprecated Qt features
DEFINES += QT_DEPRECATED_WARNINGS

# Include paths
INCLUDEPATH += $$PWD/Client
INCLUDEPATH += $$PWD/Server

# Optional: directories for build outputs (if you want)
# DESTDIR = $$PWD/bin
# OBJECTS_DIR = $$PWD/build/obj
# MOC_DIR = $$PWD/build/moc
