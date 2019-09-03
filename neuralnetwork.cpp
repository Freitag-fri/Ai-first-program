#include "neuralnetwork.h"

const int NeuralNetwork::quantityNeiron[4] = {4, 8, 15, 16};
//const int outputLayer = NeuralNetwork::quantityNeiron[3];       //количество выходов

NeuralNetwork::NeuralNetwork()
{
    CreateNeiron();
}

void NeuralNetwork::CreateNeiron()                     //создание нейронов
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

void NeuralNetwork::StartWork()
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
}
