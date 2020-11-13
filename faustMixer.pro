message(Building channel strip)
system(faust $$PWD/faustTest.dsp -o channelStrip.h -cn ChannelStrip)

CONFIG += c++11 console

CONFIG += qt

QT += gui widgets

SOURCES += lrmixer.cpp

FAUSTINC = /usr/local/include/faust/


INCLUDEPATH += $$FAUSTINC
message($$FAUSTINC)

LIBS += -ljack

HEADERS += $$FAUSTINC/gui/QTUI.h
HEADERS += $$FAUSTINC/gui/GUI.h

HEADERS += channelStrip.h
#HEADERS += jackChannelStrip.h

#SOURCES += jackChannelStrip.cpp



RESOURCES += $$FAUSTINC/gui/Styles/Grey.qrc