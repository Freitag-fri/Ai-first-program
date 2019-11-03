#ifndef NEIRON_H
#define NEIRON_H


class Neiron
{
public:
    Neiron(double value);

    void SetValue(double value);
    void SetSost(bool sost);

    double  GetValue();
    bool    GetSost();

protected:
    double value;
    bool sost;
};

#endif // NEIRON_H
