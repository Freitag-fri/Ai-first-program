#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // CreateNeiron();
    CreateLineEdit();
    CreateNetwork();
}

MainWindow::~MainWindow()
{
    // delete networkVec;

    delete ui;
}

void MainWindow::CreateNetwork()
{

    for(size_t i = 0; i < networkVec.size(); i++)
    {
        NeuralNetwork *network = new NeuralNetwork(sizeNetwork);
        networkVec[i] = network;
    }
}

void MainWindow::CreateLineEdit()               //отображение выходных значений
{
    for (size_t i = 0; i < 4; i++)
    {
        QCheckBox* box = new QCheckBox(this);
        box->resize(75, 22);                             //размер
        box->move(100, 140 + (20*i));                               //координаты
        box->setText(QString::number(i));
        arrCheckBox[i] = box;
    }

    for (int i = 0; i < OutputLayer; i++)
    {
        QLineEdit* line = new QLineEdit(this);
        line->resize(75, 22);                             //размер
        line->move(250, 40+(23*i));                               //координаты
        arrLineEdit[i] = line;
    }
}


void MainWindow::on_pushButton_clicked()
{
    DesiredValue();

    SetValueInputLayer();
    for(int i = 0; i < networkVec.size(); i++)
    {
        networkVec[i]->StartWork();
    }

    ResultPrint();
}

void MainWindow::SetValueInputLayer()
{
    for (size_t c = 0; c < networkVec.size(); c++)      // заполняем входной члой данными
    {
        for (size_t i = 0; i < 4; i++)
        {
            networkVec[c]->inputLayer[i].SetValue(arrCheckBox[i]->isChecked());
            networkVec[c]->inputLayer[i].SetSost(arrCheckBox[i]->isChecked());
        }
    }
}

void MainWindow::ResultPrint()              //вывод результата
{
    double sumValue = 0;
    for(size_t i = 0; i < OutputLayer; ++i)         //подсчет суммы
    {
        sumValue += networkVec[1]->arrAI[sizeNetwork.size()-2][i].GetValue();
    }


    double buf = 0;
    double Maxbuf = -1;
    int bestElement = -1;
    for(size_t i = 0; i < OutputLayer; ++i)         //подсчет %
    {
        buf = networkVec[1]->arrAI[sizeNetwork.size()-2][i].GetValue()*100/sumValue;
        arrLineEdit[i]->setText(QString::number(buf));

        if (buf > Maxbuf)
        {
            Maxbuf = buf;
            bestElement = i;
        }
    }
    ui->lineEdit_5->setText(QString::number(bestElement));
//    for(size_t i = 0; i < OutputLayer; ++i)       //вывод значения
//    {
//        arrLineEdit[i]->setText(QString::number(networkVec[0]->arrAI[sizeNetwork.size()-2][i].GetValue()));
//    }
}

void MainWindow::DesiredValue()         //считаем число которое должно получиться
{


    ////////////////////////////////////////////////////////////////////

    desiredValue = 0;
    for (size_t i = 0; i < InputLayer; i++)
    {
        if(arrCheckBox[i]->isChecked() && i == 0)
        {
            desiredValue ++;
        }
        else if(arrCheckBox[i]->isChecked())
        {
            desiredValue += pow(2,i);
        }
    }
    ui->lineEdit_4->setText(QString::number(desiredValue));
}

void MainWindow::on_checkBox_0_clicked()
{
    //    inputLayer[0].SetValue(ui->checkBox_0->isChecked());
    //    inputLayer[0].SetSost(ui->checkBox_0->isChecked());
    //    DesiredValue();
}

void MainWindow::on_checkBox_1_clicked()
{
    //    inputLayer[1].SetValue(ui->checkBox_1->isChecked());
    //    inputLayer[1].SetSost(ui->checkBox_1->isChecked());
    //    DesiredValue();
}

void MainWindow::on_checkBox_2_clicked()
{
    //    inputLayer[2].SetValue(ui->checkBox_2->isChecked());
    //    inputLayer[2].SetSost(ui->checkBox_2->isChecked());
    //    DesiredValue();
}

void MainWindow::on_checkBox_3_clicked()
{
    //    inputLayer[3].SetValue(ui->checkBox_3->isChecked());
    //    inputLayer[3].SetSost(ui->checkBox_3->isChecked());
    //    DesiredValue();
}
