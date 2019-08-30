#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    for (int i = 0; i < 4; i++)
    {
        inputLayer.push_back(Neiron(0));
    }

    for (int i = 1; i < quantityLayer; i++)
    {
        std::vector <neironHidden> *layer = new std::vector <neironHidden>;
        for (int c = 0; c < quantityNeiron[i]; c++)
        {
            layer->push_back(neironHidden (0, quantityNeiron[i-1]));
        }
        arrAI.push_back(*layer);
    }
    //std::vector <neironHidden> n = arrAI[0];
    //double qn = n[4].GetValue();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    inputLayer[0].SetValue(1);
    inputLayer[2].SetValue(1);

    //ui->pushButton->setText(QString::number(n.size()));

    for (unsigned int c = 0; c < quantityNeiron[1]; c++)    //обрабатываем 1-й скрытый слой
    {
        arrAI[0][c].Adder(inputLayer);
    }

    for (unsigned int i = 1; i < quantityLayer-1; i++)        //обрабатываем остальные  слои
    {
        for (unsigned int c = 0; c < quantityNeiron[i+1]; c++)
        {
            arrAI[i][c].Adder(arrAI[i-1]);
        }
    }
}
