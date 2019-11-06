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

  //  void ZeroingValue(std::vector <NeironHidden> &neiron);

private:
    //int quantityInput;              //количество нейронов в превидущем слое

    std::vector<double> arrArrweights;      //
};

#endif // NEIRONHIDDEN_H
