#include <iostream>
using namespace std;

int main()
{

// jezeli nie ma powodu zeby uzyc float nie uzywamy float
// dobule 99% przyoadkow wykozystywanie liczb zmienno pozycyjnych
// l całkowita * l całkowita iloczyn przekracza zakres i kwadrat liczb moze sie rownac zero
// float i double
float a= (1.0/3.0)+(1.0/3.0)+(1/3);
cout<<a<<endl;
// float reprezentacja 32 bitowa? nauczyc sie ile bitow ma jaki typ danych, skonczona liczba danych na ktorych mozemy zapisac liczby rzeczywiste
// i oczywiste jest to ze nie da sie zapisac wszystkich liczb na 32 bitach
//liczby wymierne ktore majaa w mianowniku potege 2 mozemy reprezentowac dokladnie i liczby calkowite o ile nie sa bardzo duze a reszta liczb jest przyblizona
//w komputerze zero moze byc ujemne
//emantysa to jest ulamek a exponenta to jest wykladnik
//liczby sa zapisywane w postaci jakies tam 1.37E7 e to jest exponent czyli wykladnik a na procesorze z 10 robimy 2 i 1.37 *2^7 1.1101*2^7 dwa jedna drugha jedna czwarta bez jednej usmej i jedna szesnasta
// 7 ma trzy jedynki
//1.11 *(10)^10 = (1+1/2+1/4)*4=7/4*4=7 znak * ułamek * 2 ^ wykładnik
//1.0+e=1E-20=1 //zaczac sumowac od malych nie od duzych bo trzeba zaokraglac coraz bardziej i błąd bedzie narastał bo mała do małej bedzie sie ladnie dodawac a z duzej trzeba duzo oszacowac,
// poniwaz z jednej zx nich trzeba odciąć bity i narasta błąd
//KOLEJNOSC DODAWANIA JEST WAZNA ZEBY ZACZYNAC OD NAJMNIEJSZYCH LICZB  a+b+c w matematyce wynik jest taki sam nie zaleznie co (a+b)+c=a+(b+c) ale w komputerze nie
//1+(-1)+1E-20=0+1E-20=1e-20 ale 1+((-1)+1E-20)=0 to sie nazywa hmm anulowanie  hmhmhm skladnikow ? jak se przypomne to wam powiem
//1/3=0.3333 - 0.3300=0.0033=
//(4/3)3.3333*10^0-(3.33)3.3300^10^0=3.3*10^-3 wieksza dolkadnosc mialoby wiecej 3.33333333 bo 4/3 byloby 3.3333333333333
// float uzywa sie poza zajeciami nigdzie, bicie glowa w sciane, tylko wtedy kiedy urzadzenie nie obsluguje niczego innego
//float 32 dobule 64 long dougle 80 bitow
// a/b gdzie a to int b to char -> oba argumenty musza byc w tym samym typie
// mnozenie 2*n n typu int = wszystko sie zgadza= wynik bedzie int double x =3/4 x=0 ale 3.0/4.0 dziala
cout<<'a'+1<<endl;
cout<<char('a'+1)<<endl;
cout<<char('abc'+1)<<endl;
unsigned n=1;
if (n>-1)
cout<<"ominiecie poniewaz -1 zamienane na typ unsigned"<<endl;
// jak pracujemy na bitach tryb usigned a tak to nie
// | suma bitowa
// a=b=c wszystko dziala
// if(a==1)
// dodawanie na iczbach calkowitych jest traktowanei zupelnie inaczej, inna elektronika wynikuje int + int a inna double +double
// ale róznie bywa, jeden w całkowitym drugi w zienno pozycyjnmy
//64 albo 32 bity, inna instrukcja w assemblerze
// 4*n wynik jest calkowity 4.0*n= zawsze upodnosimy do typów bardziej pojemnych dlatego mamy konwercje typu danych

//2 wyklad 
//tablice ? po co sa tablice , tablice to jest zmienna ktora moze przechowywac wiele wartosci w jednym miejscu 
// potrzebujemy nie tylko zmiennych ale i duzych wartowsci pamieci zeby przechowytwac dane w 1 miejscu
// tablice definiuje sie tak int tab[6];
int tab[6] = {1,2,3,4,5,6}; //mozna podac mniej liczb niz rozmiar tablicy 
std::cout<<tab[2]<<"\n";
// tab[20] tez sie kompiluje ale wyskakuje jakas dziwna liczba poniewaz wychodzimy poza zakres tablicy i zczytujemy pamiec z poza tablicy poniewaz gdzies ta pamiec jest wypelniona
char tabl[6] = {'a','b','c','d','z','f'};// na koncu tablicy kompilator dopisze bajt zerowy czyli \0 i wypisze nam a b c d e \0 ale polskie litery nie mieszcza sie w tablicy asci 
std::cout<<tabl[5]<<"\n";
std::cout<<tabl[4]<<"\n";
//wzkaźniki to jest zmienna ktora przechowuje adres pamieci w ktorej jest jakas zmienna 
// nazwy pamieci sa unikalne i nie mozna ich zmieniac: takie jak heap stack i data segment stack to jest miejsce gdzie sa przechowywane zmienne lokalne i parametry funkcji 
//stack moze byc tylko jedna i jest na gorze pamieci, heap to jest miejsce gdzie sa przechowywane zmienne globalne i dynamiczne, data segment to jest miejsce gdzie sa przechowywane zmienne globalne statyczne
// ta pamiecia zarządza kompilator 
// romiar stack to jest 1mb i jest na gorze pamieci
// a rozmiar heap to jest 2gb i jest na dole pamieci
//zeby operowac na pamieci heap trzeba uzyc wskaźników 
//wskaznik to jest taka zmienna gdzie mamy bufor pameci ktorego mozemy uzywac 
// jak definiuje sie wskazniki?
int b = 10;
int* p = &b; //p to jest wskaznik do zmiennej n
//int *p to juz nie jest adres tylko liczba  
// &n to jest adres zmiennej n
// int* p to jest deklaracja ze ta zmienna to pointer 
int** pp = &p; //pp to jest wskaznik do wskaznika


return 0;
}
