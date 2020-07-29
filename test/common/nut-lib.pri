win32 {
    CONFIG(debug,debug|release):   LIBDIR = $$absolute_path($$OUT_PWD/../../src/debug)
    CONFIG(release,debug|release): LIBDIR = $$absolute_path($$OUT_PWD/../../src/release)
    LIBS += -L$$LIBDIR -lnut
} else {
    LIBDIR = $$absolute_path($$OUT_PWD/../../src)
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
        LIBS += -L$$LIBDIR -lnut
    }
}

INCLUDEPATH += $$PWD/../../src $$PWD/../common

DEFINES += NUT_SHARED_POINTER
DEFINES += NUT_PATH=\\\"$$PWD/../../\\\"
