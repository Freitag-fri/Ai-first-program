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

private:
    //int quantityInput;              //количество нейронов в превидущем слое

    std::vector<int> arrArrweights;
};

#endif // NEIRONHIDDEN_H
