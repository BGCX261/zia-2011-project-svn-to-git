#-------------------------------------------------
#
# Project created by QtCreator 2011-03-30T23:07:49
#
#-------------------------------------------------

QT       += core gui xml

TARGET = ZiaServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += E:/boost/boost_1_44_0/

SOURCES += main.cpp \
    commandpanelcli.cpp \
    StaticFunctions.cpp \
    abstractsocketclassWindows.cpp \
    abstractsocketclasslinux.cpp \
    Gui/gui.cpp \
    Gui/moduleswindow.cpp \
    Gui/qwindow.cpp \
    HandlingConnection.cpp \
    xml/Lecture.cpp \
    xml/module.cpp \
    xml/SaveXML.cpp \
    xml/zia.cpp \
    zfile.cpp \
    reponse.cpp

HEADERS += \
    ICommandPanel.h \
    commandpanelcli.h \
    StaticFunctions.h \
    abstractsocketclasslinux.h \
    abstractsocketclasswindows.h \
    Gui/gui.h \
    Gui/moduleswindow.h \
    Gui/qwindowapi.h \
    AbstractSocketClass.h \
    HandlingConnection.h \
    xml/Lecture.h \
    xml/module.h \
    xml/zia.h \
    xml/SaveXML.h \
    zfile.h \
    reponse.h

CONFIG(release):QMAKE_CXXFLAGS += -g3

LIBS += -lws2_32 -lpthread "E:\boost\boost_1_44_0\stage\lib\libboost_regex-mgw44-mt-s-1_44.a"
