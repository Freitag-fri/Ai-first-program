#ifndef NEIRON_H
#define NEIRON_H


class Neiron
{
public:
    Neiron(double value)
    {
        this->value = value;
        sost = true;
    }

    void SetValue(double value)     {this->value = value;}
    double GetValue()   {return  value;}
    bool GetSost()      {return  sost;}

protected:
    double value;
    bool sost;
};

#endif // NEIRON_H
