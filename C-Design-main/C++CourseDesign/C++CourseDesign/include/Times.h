#pragma once
#include <iostream>
class Time
{
private:
    int year;
    int month;
    int day;
public:
    Time(int y, int m, int d);
    Time() : year(0), month(0), day(0) {}  // 默认构造函数
    void print();

    // 文件读写需要的 getter
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
};