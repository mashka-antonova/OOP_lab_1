QT = core

CONFIG += c++20 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        application.cpp \
        circle.cpp \
        circle_factrory.cpp \
        console_io.cpp \
        geometry_utils.cpp \
        main.cpp \
        polygon.cpp \
        polygon_factory.cpp \
        rectangle.cpp \
        rectangle_factory.cpp \
        shape.cpp \
        shape_creator.cpp \
        shape_manager.cpp \
        triangle.cpp \
        triangle_factory.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    application.h \
    circle.h \
    circle_factrory.h \
    console_io.h \
    geometry_utils.h \
    menu_action.h \
    polygon.h \
    polygon_factory.h \
    rectangle.h \
    rectangle_factory.h \
    shape.h \
    shape_creator.h \
    shape_factory.h \
    shape_manager.h \
    shape_type.h \
    triangle.h \
    triangle_factory.h
