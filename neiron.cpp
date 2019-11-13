#include "neiron.h"

Neiron::Neiron(double value)
{
    this->value = value;
    sost = false;
}

void Neiron::SetValue(double value)
{
    if(value <0.05)
        {this->value = 0.1;}
    else
        {this->value = value;}
}

void Neiron::SetSost(bool sost)
{
    this->sost = sost;
}

double Neiron::GetValue()
{
    return  value;
}

bool Neiron::GetSost()
{
    return  sost;
}
