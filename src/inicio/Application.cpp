#include "inicio/Application.h"
#include <iostream>

Application::Application(int &argc, char **argv) : QApplication(argc, argv) {}
bool Application::notify(QObject *receiver, QEvent *e) {
  try {
    return QApplication::notify(receiver,e);
  } catch (...) {
    std::cout << e->type();
  }
  return true; 
}
Application::~Application() {
}