QT = core \
    widgets

QT += multimedia

RC_ICONS = icon.ico
CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        gameover.cpp \
        gamewindow.cpp \
        main.cpp \
        musicplayer.cpp \
        settingwindow.cpp \
        styledwidget.cpp \
        welcomewindow.cpp

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    gameover.h \
    gamewindow.h \
    musicplayer.h \
    settingwindow.h \
    styledwidget.h \
    welcomewindow.h

RESOURCES += \
    resources.qrc

