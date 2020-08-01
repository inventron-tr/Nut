win32 {
    CONFIG(debug,debug|release):   LIBDIR = $$absolute_path($$OUT_PWD/../../../src/nut/debug)
    CONFIG(release,debug|release): LIBDIR = $$absolute_path($$OUT_PWD/../../../src/nut/release)
    LIBS += -L$$LIBDIR -lnut
} else {
    LIBDIR = $$absolute_path($$OUT_PWD/../../../lib)
    android: {

           contains(ANDROID_TARGET_ARCH,armeabi-v7a)  {
               LIBS += -L$$LIBDIR -lnut_armeabi-v7a
           }
           contains(ANDROID_TARGET_ARCH,arm64-v8a)  {
               LIBS += -L$$LIBDIR -lnut_arm64-v8a
           }
           contains(ANDROID_TARGET_ARCH,x86)  {
               LIBS += -L$$LIBDIR -lnut_x86
           }
           contains(ANDROID_TARGET_ARCH,x86_64)  {
               LIBS += -L$$LIBDIR -lnut_x86_64
           }
    } else {
#        LIBS += -L$$LIBDIR -lnut
    }
}

#INCLUDEPATH += $$PWD/../../../src/nut
INCLUDEPATH += $$PWD/../common

QT += nut

DEFINES += NUT_SHARED_POINTER
DEFINES += NUT_PATH=\\\"$$PWD/../../\\\"

runtarget.target = run-tests
runtarget.CONFIG = recursive
runtarget.recurse_target = run-tests
QMAKE_EXTRA_TARGETS += runtarget
