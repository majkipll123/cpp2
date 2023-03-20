#include <iostream> 
//size_t jest uzywane jest do array indexing and loop counting 
struct Link
{
    int value; 
    Link* next = nullptr;

};
//funkcja do zwolnienia pamieci
void release(Link** phead) 
{
    Link* head = *phead;
    //nullptr znaczy null pointer, czyli pusta wartosc wskaznika
    while (head != nullptr)
    {
        Link* tmp = head;
        head = head -> next;
        delete tmp;
    
    }
    *phead = nullptr;
}
//funkcja ktora liczy dlugosc poprzez wskazniki
size_t sizea(const Link* head)
{
    size_t count = 0;
    while (head != nullptr) //dopóki wartosc nie jest równa to program dodaje 1 do count
    {
        ++count; //lub count++
        head = head->next;//przejscie do kolejnej skladowej
    }
    return count;

}
//funkcja która sumuje wartosc wektora poprzez wskazniki
size_t sum(const Link* head)
{
    size_t sum = 0;
    while (head != nullptr)
    {
        sum += head->value;//przypisanie wartosci do sumy i dodanie do niej
        head = head->next; // przejscie do kolejnej skladowej
    }
    return sum;

}
int main()
{
    Link* head = new Link{ 1, new Link{ 2, new Link{ 3, new Link{ 4, new Link{ 5, nullptr } } } } };
    std::cout << "size: " << sizea(head) << std::endl;
    std::cout << "sum: " << sum(head) << std::endl;
    return 0;
}