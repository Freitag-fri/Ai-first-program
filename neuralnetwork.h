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

    std::vector <std::vector <NeironHidden>> arrAI;
    std::vector <Neiron> inputLayer;

    std::vector<int> sizeLayers;
};


#endif // NEURALNETWORK_H
