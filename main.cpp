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

typedef multimap <char *, long, less <string> > map_s1; // Для удобства чтения
typedef multimap <Books, int, less <Books> > map_book;

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    unsigned int timer_begin=0;

    map_s1 m1;
    map_s1::iterator iter;

    char *str;
    str = new char[4];
    str[0]='z'; str[1]='x'; str[2]='y'; str[3]='z';str[4]='f'; str[5] = '\0';
    map_book m2;
    map_book::iterator iter1;

    m2.insert(make_pair(Books("Joker", 77, 88), rand()%100));
    m2.insert(make_pair(Books("Joker", 77, 99), rand()%100));
    m2.insert(make_pair(Books("Joker", 77, 10), rand()%100));
    iter1 = m2.begin();
    Books myBook("sss", 125, 57);

    for (map_book::iterator itw = m2.begin();  itw != m2.end(); itw++)
    {
       itw->first.print();
        cout<<" "<<itw->second<<endl;
    }


    timer_begin = static_cast<unsigned int>(clock());
    for (int i=0; i<500000; i++)
    {
        m1.insert(make_pair(randomString(5), 100000+rand()%999999));
    }
    cout<<"Multimap <char*, long> add (sort) element to end time: "<<clock()-timer_begin<< "ms"<<endl;

    timer_begin = static_cast<unsigned int>(clock());
    m1.insert(make_pair(str, 456975));
    m1.insert(make_pair(str, 456977));
    m1.insert(make_pair(str, 476975));
    cout<<"Multimap <char*, long> insert elements: "<<clock()-timer_begin<< "ms"<<endl;

    timer_begin = static_cast<unsigned int>(clock());
    for (map_s1::iterator itw = m1.equal_range(str).first;  itw != m1.equal_range(str).second; itw++)
    {
        cout<<itw->first<<" "<<itw->second<<endl;
    }
    cout<<"Multimap <char*, long> find by key element: "<<clock()-timer_begin<< "ms"<<endl;

    timer_begin = static_cast<unsigned int>(clock());
    cout<<"Deleted: "<<m1.erase(str)<<" elements"<<endl;
    cout<<"Multimap <char*, long> delete element: "<<clock()-timer_begin<< "ms"<<endl;


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


    timer_begin = static_cast<unsigned int>(clock());
    list0.sort();
    cout<<"list0 sort time: (500000) "<<clock()-timer_begin<< "ms"<<endl;


    for(int i = 0; i < 10; i++) {
        pv = new Books(randomString(10), rand()%1000, rand()%1000);
        myListBook1.push_back(*pv); // добавляем в список новые элементы
    }

    timer_begin = static_cast<unsigned int>(clock());
    find_intlist(list0, 500);
    cout<<"Time list0 find value: "<<clock()-timer_begin<< "ms"<<endl;

    timer_begin = static_cast<unsigned int>(clock());
    find_booklist(myListBook0, 100);
    cout<<"Time myBookList0 find value: "<<clock()-timer_begin<< "ms"<<endl;
    return 0;
}