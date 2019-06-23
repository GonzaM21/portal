#include <QApplication>

class Application Q_DECL_FINAL : public QApplication {
  Q_OBJECT
public:
  Application(int &argc, char **argv);
  virtual bool notify(QObject *receiver, QEvent *e) override;
  virtual ~Application();
};
