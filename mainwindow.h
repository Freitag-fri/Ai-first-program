#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <neironhidden.h>
#include <QLineEdit>
#include <array>
#include <neuralnetwork.h>
#include <QCheckBox>
#include <windows.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void CreateNeiron();
    void CreateLineEdit();
    void CreateNetwork();

    void ResultPrint();
    int BestNetWork();          //поиск лучшей сети
    void DesiredValue();
    void SetValueInputLayer();
    void InheritanceNetWork(int indexBestNetWork);

private slots:
    void on_pushButton_clicked();

    void on_checkBox_0_clicked();

    void on_checkBox_1_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    int desiredValue = 0;       //нужное число

    static const int InputLayer = 4;
    static const int OutputLayer = 16;
    std::vector <int> sizeNetwork = {InputLayer, 25, 50, 70, 90, 50, 60, 40, OutputLayer};

    bool stop = false;


    QLineEdit  *arrLineEdit[OutputLayer];
//    std::vector <std::vector <NeironHidden>> arrAI;
//    std::vector <Neiron> inputLayer;
    std::array<NeuralNetwork*, 5> networkVec;
    std::array<QCheckBox*, 4> arrCheckBox;
};

#endif // MAINWINDOW_H
