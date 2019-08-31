#ifndef NEIRON_H
#define NEIRON_H


class Neiron
{
public:
    Neiron(double value)
    {
        this->value = value;
        sost = false;
    }

    void SetValue(double value)     {this->value = value;}
    void SetSost(bool sost)     {this->sost = sost;}
    double GetValue()   {return  value;}
    bool GetSost()      {return  sost;}

protected:
    double value;
    bool sost;
};

#endif // NEIRON_H
