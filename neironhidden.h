#ifndef NEIRONHIDDEN_H
#define NEIRONHIDDEN_H
#include <neiron.h>
#include <vector>

class NeironHidden: public Neiron
{
public:
    NeironHidden(double value, int aaa);
    NeironHidden();
    void ActivationFunction();
    //template < typename T >
    void Adder(std::vector <NeironHidden> &neirin);
    void Adder(std::vector <Neiron> &neirin);

private:
    //int quantityInput;              //количество нейронов в превидущем слое

    std::vector<double> arrArrweights;
};

#endif // NEIRONHIDDEN_H
