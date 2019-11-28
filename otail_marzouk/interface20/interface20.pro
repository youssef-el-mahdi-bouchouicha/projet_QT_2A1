QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    afficher.cpp \
    afficher_v.cpp \
    bus.cpp \
    chercher_bus.cpp \
    connexion.cpp \
    g_bus.cpp \
    main.cpp \
    mainwindow.cpp \
    modifier_bus.cpp \
    modifier_v.cpp \
    stati.cpp \
    suppr.cpp \
    supprimer_v.cpp \
    voitures_p.cpp \
    vp.cpp

HEADERS += \
    afficher.h \
    afficher_v.h \
    bus.h \
    chercher_bus.h \
    connexion.h \
    g_bus.h \
    mainwindow.h \
    modifier_bus.h \
    modifier_v.h \
    stati.h \
    suppr.h \
    supprimer_v.h \
    voitures_p.h \
    vp.h

FORMS += \
    afficher.ui \
    afficher_v.ui \
    bus.ui \
    chercher_bus.ui \
    mainwindow.ui \
    modifier_bus.ui \
    modifier_v.ui \
    stati.ui \
    suppr.ui \
    supprimer_v.ui \
    vp.ui
RC_ICONS=icon.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rc_icon.qrc
