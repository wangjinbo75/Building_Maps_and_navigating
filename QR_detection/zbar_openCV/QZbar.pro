#-------------------------------------------------
#
# Project created by QtCreator 2015-08-11T09:19:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET   = QZbar
TEMPLATE = app

#DEFINES *= QRDECODE
#contains(DEFINES, QRDECODE){
#    INCLUDEPATH += /usr/include/ImageMagick/
#    LIBS += -lMagick++
#    SOURCES += scanimagemagick.cpp
#    HEADERS += scanimagemagick.h

#}

#INCLUDEPATH += /usr/local/include/zbar
LIBS += -L /usr/local/lib -lzbar -lpng

SOURCES += main.cpp\
        qrcodezbar.cpp \
    scanimage.c

HEADERS  += qrcodezbar.h \
    scanimage.h

FORMS    += qzbar.ui
