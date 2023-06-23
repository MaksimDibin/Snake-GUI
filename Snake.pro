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
    leaderboard.cpp \
        main.cpp \
        mainwindow.cpp \
        musicplayer.cpp \
    score.cpp \
        settingwindow.cpp \
        styledwidget.cpp \

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    gameover.h \
    gamewindow.h \
    leaderboard.h \
    mainwindow.h \
    musicplayer.h \
    score.h \
    settingwindow.h \
    styledwidget.h \

RESOURCES += \
    resources.qrc

FORMS += \
    leaderboard.ui \
    mainwindow.ui \
    score.ui \
    settingwindow.ui

