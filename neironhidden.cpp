#include "neironhidden.h"
#include <iostream>

NeironHidden::NeironHidden(int sizeLastLayer, double value) : Neiron (value)
{
    //массив весов
    for (int i = 0; i < sizeLastLayer; i++)        //массив весов
    {
        double n = rand()%100;
        arrArrweights.push_back(n/100);
    }
}

void NeironHidden::Adder(std::vector <NeironHidden> &neiron)    //сумматор
{
    SetValue(0);                                                //обнуляем значение нейрона
    for(size_t i = 0; i < neiron.size(); i++)
    {
        if (neiron[i].GetSost())
        {
            value += neiron[i].GetValue() *  arrArrweights[i];
        }
    }
    ActivationFunction();
}

void NeironHidden::Adder(std::vector <Neiron> &neiron)          //сумматор
{
    SetValue(0);                                                //обнуляем значение нейрона
    for(size_t i = 0; i < neiron.size(); i++)
    {
        if (neiron[i].GetSost())
        {
            value += neiron[i].GetValue() *  arrArrweights[i];
        }
    }
    ActivationFunction();       //вынести или нет :)
}

void NeironHidden::ActivationFunction()
{
    if(value > 0.5) sost = true;

    else            sost = false;
}


