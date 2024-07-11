QT       += core gui multimedia network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    create.cpp \
    database.cpp \
    label_scroll.cpp \
    login.cpp \
    lyrics.cpp \
    main.cpp \
    soaring_list.cpp \
    sparkdemo.cpp \
    widget.cpp

HEADERS += \
    create.h \
    database.h \
    label_scroll.h \
    login.h \
    lyrics.h \
    soaring_list.h \
    sparkdemo.h \
    widget.h

FORMS += \
    create.ui \
    login.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES += \
    ../xiangmu/Spack-project-CPP/sparkAPI-1.py