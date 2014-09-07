#include "libs.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainList = ui->mainList;
    labelLoad = ui->labelLoad;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mainList;
    delete labelLoad;
}
