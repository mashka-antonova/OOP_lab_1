QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        application.cpp \
        circle.cpp \
        console_io.cpp \
        main.cpp \
        rectangle.cpp \
        shapes.cpp \
        shapes_manager.cpp \
        triangle.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    application.h \
    circle.h \
    console_io.h \
    constants.h \
    rectangle.h \
    shapes.h \
    shapes_manager.h \
    triangle.h
