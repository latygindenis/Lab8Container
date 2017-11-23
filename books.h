//
// Created by Денис on 08.11.2017.
//

#include <iostream>
#include <string.h>
#include <fstream>

#ifndef LAB8CONTAINER_BOOKS_H
#define LAB8CONTAINER_BOOKS_H

using namespace std;
class Books
{
    char *name;
    int num_page;
    int amount;
public:
    /*-------------------Конструкторы------------------------*/
    Books(char *name_book, int num_page_book, int amount_book);
    Books(const char name_book[], int num_page_book, int amount_book);
    Books(const Books &book);
    Books();

    /*-------------------Перегруженные операторы-------------*/
    Books operator + (Books books);
    Books & operator = (Books &books);
    Books  operator ++ (int); //постфиксная форма
    Books & operator ++ (); //префиксная форма
    operator float() const;
    friend Books operator - (Books one, Books two);
    bool operator > (Books two);
    bool operator < (Books two);

    //friend ostream& operator << (ostream& os, Books &book);
    friend istream& operator >> (istream& is, Books &book);

    /*-------------------Методы-----------------------------*/
    void write(ofstream &os);
    void read(ifstream &is);
    int get_amount(); // геттер amount
    int getNum_page() const;
    char *getName() const;
    void setdata(char *name_book, int num_page_book, int amount_book);
    void enterdata();
    virtual void print() const ;
    virtual char *getdefinition() const;
    virtual ~Books();
};

class AboutBook : public Books
{
    char *description;
public:
    char *getDescription() const;

public:
    AboutBook();// Констрктор по умолчанию
    AboutBook(const AboutBook &myAboutBook); //Конструктор копирования
    AboutBook(const char *name_book, int num_page_book, int amount_book, const char mydescription[]);//конструктор с параметрами
    void print();
    char *getdefinition() const;
    ~AboutBook();
};

class NumBook : public Books
{
    int number;
public:
    NumBook(); //Конструктор по умолчанию
    NumBook(const NumBook &myNumBook); //Конструктор копирования
    NumBook(const char name_book[], int num_page_book, int amount_book, int myNumber); // Конструктор с параметрами
    void print();
    char *getdefinition() const;
};
ostream  &operator << (ostream& os, Books &book);

#endif //LAB8CONTAINER_BOOKS_H
