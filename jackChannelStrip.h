#ifndef JCS_H
#define JCS_H

#include <faust/dsp/dsp.h>
#include <faust/gui/meta.h>
#include <faust/gui/QTUI.h>
#include "channelStrip.h"

#include <jack/jack.h>

class JackChannelStrip{
  jack_client_t myClient;
  ChannelStrip * myChannelStrip;
  int process();
  public:
  void init();
  JackChannelStrip(ChannelStrip * cs);
};

#endif