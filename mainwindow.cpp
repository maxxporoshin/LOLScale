#include "libs.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    champListFile = "championList.txt";
    imgPackFile = "images.pack";
    ui->setupUi(this);
    initMainList();
    connection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabels(QListWidgetItem* item)
{
    QPixmap pixmap(getImage(this->imgPackFile, item->text(), 2));
    this->ui->labelLoad->setPixmap(pixmap);
    this->ui->labelName->setText(item->text());
}

void MainWindow::connection()
{
    connect(this->ui->mainList, &QListWidget::itemClicked, this, &MainWindow::setLabels);
}

void MainWindow::initMainList()

{
    QFile chList(champListFile);
    chList.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream inStream(&chList);
    while (!inStream.atEnd())
    {
        QString champName = inStream.readLine();
        new QListWidgetItem(getImage(imgPackFile, champName, 0), champName, this->ui->mainList);
    }
}
