#pragma once
#include "Times.h"
#include "Book.h"
#include "Student.h"
using std::string;
enum RecordStatus {
    LEND = 1,
    RETURN = 0,
    OVERTIME = -1
};

class BorrowRecord
{
private:
    string bookId;
    string borrower;
    Student stu;
    Time outDate;
    Time dueDate;
    RecordStatus status;
public:
    BorrowRecord(string bookId, string& bor, Student& stu, Time& out, Time& due);
    void display();

    string getBookId();
    RecordStatus getStatus();
    void setStatus(RecordStatus s); 
    Student& getStudent();
    string getBorrower();
};