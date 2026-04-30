#pragma once
#include <iostream>
using std::string;
class Book
{
private:
    string name;
    string id;
    double price;
    string author;
    int stock;
public:
    Book(string& n, string id, double pr, string& au, int s);
    void display();

    // getter/setter

    void setStock(int s);
    void setName(string& n);
    void setPrice(double p);
    void setAuthor(string& a);
    void setId(string n);
    double getPrice();
    string getAuthor();
    int getStock();
    string getId();
    string getName();
};