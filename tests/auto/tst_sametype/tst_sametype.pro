QT       += testlib sql

TARGET = tst_upgrades
TEMPLATE = app
CONFIG   += warn_on c++11

include(../common/nut-lib.pri)

SOURCES +=  \
    db.cpp \
    sampletable.cpp \
    tst_sametypes.cpp

HEADERS += \
    db.h \
    sampletable.h \
    tst_sametypes.h

