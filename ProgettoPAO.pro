#-------------------------------------------------
#
# Project created by QtCreator 2020-04-27T11:02:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProgettoPAO
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    Interfacce/defenceInterface.cpp \
    Interfacce/dpsInterface.cpp \
    Interfacce/healInterface.cpp \
    Interfacce/magicInterface.cpp \
    Interfacce/personaggio.cpp \
    arciere.cpp \
    artificiere.cpp \
    berserker.cpp \
    guaritore.cpp \
    mago.cpp \
    mostro.cpp \
    paladino.cpp \
    soldato.cpp \
    tank.cpp

HEADERS += \
    mainwindow.h \
    Interfacce/defenceInterface.h \
    Interfacce/dpsInterface.h \
    Interfacce/healInterface.h \
    Interfacce/magicInterface.h \
    Interfacce/personaggio.h \
    arciere.h \
    artificiere.h \
    berserker.h \
    guaritore.h \
    mago.h \
    mostro.h \
    paladino.h \
    soldato.h \
    tank.h

FORMS += \
        mainwindow.ui
