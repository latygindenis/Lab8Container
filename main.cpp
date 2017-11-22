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
#include <utility>
#include <iostream>
#include <list>
#include <iterator>
#include <ctime>
#include "books.h"
#include <map>

char * randomString (int sybols = 3)
{
    char *str;
    str = new char [sybols+1];
    for (int i = 0; i < sybols; i++)
    {
        str [i]  = static_cast<char>(100 + rand() % 10);
    }
    str[sybols] = '\0';
    return str;
}

list<int>::iterator find_intlist (list <int> &a, int value)
{
    list<int>::iterator it;
    it = a.begin();
    for (it; it!=a.end(); it++)
    {
        if (*it == value)
        {
            cout<<"Found "<<value<<" in list<int> on place:"<<it._M_node<<endl;
            return it;

        }
    }
    cout<<"Not found "<<value<<" in list<int>"<<endl;
}
list<Books>::iterator find_booklist (list <Books> &a, int num_page = -1, int amount = -1)
{

    list<Books>::iterator it;
    it = a.begin();
    for (it; it != a.end(); it++)
    {
        if (it->get_amount() == amount && it->getNum_page() == num_page)
        {
            cout<<"Found amount: "<<amount<<" and num_page: "<<num_page<<" in list<Books> on place:"<<it._M_node<<endl;
            return it;
        }
        if (amount == -1 && it->getNum_page() == num_page)
        {
            cout<<"Found "<<"num_page: "<<num_page<<" in list<Books> on place:"<<it._M_node<<endl;
            return it;
        }
        if (num_page == -1 && it->get_amount() == amount)
        {
            cout<<"Found amount: "<<amount<<" in list<Books> on place:"<<it._M_node<<endl;
            return it;
        }
    }
    cout<<"Nothing found in list<Books>"<<endl;
}

typedef map <string, long, less <string> > map_s1;

int main() {

//    pair<int, double> pi(10, 12.3),  p2(20, 12.3);
//
//    cout << "pi: " << pi.first << " " << pi.second << endl;
//    cout << "p2: " << p2.first << " " << p2.second << endl;
//    p2.first -= 10;
//    if (pi == p2) cout << "pi == p2\n";
//    pi.second -= 1;
//    if (p2 > pi) cout << "p2 > pl\n";



    srand(static_cast<unsigned int>(time(NULL)));
    unsigned int timer_begin=0;

    list<int> list0, list1, list2;
    list<Books> myListBook0, myListBook1, myListBook2;





    cout<<"list <int> add element  to end time: ";
    timer_begin = static_cast<unsigned int>(clock());
    for(int i = 0; i < 500000; i++) {
        list0.push_back(rand()%1000); // добавляем в список новые элементы
    }
    cout<<"(500000) "<<clock()-timer_begin<< "ms"<<endl;

    cout<<"list <Books> add element to end time: ";
    timer_begin = static_cast<unsigned int>(clock());
    Books *pv;
    for(int i = 0; i < 500000; i++) {
        pv = new Books(randomString(10), rand()%1000, rand()%1000);
        myListBook0.push_back(*pv); // добавляем в список новые элементы
    }
    cout<<"(500000) "<<clock()-timer_begin<< "ms"<<endl;

    list<Books>::iterator new_it; // Добавление по номеру
    new_it = myListBook0.begin();

    timer_begin = static_cast<unsigned int>(clock());
    for(int i = 0; i<250000; i++)
    {
        new_it++;
    }
    myListBook0.insert(new_it, Books("test_test", 25, 45));
    cout<<"Add <Book> to 250000: "<<clock()-timer_begin<< "ms"<<endl;

    list<int>::iterator new_it1;
    new_it1 = list0.begin();

    timer_begin = static_cast<unsigned int>(clock());
    for(int i = 0; i<250000; i++)
    {
        new_it1++;
    }
    list0.insert(new_it1, 100);
    cout<<"Add <int> to 250000: "<<clock()-timer_begin<< "ms"<<endl;


    new_it = myListBook0.begin();

    timer_begin = static_cast<unsigned int>(clock());
    for(int i = 0; i<250000; i++)
    {
        new_it++;
    }
    myListBook0.erase(new_it);
    cout<<"Delete <int> from 250000: "<<clock()-timer_begin<< "ms"<<endl;

    new_it1 = list0.begin();

    timer_begin = static_cast<unsigned int>(clock());
    for(int i = 0; i<250000; i++)
    {
        new_it1++;
    }
    list0.erase(new_it1);
    cout<<"Delete <Books> from 250000: "<<clock()-timer_begin<< "ms"<<endl;


//    list<int>::iterator it; //вывод элементов списка типа int
//    it = list0.begin();
//    copy(it, list0.end(), ostream_iterator<int>(cout, "\n"));


    timer_begin = static_cast<unsigned int>(clock());
    list0.sort();
    cout<<"list0 sort time: (500000) "<<clock()-timer_begin<< "ms"<<endl;



    for(int i = 0; i < 10; i++) {
        pv = new Books(randomString(10), rand()%1000, rand()%1000);
        myListBook1.push_back(*pv); // добавляем в список новые элементы
    }

//    myListBook1.sort();
//    new_it  = myListBook1.begin();
//    while (new_it!=myListBook1.end())
//    {
//        new_it->print();
//        new_it++;
//    }

    timer_begin = static_cast<unsigned int>(clock());
    find_intlist(list0, 500);
    cout<<"Time list0 find value: "<<clock()-timer_begin<< "ms"<<endl;

    timer_begin = static_cast<unsigned int>(clock());
    find_booklist(myListBook0, 100, 785);
    cout<<"Time myBookList0 find value: "<<clock()-timer_begin<< "ms"<<endl




    //copy(list0.begin(), list0.end(), ostream_iterator<int>(cout," "));
    //copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout," ")); // вывод на экран элементов списка

    return 0;
}