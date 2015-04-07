#-------------------------------------------------
#
# Project created by QtCreator 2013-03-06T11:06:53
#
#-------------------------------------------------

QT       += core gui

TARGET = calculator2
TEMPLATE = app


SOURCES += main.cpp\
        calculator.cpp \
    biguint.cpp \
    dialog.cpp

HEADERS  += calculator.h \
    biguint.h \
    dialog.h

FORMS    += calculator.ui \
    dialog.ui

RESOURCES += \
    resource.qrc
