#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
  this->proxies = getproxies();
  this->proxylayout = new QWidget(this);
  QWindow w ;
}
void MainWindow::setupProxy() {

  QGridLayout *layout = new QGridLayout(this->proxylayout);
  this->proxylayout->setLayout(layout);
  for (int i = 0; i < this->proxies.size(); ++i) {
    Proxy p = this->proxies.at(i);
    layout->addWidget(new QLabel(p.name.c_str()), i / 3, i % 3);
  }
}

MainWindow::~MainWindow() { delete this->proxylayout; }
