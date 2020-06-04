#-------------------------------------------------
#
# Project created by QtCreator 2020-04-27T11:02:20
#
#-------------------------------------------------

QT       += core gui
QT       += xml

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
    tank.cpp \
    partita.cpp \
    battaglia.cpp \
    contenitore.cpp \
    Gui/abilita_personaggio_match.cpp \
    Gui/changecharacter.cpp \
    Gui/choosefirstcharacter.cpp \
    Gui/info_match.cpp \
    Gui/mainwindow.cpp \
    Gui/match.cpp \
    Gui/negozio_personaggio.cpp \
    Gui/negozio_widget.cpp \
    Gui/statistichematchmostro.cpp \
    Gui/statistichematchpersonaggio.cpp \
    Gui/storico.cpp \
    Controller/controller.cpp \
    Gui/scegliapplicativo.cpp \
    xml/storicomodello.cpp \
    Gui/infopersonaggiostorico.cpp \
    Gui/infopartitastorico.cpp \
    xml/xmlitem.cpp

HEADERS += \
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
    tank.h \
    partita.h \
    battaglia.h \
    contenitore.h \
    Gui/abilita_personaggio_match.h \
    Gui/changecharacter.h \
    Gui/choosefirstcharacter.h \
    Gui/info_match.h \
    Gui/mainwindow.h \
    Gui/match.h \
    Gui/negozio_personaggio.h \
    Gui/negozio_widget.h \
    Gui/statistichematchmostro.h \
    Gui/statistichematchpersonaggio.h \
    Gui/storico.h \
    Controller/controller.h \
    xml/storicoModello.h \
    xml/xmlitem.h \
    Gui/scegliapplicativo.h \
    Gui/infopersonaggiostorico.h \
    Gui/infopartitastorico.h

RESOURCES += \
    xmlresources.qrc


