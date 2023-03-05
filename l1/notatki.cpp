cmake_minumum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED QT)
add_executable(zad1 main.cpp)
add_executable(zad21 zad2.cpp)
//uzywaj debuggera w programach to powodeuje ze program zatrzymuje sie na kropce
//mozna po zmiennych lokalnych ,dohodzenie do tego co i jak sie stalo w naszym porgramie
INNY PLIK
cpp reference com
#include <iostream>

int main()
{
int i=9;
i++;
i=i+10;
std::cout<<"hello\n";
return 0;}

//typy danych
pierwsza rzecz o ktorej trzeba pamietac
jezyk cpp nalezy do statycznie typowalnych jezykow
statycznie= w trakcie kompilacji
typowalnych= typ obiektu czy zmiennej musi byc znany w trakcie kompilacji
informacje o typie danych trzyma kompilator a w pythonie x= 1 x=1,23 x=kota
trzeba inicjator ale mozna tak zrobic
auto i = 0;
lub int i = 0;
int i (0); mozna tak robic lol
inicjalizator albo kosntruktor
int i{0};
nie zostawiamy zmiennych bez inicjalizatora
int i; ??? dziwne chyba ze zaraz wczytasz ją z pliku
bardzo rzadkie przypadki ze tego inicjalizatora czyli przypisania na nie ma
typy podstawowe
int i = 0;
long int j = 0; //na 32 bit int na 64 bit nie uslyszalem
long long int k = 0;//64 bity
short l = 0; //2 bajty
char m = 9;//liczba zxapisana na 8 bitach
int64_t p; // rzadamy zeby liczba miescila sie dokladnie na 64 bitach i byla od calkowitego
int16_t pp; //
unsigned int u; //

uint16_t yy23; // |1|1|1|1| 1*10^0+1*10^1+1*10^2+1*10^2

2 liczby dodatkie ktorych suma < 0  a liczba * liczba2 =0
// |0|1|0|0|*|0|1|0|0|
int i = 0x10000;// std out i da nam 65536 bo 2 do 16
i* i // da nam 0
//skad sie biora liczby ujemne?
//bit najstarszy ma wage ujemna          bit najmlodszy
                        |-2^3|2^2|2^1|2^0|

2^10=1024
10^3
2^64
2^4*2^60=16*(2^10)^6
16*(10^3^)^6=16*10^18

uklad szestansto=kowy
int i = 0xFFFFFFF; 15^16^0+15*16^1+15*16*2+15*16^3 // to bedzie 2miliardy, najwieksza liczba typu int  a suma bedzie i+i = -2
//f=15

auto i = 0; odczyta zero i ustawi jej typ na int ale dopisanie u po 0 daje ze i jest typu unsigned a dopisanie l daje using long


int k = 3;
int n = 8;

auto wynik = k/n; // wynik bedzie 0 dlatego ze popatrzy na dzielenie i z lewej strony int z prawej int wiec musi byc int
//a jezeli zadeklarujemy jako dwa double to to dzielenie jest kierowane do innej elektroniki na innej czesci procesora
// inty
x= a & b 5 & 9=1//co to znaczy?x=0101   x=0101   x=0101  x=0101
a | b//mnozenie po komorkach & y=1001  |y=1001  ^y=1001  y=1001
     5 ^ 9          //           0001     1101     1100
| to robi ze prawda lub falsz, jezeli jedno jest prawda to prawda jezeli dwa sa prawda to prawda jezeli dwa sa falsz to falsz
& and | or ^ czy rózne, 1 i 0 daje 1, 0 i 0 daje 0, 1 i 1 daje 0
//negacja ~x 1011 = 0100 odwraca po prostu 0 na 1 1 na 0
//operator przesuniecia bitowego  x<<1 przesuniecie o jeden w lewo 1011 << 1|0110| a w prawo to samo tylko >>
// 1011 zamienia na 0101|1



















