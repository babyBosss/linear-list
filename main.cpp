//
//  main.cpp
//  lab14
//
//  Created by Alex on 03.12.2019.
//  Copyright © 2019 Alex. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
 
 
using namespace std;

typedef struct elem* elemInd ;
 
 
struct elem{
  int value;
  elemInd next;
};

void Insert(elemInd L, elemInd E, elemInd E1){
 
 elemInd current;
 elemInd e;
 int v,v1;
  v = E -> value;
  v1 = E1 -> value;
  current = L;
   while (current){
    if (current -> value == v){
      e = new elem();
      e -> value = v1;
           e -> next = current -> next;
      current -> next = e;
    }
    current = current -> next;
  }
}
int main(int argc, char** argv){
    
    setlocale(LC_ALL, "RU");
    
    elemInd first = NULL;
    elemInd* pointer = &first;
    cout << "Введите построчно элементы списка\n";
    for (int n=1; n<=15; ++n){
        
        *pointer = new elem;
        cin >> (*pointer)->value;
        pointer = &(*pointer)->next;
    }
    *pointer = NULL;
    cout << "Начальный список\n";
    elemInd p = first;
    while (p){
        cout << p -> value << " ";
        p = p -> next;
    }
    cout << "\n";
    
    elemInd ind1 = new elem;
    int n;
    cout << "\nВведите элемент E: "; cin >> n;
    ind1 -> value = n;
    elemInd ind2 = new elem;
    cout << "\nВведите элемент E1: "; cin >> n;
    ind2 ->value = n;
    p = first;
    Insert(p, ind1, ind2);
 
    p = first;
    cout <<"\n";
    while (p){
        cout << p->value << ' ';
        p = p->next;
    }
    cout << "\n";
    while (first){
        elemInd v = first;
        first = first -> next;
        delete v;
    }
  
return 0;
}
