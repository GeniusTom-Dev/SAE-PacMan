TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        draw.cpp \
        main.cpp \
        map.cpp \
        menu.cpp \
        movementPacman.cpp \
        movementPhantom.cpp \
        musicGest.cpp \
        yaml.cpp

include(MinGL2/mingl.pri)

HEADERS += \
    draw.h \
    map.h \
    menu.h \
    movementPacman.h \
    movementPhantom.h \
    musicGest.h \
    type.h \
    yaml.h
