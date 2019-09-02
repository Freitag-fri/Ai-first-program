#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateNeiron();
    CreateLineEdit();
    //    QPushButton* but = new QPushButton(this);
    //    but->resize(75,23);   //размер
    //    but->move(55,55);       //координаты
}

void MainWindow::CreateLineEdit()
{
    for (int i = 0; i < outputLayer; i++)
    {
        QLineEdit* line = new QLineEdit(this);
        line->resize(75,22);                             //размер
        line->move(250,40+(23*i));                               //координаты
        arrLineEdit[i] = line;
    }
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
    DesiredValue();

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
    for(int i = 0; i < outputLayer; ++i)
    {
        arrLineEdit[i]->setText(QString::number(arrAI[quantityLayer-2][i].GetValue()));
    }
}

void MainWindow::DesiredValue()
{
    desiredValue = 0;
    for (unsigned int i = 0; i < inputLayer.size(); i++)
    {
        if(inputLayer[i].GetSost() && i == 0)
        {
          desiredValue ++;
        }
        else if(inputLayer[i].GetSost())
        {
          desiredValue += pow(2,i);
        }
    }
    ui->lineEdit_4->setText(QString::number(desiredValue));
}

void MainWindow::on_checkBox_0_clicked()
{
    inputLayer[0].SetValue(ui->checkBox_0->isChecked());
    inputLayer[0].SetSost(ui->checkBox_0->isChecked());
    DesiredValue();
}

void MainWindow::on_checkBox_1_clicked()
{
    inputLayer[1].SetValue(ui->checkBox_1->isChecked());
    inputLayer[1].SetSost(ui->checkBox_1->isChecked());
    DesiredValue();
}

void MainWindow::on_checkBox_2_clicked()
{
    inputLayer[2].SetValue(ui->checkBox_2->isChecked());
    inputLayer[2].SetSost(ui->checkBox_2->isChecked());
    DesiredValue();
}

void MainWindow::on_checkBox_3_clicked()
{
    inputLayer[3].SetValue(ui->checkBox_3->isChecked());
    inputLayer[3].SetSost(ui->checkBox_3->isChecked());
    DesiredValue();
}
