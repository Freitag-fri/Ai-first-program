#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    for (int i = 1; i < quantityLayer; i++)
    {
        std::list <neironHidden> *layer = new std::list <neironHidden>;
        for (int c = 0; c < quantityNeiron[i]; c++)
        {
            layer->push_back(neironHidden (c,quantityNeiron[i-1]));
        }
        arrAI.push_back(*layer);
    }
int a;
int b;
}

MainWindow::~MainWindow()
{
    delete ui;
}