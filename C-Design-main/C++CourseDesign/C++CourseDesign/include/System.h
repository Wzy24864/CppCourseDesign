#pragma once
#include "Book.h"
#include "Student.h"
#include "BorrowRecord.h"
#include "Times.h"
#include <vector>
#include <fstream>
#include <string>

class System
{
private:
    std::vector<BorrowRecord> records;
    std::vector<Book> books;
    std::vector<Student> students;

    void loadBooks();      // 读book.txt
    void loadRecords();    // 读record.txt
    void loadStudents();   // 读student.txt
    void saveBooks();      // 写book.txt
    void saveRecords();    // 写record.txt
    void saveStudents();   // 写student.txt

public:
    System();
    ~System();

    // 五大功能
    void newBookEnter();              // 1.新进图书录入
    void manageBook();                // 2.图书查询、修改、删除
    void borrowBook();                // 3.办理借书
    void returnBook();                // 4.办理还书
    void deleteRecord();              // 5.删除借阅信息 

    // 全部保存接口
    void save();
};