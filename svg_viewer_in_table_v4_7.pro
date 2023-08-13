QT       += core gui xml svg   svgwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp\
    newfileclass.cpp\
    svgreader.cpp

HEADERS += \
    mainwindow.h\
    newfileclass.h\
    svgreader.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    svg_viewer_in_table_v3_uk_UA.ts
CONFIG += lrelease
CONFIG += embed_translations

macx {
ICON = icon.icns
}

unix:!macx{
# linux only in :/other files
}

win32 {
RC_ICONS = icon.ico
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icon.icns \
    icon.ico

RESOURCES += \
    res.qrc
