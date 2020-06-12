QT += quick multimedia network opengl
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS WINDOWS ARCH_WINDOWS DPS_API_EXPORTS

DISTFILES +=

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SOURCES += \
        main.cpp \
    playVideo/XVideo.cpp \
    playVideo/xvideoreplay.cpp \
    recordVideo/captureScreen/screenvideo.cpp \
    render/nv12render.cpp \
    render/renderthread.cpp \
    render/texturenode.cpp \
    util/debuglog.cpp \
    qmlcplus/replaytimeline.cpp \
    thirdSrc/ffmpeg/ffmpegcodec.cpp \
    thirdSrc/ffmpeg/ffmpegconvert.cpp \
    thirdSrc/ffmpeg/ffmpegreplay.cpp \
    protocol/chttpapidevice.cpp \
    protocol/mysearch1.cpp \
    protocol/tcpworker.cpp \
    recordVideo/captureScreen/writeh264.cpp \
    qmlcplus/warnmodel.cpp \
    application.cpp \
    qmlcplus/replaydatesearch.cpp \
    thirdSrc/avi/avformat.cpp \
    thirdSrc/avi/avformat_input.cpp \
    thirdSrc/avi/avi_adapt.cpp \
    thirdSrc/avi/avienc_adapt.cpp \
    thirdSrc/avi/hi_avi.cpp \
    recordVideo/record/avirecord.cpp \
    qmlcplus/devicemodel.cpp \
    qmlcplus/facedatamodel.cpp \
    playAudio/mydevice.cpp \
    playAudio/playaudio.cpp \
    protocol/p2pworker.cpp \
    protocol/p2pprotrol.cpp \
    qmlcplus/devicemodeldata.cpp \
    qmlcplus/mylanguage.cpp

HEADERS += \
    playVideo/XVideo.h \
    playVideo/xvideoreplay.h \
    recordVideo/captureScreen/screenvideo.h \
    render/nv12render.h \
    render/renderthread.h \
    render/texturenode.h \
    util/debuglog.h \
    qmlcplus/replaytimeline.h \
    thirdSrc/ffmpeg/ffmpegcodec.h \
    thirdSrc/ffmpeg/ffmpegconvert.h \
    thirdSrc/ffmpeg/ffmpegreplay.h \
    protocol/chttpapidevice.h \
    protocol/mysearch1.h \
    protocol/tcpworker.h \
    recordVideo/captureScreen/writeh264.h \
    qmlcplus/warnmodel.h \
    application.h \
    qmlcplus/replaydatesearch.h \
    thirdSrc/avi/adapt.h \
    thirdSrc/avi/avformat.h \
    thirdSrc/avi/avi_adapt.h \
    thirdSrc/avi/avienc_adapt.h \
    thirdSrc/avi/common.h \
    thirdSrc/avi/debug.h \
    thirdSrc/avi/defs.h \
    thirdSrc/avi/hi_avi.h \
    thirdSrc/avi/hi_type.h \
    recordVideo/record/avirecord.h \
    qmlcplus/devicemodel.h \
    util/help.h \
    qmlcplus/facedatamodel.h \
    playAudio/mydevice.h \
    playAudio/playaudio.h \
    protocol/p2pworker.h \
    protocol/protocal_pkg.h \
    protocol/p2pprotrol.h \
    qmlcplus/devicemodeldata.h \
    util/common.h \
    qmlcplus/mylanguage.h


INCLUDEPATH += $$PWD/avi
INCLUDEPATH += $$PWD/protocol
INCLUDEPATH += $$PWD/playVideo
INCLUDEPATH += $$PWD/playAudio
INCLUDEPATH += $$PWD/render
INCLUDEPATH += $$PWD/thirdSrc
INCLUDEPATH += $$PWD/thirdSrc/ffmpeg
INCLUDEPATH += $$PWD/thirdSrc/avi
INCLUDEPATH += $$PWD/recordVideo/captureScreen
INCLUDEPATH += $$PWD/util
INCLUDEPATH += $$PWD/qmlcplus


INCLUDEPATH += $$PWD/thirdLib/ffmpeg64/include
LIBS += $$PWD/thirdLib/ffmpeg64/lib/avcodec.lib \
        $$PWD/thirdLib/ffmpeg64/lib/avdevice.lib \
        $$PWD/thirdLib/ffmpeg64/lib/avfilter.lib \
        $$PWD/thirdLib/ffmpeg64/lib/avformat.lib \
        $$PWD/thirdLib/ffmpeg64/lib/avutil.lib \
        $$PWD/thirdLib/ffmpeg64/lib/postproc.lib \
        $$PWD/thirdLib/ffmpeg64/lib/swresample.lib \
        $$PWD/thirdLib/ffmpeg64/lib/swscale.lib


#P2P 库
#LIBS+= -L $$PWD/thirdLib/p2p_ppcs/ -l PPCS_API
LIBS+= $$PWD/thirdLib/p2p_ppcs/PPCS_API.lib
INCLUDEPATH += $$PWD/thirdLib/p2p_ppcs/include



#LIBS += -lWs2_32




