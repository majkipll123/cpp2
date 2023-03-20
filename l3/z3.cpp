#include <bits/stdc++.h>
#include <cstdlib>
 
//tworzy strukture node, ktora zawiera wartosc i wskaznik na nastepny element
struct Node {
    int data;
    struct Node* next;
    //konstruktor ktory ustawia wartosc i wskaznik na nullptr
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

struct List {
    Node* head;
    List() { head = nullptr; }
 
    //funkcja do odwrocenia listy
    void reverse()
    {
        //inicjalizacja wszystkich pointerow, poprzedniego obecnego i nastepnego
        Node* current = head;
        Node *prev = nullptr, *next = nullptr;
        // node * i node* to to samo

        while (current != nullptr) {
            // przechowanie nastepnego elementu
            next = current->next;
            // odwracanie obecnego pointera w lewo 
            current->next = prev;
            // przesuwanie pointera do przodu o 1
            prev = current;
            current = next;
        } 
        //ustawanie ostatniej wartosci jako head
        head = prev;
    }
 
    //funkcja do printowania list na ekranie 
    void print()
    {
        struct Node* temp = head;
        while (temp != nullptr) {
            //printowanie kolejnych elementow oddzielonych spacja 
            std::cout << temp->data << " ";
            temp = temp->next; 
        }
    }
    //funkcja ktora ustawia nowy element 
    void add(int data)
    {
        Node* temp = new Node(data); //tworzenie nowego elementu
        temp->next = head;  //ustawien
        head = temp;   
    }
};
 

int main()
{
    
    List lista;
    //tworzenie listy losowych elementow
    for (int i=0; i<100;i++)
    {
        lista.add(rand());
    }
    
    std::cout << "lista podana przez uzytkownika \n";
    lista.print();//printowanie listy
 
    lista.reverse();//odwrocenie listy
    
    std::cout << "\nodwrocona lista  \n";
    lista.print();//printowanie listy odwroconej
    std::cout<<'\n';
    return 0;
}