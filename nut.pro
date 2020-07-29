load(qt_parts)
#system($$[QT_INSTALL_BINS]/syncqt.pl -version 0.6.0 -outdir $$OUT_PWD)

runtests.target = run-tests
runtests.CONFIG = recursive
runtests.recurse_target = run-tests
runtests.recurse += sub_tests sub_src
QMAKE_EXTRA_TARGETS += runtests

DISTFILES += .qmake.conf \
        sync.profile
