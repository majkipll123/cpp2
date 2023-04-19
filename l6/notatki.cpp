#include <iostream>
#include <vector>
class Figura
{
    public:
        virtual double pole() const;
    protected:
        double x,y;
};

void pisz_pole(const Figura & f)

{
    std::cout << "Pole figury: " << f.pole() << std::endl;
}

void pisz_pole(const std::vector<Figura*> & w)

{
    for (const auto & x: w)
    {
    std::cout << "pole = "<< x->pole() << std::endl;
    }
}

class Kwadrat : public Figura
{
    public:
        Kwadrat(double bok)
            : _bok(bok)
        {
            x=0;
        }
        double pole() const { return _bok * _bok; }
    private:
        double _bok;
};

class Trojkat : public Figura
{
    public:
        Trojkat(double bok)
            : _bok(bok)
        {}
        double pole() const { return _bok * _bok * std::sqrt(3.0) /2.0; }
};
int main()
{
    Figura f;
    Kwadrat kw(10.0);
    Trojkat tr(1.0)

    std::vector<Figura*> v = { &kw, &tr};






    Figura* p = &kw;
    return 0;
}