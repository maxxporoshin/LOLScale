#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

struct Champ
{
    QString rpCost;
    QString ipCost;
    QString popularity;
    QString winRate;
    QString banRate;
    QString released;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString imgPackFile;
    QString statsFile;
    void initMainList();
    void pack(const QString &imgFolderPath, bool isNeeded);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void setLabels();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
