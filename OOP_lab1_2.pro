QT = core

CONFIG += c++20 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        application.cpp \
        circle.cpp \
        console_io.cpp \
        geometry_utils.cpp \
        main.cpp \
        rectangle.cpp \
        shape.cpp \
        shape_creator.cpp \
        shape_manager.cpp \
        triangle.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    application.h \
    circle.h \
    console_io.h \
    geometry_utils.h \
    menu_action.h \
    rectangle.h \
    shape.h \
    shape_creator.h \
    shape_manager.h \
    shape_type.h \
    triangle.h
