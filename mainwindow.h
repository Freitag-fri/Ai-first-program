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
    void CreateNeiron();
    void ResultPrint();

private slots:
    void on_pushButton_clicked();

    void on_checkBox_0_clicked();

    void on_checkBox_1_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

private:
    Ui::MainWindow *ui;

    static const int quantityLayer = 4;                     //количество слоёв
    const int quantityNeiron[quantityLayer] = {4,8,15,16};      //количество нейронов в каждом слое
    std::vector <std::vector <NeironHidden>> arrAI;
    std::vector <Neiron> inputLayer;
};

#endif // MAINWINDOW_H
