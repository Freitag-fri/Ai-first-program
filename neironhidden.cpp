#include "neironhidden.h"

neironHidden::neironHidden(double value, int inputQuantityNeiron) : Neiron (value)
{
               //массив весов

    for (int i = 0; i <inputQuantityNeiron; i++)
    {
       arrArrweights.push_back(5);
    }
}

neironHidden::neironHidden():Neiron (0)
{

}

