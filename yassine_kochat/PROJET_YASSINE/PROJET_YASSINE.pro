#-------------------------------------------------
#
# Project created by QtCreator 2019-10-24T19:02:04
#
#-------------------------------------------------

QT             +=core gui sql network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PROJET_YASSINE
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ajout.cpp \
    ajout_g.cpp \
    affichage.cpp \
    client.cpp \
    connexion.cpp \
    supprimer_client.cpp \
    groupe.cpp \
    supprimer_g.cpp \
    afficher_g.cpp \
    update_client.cpp \
    update_groupe.cpp \
    stati.cpp \
    mailing/emailaddress.cpp \
    mailing/mimeattachment.cpp \
    mailing/mimecontentformatter.cpp \
    mailing/mimefile.cpp \
    mailing/mimehtml.cpp \
    mailing/mimeinlinefile.cpp \
    mailing/mimemessage.cpp \
    mailing/mimemultipart.cpp \
    mailing/mimepart.cpp \
    mailing/mimetext.cpp \
    mailing/quotedprintable.cpp \
    mailing/smtpclient.cpp

HEADERS += \
        mainwindow.h \
    ajout.h \
    ajout_g.h \
    affichage.h \
    client.h \
    connexion.h \
    supprimer_client.h \
    groupe.h \
    supprimer_g.h \
    afficher_g.h \
    update_client.h \
    update_groupe.h \
    stati.h \
    mailing/emailaddress.h \
    mailing/mimeattachment.h \
    mailing/mimecontentformatter.h \
    mailing/mimefile.h \
    mailing/mimehtml.h \
    mailing/mimeinlinefile.h \
    mailing/mimemessage.h \
    mailing/mimemultipart.h \
    mailing/mimepart.h \
    mailing/mimetext.h \
    mailing/quotedprintable.h \
    mailing/smtpclient.h \
    mailing/smtpexports.h \
    mailing/SmtpMime



FORMS += \
        mainwindow.ui \
    ajout.ui \
    ajout_g.ui \
    affichage.ui \
    supprimer_client.ui \
    supprimer_g.ui \
    afficher_g.ui \
    update_client.ui \
    update_groupe.ui \
    stati.ui
    RC_ICONS=icon.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    yassine.qrc


INCLUDEPATH += $$PWD/../../Downloads/OpenSSL/include
DEPENDPATH += $$PWD/../../Downloads/OpenSSL/include
