#include <iostream>
#include <unistd.h>
#include <jack/jack.h>
#include <Patcher.h>
#include <QCoreApplication>
#include <QScopedPointer>

using std::cout;



int main(int argc, char *argv[]){
  QCoreApplication app(argc, argv);
  QScopedPointer<Patcher> thePatcher(new Patcher());

  cout << "Hello World \n";

  Q_UNUSED(thePatcher);
  

  return app.exec();
}
