greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
LANGUAGE = C++
QT += core gui

INCLUDEPATH += include
LIBS +=

OBJECTS_DIR = temp
MOC_DIR = temp	
UI_DIR = include/gui/forms/ui

TARGET = SGI.app

HEADERS  += include/gui/forms/*.h \

SOURCES += src/gui/forms/*.cpp \
src/control/*.cpp \

FORMS    += src/gui/forms/ui/*.ui \