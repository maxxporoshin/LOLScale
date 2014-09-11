#include "libs.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    imgPackFile = "images.mmp";
    statsFile = "stats.mmt";
    pack("Images", false);
    ui->setupUi(this);
    initMainList();
    connect(ui->mainList, &QListWidget::itemSelectionChanged, this, &MainWindow::setLabels);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabels()
{
    QListWidgetItem *item = ui->mainList->selectedItems().first();
    QPixmap pixmap(getImage(imgPackFile, item->text(), 2));
    ui->labelLoad->setPixmap(pixmap);
    ui->labelName->setText(item->text());
    Champ champ = getChampStats(statsFile, item->text());
    ui->labelRPCost->setText(champ.rpCost);
    ui->labelIPCost->setText(champ.ipCost);
    ui->labelPopularity->setText(champ.popularity);
    ui->labelWinRate->setText(champ.winRate);
    ui->labelBanRate->setText(champ.banRate);
    ui->labelReleased->setText(champ.released);
}

void MainWindow::initMainList()

{
    QFile chList(statsFile);
    chList.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream inStream(&chList);
    while (!inStream.atEnd())
    {
        QString champName = inStream.readLine().section('@', 1, 1);
        new QListWidgetItem(getImage(imgPackFile, champName, 0), champName, ui->mainList);
    }
}

void MainWindow::pack(const QString &imgFolderPath, bool isNeeded)
{
    if (isNeeded)
    {
        int hashAlign = setImgHash(statsFile, imgPackFile);
        packImages(imgPackFile, imgFolderPath, hashAlign);
    }
}
