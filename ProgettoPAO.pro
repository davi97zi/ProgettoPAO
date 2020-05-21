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
    Gui/statistichepersonaggio.cpp \
    Interfacce/defenceInterface.cpp \
    Interfacce/dpsInterface.cpp \
    Interfacce/healInterface.cpp \
    Interfacce/magicInterface.cpp \
    Interfacce/personaggio.cpp \
    arciere.cpp \
    artificiere.cpp \
    battaglia.cpp \
    berserker.cpp \
    Gui/changecharacter.cpp \
    Gui/choosecharacter.cpp \
    Gui/choosefirstcharacter.cpp \
    contenitore.cpp \
    guaritore.cpp \
    mago.cpp \
    main.cpp \
    Gui/mainwindow.cpp \
    paladino.cpp \
    partita.cpp \
    soldato.cpp \
    Gui/storico.cpp \
    tank.cpp \
    Gui/statistichematch.cpp \
    Gui/info_match.cpp \
    Gui/abilita_personaggio_match.cpp \
    Gui/match.cpp \
    negozio_widget.cpp \
    negozio_personaggio.cpp

HEADERS += \
    mainwindow.h \
    Gui/statistichepersonaggio.h \
    Interfacce/defenceInterface.h \
    Interfacce/dpsInterface.h \
    Interfacce/healInterface.h \
    Interfacce/magicInterface.h \
    Interfacce/personaggio.h \
    arciere.h \
    artificiere.h \
    battaglia.h \
    berserker.h \
    Gui/changecharacter.h \
    Gui/choosecharacter.h \
    Gui/choosefirstcharacter.h \
    contenitore.h \
    guaritore.h \
    mago.h \
    Gui/mainwindow.h \
    paladino.h \
    partita.h \
    soldato.h \
    Gui/storico.h \
    tank.h \
    ui_mainwindow.h \
    Gui/statistichematch.h \
    Gui/info_match.h \
    Gui/abilita_personaggio_match.h \
    Gui/match.h \
    negozio_widget.h \
    negozio_personaggio.h

FORMS += \
        Gui/mainwindow.ui \
    Gui/partita.ui \
    Gui/storico.ui \
    Gui/chooseFirstcharacter.ui \
    Gui/changecharacter.ui \
    Gui/match.ui
