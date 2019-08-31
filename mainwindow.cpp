#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateNeiron();
}

void MainWindow::CreateNeiron()                     //создание нейронов
{
    for (int i = 0; i < quantityNeiron[0]; i++)     //входной слой
    {
        inputLayer.push_back(Neiron(0));
    }

    for (int i = 1; i < quantityLayer; i++)         //скрытый и выходной слой
    {
        std::vector <NeironHidden> *layer = new std::vector <NeironHidden>;
        for (int c = 0; c < quantityNeiron[i]; c++)
        {
            layer->push_back(NeironHidden (0, quantityNeiron[i-1]));
        }
        arrAI.push_back(*layer);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    for (int c = 0; c < quantityNeiron[1]; c++)    //обрабатываем 1-й скрытый слой
    {
        arrAI[0][c].Adder(inputLayer);
    }

    for (int i = 1; i < quantityLayer-1; i++)        //обрабатываем остальные  слои
    {
        for (int c = 0; c < quantityNeiron[i+1]; c++)
        {
            arrAI[i][c].Adder(arrAI[i-1]);
        }
    }

ResultPrint();
}

void MainWindow::ResultPrint()
{
  ui->lineEdit_0->setText(QString::number(arrAI[quantityLayer-2][0].GetValue()));
}

void MainWindow::on_checkBox_0_clicked()
{
    inputLayer[0].SetValue(ui->checkBox_0->isChecked());
    inputLayer[0].SetSost(ui->checkBox_0->isChecked());
}

void MainWindow::on_checkBox_1_clicked()
{
    inputLayer[1].SetValue(ui->checkBox_1->isChecked());
    inputLayer[1].SetSost(ui->checkBox_0->isChecked());
}

void MainWindow::on_checkBox_2_clicked()
{
    inputLayer[2].SetValue(ui->checkBox_2->isChecked());
    inputLayer[2].SetSost(ui->checkBox_0->isChecked());
}

void MainWindow::on_checkBox_3_clicked()
{
    inputLayer[3].SetValue(ui->checkBox_3->isChecked());
    inputLayer[3].SetSost(ui->checkBox_0->isChecked());
}
