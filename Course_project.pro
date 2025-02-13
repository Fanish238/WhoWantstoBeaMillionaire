QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

VERSION = 0.0.1.0
QMAKE_TARGET_PRODUCT = Who Wants to Be a Millionaire?
QMAKE_TARGET_COPYRIGHT = Mihail Konovalchik

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    help_friends_and_hall.cpp \
    main.cpp \
    main_menu.cpp \
    winnings.cpp

HEADERS += \
    game.h \
    help_friends_and_hall.h \
    main_menu.h \
    winnings.h

FORMS += \
    game.ui \
    help_friends_and_hall.ui \
    main_menu.ui \
    winnings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
