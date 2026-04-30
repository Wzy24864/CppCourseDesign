#include "Times.h"
using std::cout;
Time::Time(int y, int m, int d):year(y), month(m), day(d){}
void Time::print() {
    cout << year << "Äê" << month << "ÔÂ" << day << "ÈÕ";
}