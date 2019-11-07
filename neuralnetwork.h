#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include <QLineEdit>
#include <iostream>
#include <neironhidden.h>
#include <array>

class NeuralNetwork
{
public:


    NeuralNetwork(std::vector<int> sizeLayers);
    NeuralNetwork();
    void CreateNeiron();
    void StartWork();

//    NeuralNetwork &operator = (NeuralNetwork &other)
//    {
//       //this->arrAI[0][0].arrArrweights[2] = this->arrAI[0][0].arrArrweights[2];
//        std::copy(this->arrAI[0][0].arrArrweights.begin(), this->arrAI[0][0].arrArrweights.end(), other.arrAI[0][0].arrArrweights.begin());
//        return *this;
//    }

    std::vector <std::vector <NeironHidden>> arrAI;
    std::vector <Neiron> inputLayer;

    std::vector<int> sizeLayers;                //размеры слоев сети

    double GetAccuracyValue(size_t rightValue);
};


#endif // NEURALNETWORK_H
