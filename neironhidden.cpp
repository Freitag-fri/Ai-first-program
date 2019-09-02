#include "neironhidden.h"
#include <iostream>

NeironHidden::NeironHidden(double value, int inputQuantityNeiron) : Neiron (value)
{
    //массив весов

    for (int i = 0; i <inputQuantityNeiron; i++)        //массив весов
    {
        double n = rand()%100;
        arrArrweights.push_back(n/100);
    }
}

NeironHidden::NeironHidden():Neiron (0)     //конструктор по умалчанию для вектора
{

}


//template < typename T >
void NeironHidden::Adder(std::vector <NeironHidden> &neiron)
{
    SetValue(0);                                                //обнуляем значение нейрона
    for(unsigned int i = 0; i < neiron.size(); i++)
    {
        if (neiron[i].sost)
        {
            value += neiron[i].value *  arrArrweights[i];
        }
    }
    ActivationFunction();
}

void NeironHidden::Adder(std::vector <Neiron> &neiron)
{
    SetValue(0);                                                //обнуляем значение нейрона
    for(unsigned int i = 0; i < neiron.size(); i++)
    {
        if (neiron[i].GetSost())
        {
            value += neiron[i].GetValue() *  arrArrweights[i];
        }
    }
    ActivationFunction();

}

//void NeironHidden::ZeroingValue(std::vector <NeironHidden> &neiron)
//{
//    for(unsigned int i = 0; i < neiron.size(); i++)
//    {
//        neiron[i].SetValue(0);
//        neiron[i].SetSost(false);
//    }
//}

void NeironHidden::ActivationFunction()
{
    if(value > 1)   sost = true;

    else            sost = false;
}


