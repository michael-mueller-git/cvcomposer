#-------------------------------------------------
#
# Project created by QtCreator 2015-12-29T23:02:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cvcomposer
TEMPLATE = app
QMAKE_CXXFLAGS = -std=c++11

win32 {
    INCLUDEPATH += "C:\Program Files\opencv2.4.6\build\include"
    LIBS += -L"C:\Program Files\opencv2.4.6\build-mingw\lib"
    LIBS += -lopencv_core249 -lopencv_imgproc249 -lopencv_highgui249
}
else {
    INCLUDEPATH += /usr/include/opencv2/
    LIBS += -lopencv_core -lopencv_imgproc -lopencv_highgui
}


SOURCES += main.cpp\
        mainwidget.cpp \
    composerwidget.cpp \
    nodestypesmanager.cpp \
    composerscene.cpp \
    nodesviews/plugitem.cpp \
    nodesviews/connectionitem.cpp \
    composermodel.cpp \
    composerexecutor.cpp \
    composerscheduler.cpp \
    interactivegraphicsview.cpp \
    nodesviews/genericnodeitem.cpp \
    nodeslistwidget.cpp \
    connection.cpp \
    cvutils.cpp \
    nodesviews/imageviewerdockwidget.cpp \
    genericnode.cpp \
    processors/abstractprocessor.cpp \
    processors/blurprocessor.cpp \
    processors/imagefromfileprocessor.cpp \
    nodesviews/imagefromfilewidget.cpp \
    nodesviews/abstractnodewidget.cpp \
    nodesviews/imagepreviewerwidget.cpp \
    processors/imagepreviewerprocessor.cpp \
    nodesviews/dockableimageviewerwidget.cpp \
    processors/dockableimageviewerprocessor.cpp \
    processors/gaussianblurprocessor.cpp \
    nodesviews/medianblurwidget.cpp \
    processors/medianblurprocessor.cpp \
    nodesviews/bilateralfilterwidget.cpp \
    processors/bilateralfilterprocessor.cpp \
    nodesviews/genericnodewidget.cpp \
    plugtype.cpp \
    plug.cpp \
    plugwidgets/imagepathwidget.cpp \
    plugwidgets/abstractplugwidget.cpp \
    plugwidgets/imagepreviewwidget.cpp \
    plugwidgets/sizewidget.cpp \
    plugwidgets/pointwidget.cpp \
    plugwidgets/enumerationwidget.cpp \
    plugwidgets/doublewidget.cpp

HEADERS  += mainwidget.h \
    composerwidget.h \
    nodestypesmanager.h \
    composerscene.h \
    nodesviews/plugitem.h \
    nodesviews/connectionitem.h \
    composermodel.h \
    nodesviews/customitems.h \
    composerexecutor.h \
    composerscheduler.h \
    connection.h \
    interactivegraphicsview.h \
    nodesviews/genericnodeitem.h \
    nodeslistwidget.h \
    plug.h \
    cvutils.h \
    nodesviews/imageviewerdockwidget.h \
    genericnode.h \
    processors/abstractprocessor.h \
    processors/blurprocessor.h \
    processors/imagefromfileprocessor.h \
    nodesviews/imagefromfilewidget.h \
    nodesviews/abstractnodewidget.h \
    properties.h \
    nodesviews/imagepreviewerwidget.h \
    processors/imagepreviewerprocessor.h \
    nodesviews/dockableimageviewerwidget.h \
    processors/dockableimageviewerprocessor.h \
    processors/gaussianblurprocessor.h \
    nodesviews/medianblurwidget.h \
    processors/medianblurprocessor.h \
    nodesviews/bilateralfilterwidget.h \
    processors/bilateralfilterprocessor.h \
    plugdefinition.h \
    plugtype.h \
    nodesviews/genericnodewidget.h \
    plugwidgets/imagepathwidget.h \
    plugwidgets/abstractplugwidget.h \
    plugwidgets/imagepreviewwidget.h \
    plugwidgets/sizewidget.h \
    plugwidgets/pointwidget.h \
    plugwidgets/enumerationwidget.h \
    plugwidgets/doublewidget.h

FORMS    += \
    mainwidget.ui \
    nodesviews/imagedockwidget.ui \
    nodesviews/imagefromfilewidget.ui \
    nodesviews/dockableimageviewerwidget.ui \
    nodesviews/medianblurwidget.ui \
    nodesviews/bilateralfilterwidget.ui
