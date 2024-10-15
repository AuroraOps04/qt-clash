#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "proxy.h"
#include <QtWidgets>
#include <vector>

class MainWindow : public QWidget {
  Q_OBJECT
public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void setupProxy();

private:
  std::vector<Proxy> proxies;
  QWidget *proxylayout;
};

#endif // MAINWINDOW_H
