#include "neuralnetwork.h"

NeuralNetwork::NeuralNetwork(std::vector<int> sizeLayers) : sizeLayers(sizeLayers)
{
    CreateNeiron();
}

NeuralNetwork::NeuralNetwork()
{}


void NeuralNetwork::CreateNeiron()                      //создание слоев
{
    for (size_t i = 0; i < sizeLayers[0]; i++)          //создание и заполнение входного слоя
    {
        inputLayer.push_back(Neiron(0));
    }

    for (size_t i = 1; i < sizeLayers.size(); i++)      //создаём скрытый и выходной слой
    {
        std::vector <NeironHidden> layer;
        for (int c = 0; c < sizeLayers[i]; c++)         //заполняем скрытый и входной слой
        {
            layer.push_back(NeironHidden (sizeLayers[i-1]));
        }
        arrAI.push_back(layer);
    }
}

void NeuralNetwork::StartWork()                     //заполняем значения скрытого и выходного слоя
{
    for (size_t i = 0; i < sizeLayers[1]; i++)      //обрабатываем 1-й скрытый слой
    {
        arrAI[0][i].Adder(inputLayer);
    }

    for (size_t i = 1; i < sizeLayers.size()-1; i++)        //обрабатываем остальные  слои
    {
        for (size_t c = 0; c < sizeLayers[i+1]; c++)
        {
            arrAI[i][c].Adder(arrAI[i-1]);
        }
    }
}

double NeuralNetwork::GetAccuracyValue(size_t rightValue)
{
    double sumValue = 0;
    size_t sizeOutputLayer = sizeLayers[sizeLayers.size()-1];       //получаем размер выходного слоя

    for(size_t i = 0; i < sizeOutputLayer; ++i)         //подсчет суммы
    {
        sumValue += arrAI[arrAI.size()-1][i].GetValue();       //может sizeOutputLayer -1!!!!
    }

    return arrAI[arrAI.size()-1][rightValue].GetValue()*100/sumValue;
}
