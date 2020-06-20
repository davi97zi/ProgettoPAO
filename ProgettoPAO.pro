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
    interfacce/personaggio.cpp \
    personaggi/arciere.cpp \
    personaggi/artificiere.cpp \
    personaggi/berserker.cpp \
    personaggi/guaritore.cpp \
    personaggi/mago.cpp \
    personaggi/mostro.cpp \
    personaggi/paladino.cpp \
    personaggi/soldato.cpp \
    personaggi/tank.cpp \
    partita.cpp \
    contenitore.cpp \
    gui/abilita_personaggio_match.cpp \
    gui/info_match.cpp \
    gui/match.cpp \
    gui/negozio_personaggio.cpp \
    gui/negozio_widget.cpp \
    gui/storico.cpp \
    controller/controller.cpp \
    xml/dungeon.cpp \
    xml/taverna.cpp \
    gui/change_character.cpp \
    gui/info_partita_storico.cpp \
    gui/info_personaggio_storico.cpp \
    gui/main_window.cpp \
    gui/scegli_applicativo.cpp \
    gui/statistiche_match_mostro.cpp \
    gui/statistiche_match_personaggio.cpp \
    interfacce/defence_interface.cpp \
    interfacce/dps_interface.cpp \
    interfacce/heal_interface.cpp \
    interfacce/magic_interface.cpp \
    xml/dungeon_item.cpp \
    xml/storico_modello.cpp \
    xml/xml_item.cpp

HEADERS += \
    interfacce/personaggio.h \
    personaggi/arciere.h \
    personaggi/artificiere.h \
    personaggi/berserker.h \
    personaggi/guaritore.h \
    personaggi/mago.h \
    personaggi/mostro.h \
    personaggi/paladino.h \
    personaggi/soldato.h \
    personaggi/tank.h \
    partita.h \
    contenitore.h \
    gui/abilita_personaggio_match.h \
    gui/info_match.h \
    gui/match.h \
    gui/negozio_personaggio.h \
    gui/negozio_widget.h \
    gui/storico.h \
    controller/controller.h \
    xml/taverna.h \
    xml/dungeon.h \
    gui/change_character.h \
    gui/info_partita_storico.h \
    gui/info_personaggio_storico.h \
    gui/main_window.h \
    gui/scegli_applicativo.h \
    gui/statistiche_match_mostro.h \
    gui/statistiche_match_personaggio.h \
    interfacce/defence_interface.h \
    interfacce/dps_interface.h \
    interfacce/heal_interface.h \
    interfacce/magic_interface.h \
    xml/dungeon_item.h \
    xml/storico_modello.h \
    xml/xml_item.h

RESOURCES +=


