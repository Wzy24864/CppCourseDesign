#include "BorrowRecord.h"

using std::string;
using std::cout;
BorrowRecord::BorrowRecord(string bookId, string& bor, Student& stu, Time& out, Time& due) :
    bookId(bookId), borrower(bor), stu(stu), outDate(out), dueDate(due), status(LEND) {}
void BorrowRecord::display() {
    cout << "借书信息:";
    stu.display();
    cout << "\n归还状态:";
    if (status == LEND) cout << "LEND";
    else if (status == RETURN) cout << "Returned";
    else if (status == OVERTIME) cout << "OverTime(Unreturned)";
    cout << "\n";
}
string BorrowRecord::getBookId() { return bookId; }
RecordStatus BorrowRecord::getStatus() { return status; }
void BorrowRecord::setStatus(RecordStatus s) { status = s; }
Student& BorrowRecord::getStudent() { return stu; }
string BorrowRecord::getBorrower() { return borrower; }