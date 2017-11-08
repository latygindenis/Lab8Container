/*
 * Для встроенного типа и класса из лабораторной работы №1 провести
 * временной анализ заданных шаблонных классов на основных операциях:
 * добавление, удаление, поиск, сортировка.
 * Использовать итераторы для работы с контейнерами. Для получения времени выполнения
 * операции засекать системное время начала и окончания операции и автоматически
 * генерировать большое количество данных.
 * Вариант 8:
 * Cписок, словарь с дубликатами
 */

#include <iostream>
#include <list>
#include <iterator>
#include <ctime>
#include "books.h"
#include <vector>

int main() {

    srand(static_cast<unsigned int>(time(NULL)));
    unsigned int timer_begin=0, timer_end=0;
    Books myBook("Dotoevsky", 135, 50);

    list<int> list0, list1, list2;
    list<Books> myListBook0, myListBook1, myListBook2;

    cout<<"list <int> add element  to end time: "<<endl;
    timer_begin = static_cast<unsigned int>(clock());
    for(int i = 0; i < 50000; i++) {
        list0.push_back(rand()%1000); // добавляем в список новые элементы
    }
    cout<<"(50000) "<<clock()-timer_begin<< "ms"<<endl;

    timer_begin = static_cast<unsigned int>(clock());
    for(int i = 0; i < 500000; i++) {
        list1.push_back(rand()%1000); // добавляем в список новые элементы
    }
    cout<<"(500000) "<<clock()-timer_begin<< "ms"<<endl;

    timer_begin = static_cast<unsigned int>(clock());
    for(int i = 0; i < 5000000; i++) {
        list2.push_back(rand()%1000); // добавляем в список новые элементы
    }
    cout<<"(5000000) "<<clock()-timer_begin<< "ms"<<endl;
    cout<<endl;


    cout<<"list <Books> add element to end time: "<<endl;
    timer_begin = static_cast<unsigned int>(clock());
    Books *pv;
    for(int i = 0; i < 50000; i++) {
        pv = new Books("test", rand()%1000, rand()%1000);
        myListBook0.push_back(*pv); // добавляем в список новые элементы
    }
    cout<<"(50000) "<<clock()-timer_begin<< "ms"<<endl;

    timer_begin = static_cast<unsigned int>(clock());
    for(int i = 0; i < 500000; i++) {
        pv = new Books("test", rand()%1000, rand()%1000);
        myListBook1.push_back(*pv); // добавляем в список новые элементы
    }
    cout<<"(500000) "<<clock()-timer_begin<< "ms"<<endl;

    timer_begin = static_cast<unsigned int>(clock());
    for(int i = 0; i < 5000000; i++) {
        pv = new Books("test", rand()%1000, rand()%1000);
        myListBook2.push_back(*pv); // добавляем в список новые элементы
    }
    cout<<"(5000000) "<<clock()-timer_begin<< "ms"<<endl;




//    list<Books>::iterator it; //вывод элементов списка типа Books
//    it = myListBook0.begin();
//    while (it != myListBook0.end())
//    {
//        it->print();
//        it++;
//    }




    cout<<endl;
    cout<<"list0 sort time: "<<endl;

    timer_begin = static_cast<unsigned int>(clock());
    list0.sort();
    cout<<"(50000) "<<clock()-timer_begin<< "ms"<<endl;

    timer_begin = static_cast<unsigned int>(clock());
    list1.sort();
    cout<<"(500000) "<<clock()-timer_begin<< "ms"<<endl;

    timer_begin = static_cast<unsigned int>(clock());
    list2.sort();
    cout<<"(5000000) "<<clock()-timer_begin<< "ms"<<endl;



    //copy(list0.begin(), list0.end(), ostream_iterator<int>(cout," "));
    //copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout," ")); // вывод на экран элементов списка

    return 0;
}