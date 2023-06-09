QT       += core gui
QT       += network
QT       += sql
QT       += testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    btn.cpp \
    chat.cpp \
    cl_socket.cpp \
    client.cpp \
    homie.cpp \
    main.cpp \
    mainwindow.cpp \
    pop.cpp \
    signin.cpp \
    signup.cpp \
    user.cpp

HEADERS += \
    btn.h \
    chat.h \
    cl_socket.h \
    client.h \
    homie.h \
    mainwindow.h \
    pop.h \
    signin.h \
    signup.h \
    user.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
