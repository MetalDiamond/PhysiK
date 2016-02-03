TARGET = PhysiK
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

QT -= core gui

SOURCES += main.cpp \
    src/triangle.cpp \
    src/physicobject.cpp \
    src/vec3.cpp \
    src/body.cpp \
    src/particlegroup.cpp \
    src/constraint.cpp \
    src/particlesystem.cpp \
    src/trianglehashtable.cpp \
    src/solver.cpp \
    src/intersection.cpp

HEADERS += \
    src/triangle.h \
    src/physicobject.h \
    src/vec3.h \
    src/body.h \
    src/particlegroup.h \
    src/constraint.h \
    src/particlesystem.h \
    src/trianglehashtable.h \
    src/solver.h \
    src/intersection.h