TEMPLATE = app

# Make sure we do not accidentally #include files placed in 'resources'
CONFIG += no_include_pwd
#CONFIG += static
#CONFIG += staticlib

SOURCES = $$PWD/src/*.cpp \
    P4Map.cpp
SOURCES += $$PWD/lib/StanfordCPPLib/*.cpp
HEADERS = $$PWD/src/*.h
HEADERS += $$PWD/lib/StanfordCPPLib/*.h

QMAKE_CXXFLAGS += -std=c++11
#QMAKE_CXXFLAGS += -lpthread
#QMAKE_LFLAGS += -static
#QMAKE_LFLAGS += -static-libgcc
#QMAKE_LFLAGS += -static-libstdc++

INCLUDEPATH += $$PWD/lib/StanfordCPPLib/

# Copies the given files to the destination directory
defineTest(copyToDestdir) {
    files = $$1

    for(FILE, files) {
        DDIR = $$OUT_PWD

        # Replace slashes in paths with backslashes for Windows
        win32:FILE ~= s,/,\\,g
        win32:DDIR ~= s,/,\\,g

        !win32 {
            QMAKE_POST_LINK += cp -r '"'$$FILE'"' '"'$$DDIR'"' $$escape_expand(\\n\\t)
        }
        win32 {
            QMAKE_POST_LINK += xcopy '"'$$FILE'"' '"'$$DDIR'"' /e /y $$escape_expand(\\n\\t)
        }
    }

    export(QMAKE_POST_LINK)
}
!win32 {
    copyToDestdir($$files($$PWD/res/*))
    copyToDestdir($$files($$PWD/lib/*.jar))
}
win32 {
    copyToDestdir($$PWD/res)
    copyToDestdir($$PWD/lib/*.jar)
}

OTHER_FILES += \
    ../build-Life-Desktop_Qt_5_2_1_MinGW_32bit-Debug/simple.txt \
    ../build-Life-Desktop_Qt_5_2_1_MinGW_32bit-GCC/diehard.txt \
    ../build-Life-Desktop_Qt_5_2_1_MinGW_32bit-GCC/dinner-table.txt \
    ../build-Life-Desktop_Qt_5_2_1_MinGW_32bit-GCC/fish.txt \
    ../build-Life-Desktop_Qt_5_2_1_MinGW_32bit-GCC/flower.txt \
    ../build-Life-Desktop_Qt_5_2_1_MinGW_32bit-GCC/glider.txt \
    ../build-Life-Desktop_Qt_5_2_1_MinGW_32bit-GCC/rpent.txt \
    ../build-Life-Desktop_Qt_5_2_1_MinGW_32bit-GCC/seeds.txt \
    ../Ngrams/aaa.txt
