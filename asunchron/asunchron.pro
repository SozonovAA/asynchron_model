#-------------------------------------------------
#
# Project created by QtCreator 2020-09-16T18:19:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = asunchron
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcpdocumentobject.cpp \
    qcustomplot.cpp \
    asynchron_mashine.cpp

HEADERS  += mainwindow.h \
    qcpdocumentobject.h \
    qcustomplot.h \
    asynchron_mashine.h \
    math_convert.h

FORMS    += mainwindow.ui
