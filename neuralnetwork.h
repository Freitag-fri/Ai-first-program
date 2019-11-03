#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include <QLineEdit>
#include <iostream>
#include <neironhidden.h>


class NeuralNetwork : public NeironHidden
{
public:

    NeuralNetwork();
    void CreateNeiron();
    void StartWork();

//private:
    static const int quantityLayer = 4;                     //количество слоёв
    static const int outputLayer = 16;                      //выходной слой
    static const int quantityNeiron[quantityLayer];      //количество нейронов в каждом слое

    std::vector <std::vector <NeironHidden>> arrAI;
    std::vector <Neiron> inputLayer;
};


#endif // NEURALNETWORK_H
