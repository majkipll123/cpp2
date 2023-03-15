#include <iostream>

// include wector 
#include <vector>
//notatki z wykładu 
struct Pracownik 
{

    std::string nazwisko;
    int rok_urodzenia;
    double wynagrodzenia[10000]; 
    //tablica 10000 elementowa zajmuje 80 kB
};
//zamiast kopjowac cala wartosc tablicy mozna przekazac wskaznik na tablice
//a jezeli nie chcemy jej modyfikowac to przekazujemy przez const  
void f(Pracownik & p)
{

}

int suma(int a, int b)
{
    a = 0;
    return a+b;
}

//przekasanie poprzez wskasnik

int sumas(int* a, int b)
{
    *a = 0;
    return *a+b;
}
//wszedzie gdzie mamy cout mozemy napisac printer 
std::ostream& printer()
{
    return std::cout;
}

int operator*(const std::vector<int> & v,const std::vector<int> & w)
{
    //zle jest ze wektory przekazujemy przez wartosc wektory sa duze
    //lepiej przekazac przez referencje
    int skalarny = 0;
    for (int i=0; i < v.size(); i++)
    {
        skalarny += v[i]*w[i];
    }
    return skalarny;
}

std::ostream& operator <<(std::ostream& out,const std::vector<int> & v)
{

    out << "[ ";
    if(!v.empty())
    {
        out << v[0];
        //albo v.front()
    }
    for (int i=1; i < v.size(); i++)
    {
        out << ", " << v[i];
    }
    out << " ]";
    return out;
}
//silnia poprzez rekurencje 
float silnia(int n)
{
    if (n==0)
        return 1;
    
    else
        return n*silnia(n-1);
}

int main(int argc, char const *argv[])
{
    if (argc <=1) throw std::logic_error("oczekiwano liczby");  
    int k=std::stoi(argv[1]);
    std::cout << silnia(k) << "\n";
    int n;
    Pracownik kazio;
    kazio.nazwisko = "Jan Maria";
    Pracownik* p = &kazio;
    std::cout << p->nazwisko <<"\n";
    //int k=9;
    std::cout << suma(5,6) << "\n";
    std::cout << suma(k+4,6) << "\n";
    //przekazanie argumentu przez wartosc nie zeruje poprzedniej wartosci zmiennej 
    std::cout << suma(k,6) << "\n";
    std::cout << k << "\n";
    //argment przekazuje tylko wartosc 
    //zeby zmienic wartosc argumentu trzeba uzyc wskaznika 
    std::cout << sumas(&k,6) << "\n";
    //teraz k zostanie wyzerowane 
    std::cout << k << "\n";
    //istnieje nieskonczona liczba beldow ktore mozna popelnic wskaznikami
    //trzeba duzego doswiadczenia i lat pracy zeby poslugiwac sie wskaznikami bezbłędnie
    //HISTORYCZNE POROWNANIE 
    //nie calujemy obcej osoby 
    //chyba ze ratujemy jej zycie 
    //albo sie napijemy
    //przekazanie przez referencje za pomoca &

    int& r = k;
    r = 15;
    std::cout << k << "\n";
    //PRZEKAZANIE POPRZEZ CONST REFERENCE
    //nie mozna zmienic wartosci zmiennej
    //ale mozna zmienic wartosc zmiennej wskazywanej przez wskaznik

    const int& r2 = k;
    //error: assignment of read-only reference ‘r2’ r2 = 25;

    
    std::cout << k << "\n";

    //dlaczego jest tyle mozliwosci i ktora wybrac??
    //jezeli przekazywanie wartosci jest kosztowne to NIE przekazujemy ja przez wartosc
    //jezeli nie chcemy zmieniac wartosci to przekazujemy przez const reference
    //jezeli chcemy zmienic wartosc to przekazujemy przez reference
    // czasami wstawienie jednego & program moze dzialac duzo szybciej

    printer() << "Hello World!\n";



    std::vector<int> v = {1,2,3};
    std::vector<int> w = {4,5,6};
    // te dwie * * to sa dwie rożne funkcje 
    std::cout << v * w << "\n";
    std::cout <<2*3 <<"\n";
    //przeciazenie <<
    std::cout << v << "\n";
    //error: no match for ‘operator*’ (operand types are ‘std::vector<int, std::allocator<int> >’ and ‘std::vector<int, std::allocator<int> >’)
    std::cout << "ala\n"<< 9 << &v << "\n";
    std::cout << silnia(5) << "\n";



    return 0;
}