#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString imgPackFile;
    QString champListFile;
    void initMainList();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void setLabels(QListWidgetItem* item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
