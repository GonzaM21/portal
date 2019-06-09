#ifndef INICIO_H
#define INICIO_H

#include <QWidget>

class Inicio : public QWidget
{
public:
  explicit Inicio(std::string &host, std::string &port, std::string &player_name, QWidget *parent = 0);
  unsigned int getWinId();
  bool finished() { return finiched;}

private:
  void updateGreetings();
  void connectEvents();
  bool finiched = false;
  std::string & player_name;
  std::string &host;
  std::string &port;
};

#endif // Inicio_H
