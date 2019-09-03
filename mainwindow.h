#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <neironhidden.h>
#include <QLineEdit>
#include <vector>
#include <neuralnetwork.h>
#include <QCheckBox>


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
    void ResultPrint();
    void DesiredValue();

private slots:
    void on_pushButton_clicked();

    void on_checkBox_0_clicked();

    void on_checkBox_1_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

private:

    int desiredValue = 0;       //нужное число

    Ui::MainWindow *ui;

//    static const int quantityLayer = 4;                     //количество слоёв
//    static const int outputLayer = 16;                      //выходной слой
//    const int quantityNeiron[quantityLayer] = {4, 8, 15, outputLayer};      //количество нейронов в каждом слое

    QLineEdit  *arrLineEdit[NeuralNetwork::outputLayer];
//    std::vector <std::vector <NeironHidden>> arrAI;
//    std::vector <Neiron> inputLayer;
    std::vector<NeuralNetwork> network;
    QCheckBox *arrCheckBox[4];

    NeuralNetwork firstNeiron;          //нейронная сеть
};

#endif // MAINWINDOW_H
