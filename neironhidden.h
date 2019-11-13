#ifndef NEIRONHIDDEN_H
#define NEIRONHIDDEN_H
#include <neiron.h>
#include <vector>

class NeironHidden: public Neiron
{
public:
    NeironHidden(int sizeLastLayer, double value = 0);
 //   NeironHidden();
    void ActivationFunction();
    void Adder(std::vector <NeironHidden> &neirin);
    void Adder(std::vector <Neiron> &neirin);
    void Mutation();

    NeironHidden &operator = (NeironHidden &other)
    {
        this->arrArrweights = other.arrArrweights;
        return *this;
    }

    std::vector<double> arrArrweights;      //массив векторов
};

#endif // NEIRONHIDDEN_H
