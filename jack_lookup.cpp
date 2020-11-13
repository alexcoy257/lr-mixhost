#include <iostream>
#include <unistd.h>
#include <jack/jack.h>

int main(){
  jack_options_t myOptions = JackNoStartServer;
  jack_client_t * myClient = jack_client_open("Reader", myOptions, NULL);
  
  const char ** ports = NULL;
  
  if (myClient) {
    std::cout << "Jack Client open successful\n ";
    ports = jack_get_ports (myClient, ".*", NULL, JackPortIsInput);
    
    int n=0;
    while (ports[n]){
      std::cout <<"Input Port: " <<ports[n] <<"\n";
      n++;
    }
    jack_free(ports);
    
    ports = jack_get_ports (myClient, ".*", NULL, JackPortIsOutput);
    
    n=0;
    while (ports[n]){
      std::cout <<"Output Port: " <<ports[n] <<"\n";
      n++;
    }
    jack_free(ports);
    }
  //sleep(5);
  
  jack_free(myClient);

  std::cout << "Hello World \n";
  return 0;
}
