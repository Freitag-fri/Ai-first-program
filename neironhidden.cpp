#include "neironhidden.h"
#include <iostream>

neironHidden::neironHidden(double value, int inputQuantityNeiron) : Neiron (value)
{
    //массив весов

    for (int i = 0; i <inputQuantityNeiron; i++)        //массив весов
    {
        double n = rand()%100;
        arrArrweights.push_back(n/100);
    }
}

neironHidden::neironHidden():Neiron (0)     //конструктор по умалчанию для вектора
{

}


//template < typename T >
void neironHidden::Adder(std::vector <neironHidden> &neiron)
{

    for(unsigned int i = 0; i < neiron.size(); i++)
    {
        if (neiron[i].sost)
        {
           value += neiron[i].value *  arrArrweights[i];
        }
    }
    ActivationFunction();
}

void neironHidden::Adder(std::vector <Neiron> &neiron)
{
    for(unsigned int i = 0; i < neiron.size(); i++)
    {
        if (neiron[i].GetSost())
        {
           value += neiron[i].GetValue() *  arrArrweights[i];
        }
    }
    ActivationFunction();
}



void neironHidden::ActivationFunction()
{
    if(value > 1.5)   sost = true;

    else            sost = false;
}


