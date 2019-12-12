QT       += core gui sql network multimedia


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
    affiche.cpp \
    affiche1.cpp \
    ajoutercontacts.cpp \
    ajoutercontacts1.cpp \
    connexion.cpp \
    contact_autres.cpp \
    contact_hebergement_transport.cpp \
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
    mailing/smtpclient.cpp \
    main.cpp \
    gerercontact.cpp \
    modifier.cpp \
    modifier1.cpp \
    stati.cpp \
    supprimer.cpp \
    supprimer1.cpp

HEADERS += \
    affiche.h \
    affiche1.h \
    ajoutercontacts.h \
    ajoutercontacts1.h \
    connexion.h \
    contact_autres.h \
    contact_hebergement_transport.h \
    gerercontact.h \
    mailing/SmtpMime \
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
    modifier.h \
    modifier1.h \
    stati.h \
    supprimer.h \
    supprimer1.h

FORMS += \
    affiche.ui \
    affiche1.ui \
    ajoutercontacts.ui \
    ajoutercontacts1.ui \
    gerercontact.ui \
    modifier.ui \
    modifier1.ui \
    stati.ui \
    supprimer.ui \
    supprimer1.ui
RS_ICONS= icon.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rs_icone.qrc
