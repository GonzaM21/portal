#ifndef SALAESPERA_H
#define SALAESPERA_H

#include <QWidget>

class Inicio : public QWidget
{
public:
    explicit SalaEspera(std::string &host, std::string &port, std::string &player_name, QWidget *parent = 0);
    ~SaleEspera();

private:
    void updateGreetings();
    void connectEvents();
    bool finiched = false;
    std::string &player_name;
    std::string &host;
    std::string &port;
};

#endif // SalaEspera_H
