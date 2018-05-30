QT += core
QT -= gui

CONFIG += c++11

TARGET = medium4
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += \
         $$PWD/3rdparty \
        $$PWD/3rdparty/rapidjson/include/rapidjson

SOURCES += main.cpp
