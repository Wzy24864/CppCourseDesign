#include "Book.h"
using std::string;
using std::cout;
Book::Book(string &n, string id, double pr, string &au, int s):
name(n), id(id), price(pr), author(au), stock(s) {}
void Book::display() {
    cout << "\n以下是图书信息:\n书名:" << name 
    << "\t图书编号" << id
    << "\t价格:" << price 
    << "\n\t作者:" << author
    << "\t剩余书本个数:" << stock;
}
void Book::setStock(int s) { stock = s; }
void Book::setName(string& n) { name = n; }
void Book::setPrice(double p) { price = p; }
void Book::setAuthor(string& a) { author = a; }
void Book::setId(string i) { id = i; }
double Book::getPrice() { return price; }
string Book::getAuthor() { return author; }
int Book::getStock() { return stock; }
string Book::getName() { return name; }
string Book::getId() { return id; }
