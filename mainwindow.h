#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <neironhidden.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    static const int quantityLayer = 3;                     //количество слоёв
    const int quantityNeiron[quantityLayer] = {4,2,3};      //количество нейронов в каждом слое
    std::vector <std::vector <neironHidden>> arrAI;
    std::vector <Neiron> inputLayer;
};

#endif // MAINWINDOW_H
