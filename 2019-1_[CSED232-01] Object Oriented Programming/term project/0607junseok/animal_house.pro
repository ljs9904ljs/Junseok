#-------------------------------------------------
#
# Project created by QtCreator 2019-05-14T14:30:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = animal_house
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

CONFIG += c++11

SOURCES += \
        fame_hall.cpp \
        game_window.cpp \
    inventory.cpp \
        main.cpp \
        mainwindow.cpp \
    market.cpp \
    minigamebase.cpp \
    rock_scissors_paper.cpp \
    roulette.cpp \
    speedquiz.cpp \
    src/model/ability_point.cpp \
        src/model/item.cpp \
    src/model/pet.cpp \
    src/model/player.cpp \

HEADERS += \
        fame_hall.h \
        game_window.h \
        include/model/ability_point.h \
        include/model/item.h \
        include/model/pet.h \
        include/model/player.h \
        inventory.h \
        mainwindow.h \
        market.h \
    minigamebase.h \
    rock_scissors_paper.h \
    roulette.h \
    speedquiz.h \

FORMS += \
        fame_hall.ui \
        game_window.ui \
        inventory.ui \
        mainwindow.ui \
        market.ui \
    minigamebase.ui \
    rock_scissors_paper.ui \
    roulette.ui \
    speedquiz.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    item_image.qrc \
