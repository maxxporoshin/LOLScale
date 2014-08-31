#include "libs.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainList = this->findChild<QListWidget*>("mainList");
    label = this->findChild<QLabel*>("label");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mainList;
}
