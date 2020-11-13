#include "jackChannelStrip.h"

int JackChannelStrip::init(){
  jack_options_t myOptions = JackNoStartServer;
  jack_status_t status;

  myClient = jack_client_open("JCS", myOptions, &status);
  if (client == NULL) {
		fprintf (stderr, "jack_client_open() failed, "
			 "status = 0x%2.0x\n", status);
		if (status & JackServerFailed) {
			fprintf (stderr, "Unable to connect to JACK server\n");
		}
		return 1;
	}

  jack_port_register(myClient, "IN", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
  jack_port_register(myClient, "OUT", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
  if ((input_port == NULL) || (output_port == NULL)) {
		fprintf(stderr, "no more JACK ports available\n");
		return 1;
	}

  jack_set_process_callback (client, process, this);
}
int JackChannelStrip::process(){
  myChannelStrip->compute();
  return 0;
}
JackChannelStrip::JackChannelStrip(ChannelStrip * cs){
  myClient = NULL;
  myChannelStrip = cs;
}
JackChannelStrip::~JackChannelStrip(){
  if (myClient){
    jack_client_close(myClient);
    jack_free(myClient);
  }
}