#include "neiron.h"

Neiron::Neiron(double value)
{
    this->value = value;
    sost = false;
}

void Neiron::SetValue(double value)
{
    this->value = value;
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
    int test;
    return  sost;
}
