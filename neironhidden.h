#ifndef NEIRONHIDDEN_H
#define NEIRONHIDDEN_H
#include <neiron.h>
#include <vector>

class neironHidden: public Neiron
{
public:
    neironHidden(double value, int aaa);
    neironHidden();
    void ActivationFunction();
    //template < typename T >
    void Adder(std::vector <neironHidden> &neirin);
    void Adder(std::vector <Neiron> &neirin);

private:
    //int quantityInput;              //количество нейронов в превидущем слое

    std::vector<double> arrArrweights;
};

#endif // NEIRONHIDDEN_H
