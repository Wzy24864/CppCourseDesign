#include "System.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::vector;
using std::stringstream;

// System入口，读取文件books.txt students.txt records.txt
System::System() {
    loadBooks();
    loadStudents();
    loadRecords();
}

// 在程序结束时自动保存文件
System::~System() {
    save();
}

// 文件读取
void System::loadBooks() {
    ifstream fin("books.txt");
    if (!fin) return;

    books.clear();
    string name, id, author;
    double price;
    int stock;

    while (getline(fin, name)) {
        if (name.empty()) continue;
        getline(fin, id);
        fin >> price;
        fin.ignore();
        getline(fin, author);
        fin >> stock;
        fin.ignore();

        Book b(name, id, price, author, stock);
        books.push_back(b);
    }
    fin.close();
}

void System::loadStudents() {
    ifstream fin("students.txt");
    if (!fin) return;

    students.clear();
    string name, id;
    while (getline(fin, name)) {
        if (name.empty()) continue;
        getline(fin, id);
        Student s(name, id);
        students.push_back(s);
    }
    fin.close();
}

void System::loadRecords() {
    ifstream fin("records.txt");
    if (!fin) return;

    records.clear();
    string bookId;
    int y1, m1, d1, y2, m2, d2, st;
    string borrower, stuName, stuId;

    while (fin >> bookId) {
        fin.ignore();
        getline(fin, borrower);
        getline(fin, stuName);
        getline(fin, stuId);
        fin >> y1 >> m1 >> d1;
        fin >> y2 >> m2 >> d2;
        fin >> st;
        fin.ignore();

        Student stu(stuName, stuId);
        Time out(y1, m1, d1);
        Time due(y2, m2, d2);
        BorrowRecord rec(bookId, borrower, stu, out, due);
        records.push_back(rec);
    }
    fin.close();
}

// 文件保存
void System::saveBooks() {
    ofstream fout("books.txt");
    for (auto& b : books) {
        fout << b.getName() << '\n';
        fout << b.getId() << '\n';
        fout << b.getPrice() << '\n';
        fout << b.getAuthor() << '\n';
        fout << b.getStock() << '\n';
    }
    fout.close();
}

void System::saveStudents() {
    ofstream fout("students.txt");
    for (auto& s : students) {
        fout << s.getName() << '\n';
        fout << s.getId() << '\n';
    }
    fout.close();
}

void System::saveRecords() {
    ofstream fout("records.txt");
    for (auto& r : records) {
        fout << r.getBookId() << '\n';
        fout << r.getBorrower() << '\n';
        fout << r.getStudent().getName() << '\n';
        fout << r.getStudent().getId() << '\n';
       
    }
    fout.close();
}

// 新图书录入
void System::newBookEnter() {
    string name, id, author;
    double price;
    int stock;

    cout << "===== 新进图书录入 =====\n";
    cout << "书名: ";
    getline(cin, name);
    cout << "编号: ";
    getline(cin, id);

    // 检查编号是否重复
    for (auto& b : books) {
        if (b.getId() == id) {
            cout << "该编号已存在，录入失败！\n";
            return;
        }
    }

    cout << "价格: ";
    cin >> price;
    cin.ignore();
    cout << "作者: ";
    getline(cin, author);
    cout << "库存: ";
    cin >> stock;
    cin.ignore();

    Book newBook(name, id, price, author, stock);
    books.push_back(newBook);
    cout << "录入成功!\n";
}

// 图书查询的修改与删除
// 图书查询的修改与删除
void System::manageBook() {
    string keyword;
    cout << "===== 图书管理 =====\n";
    cout << "输入书名或编号搜索: ";
    getline(cin, keyword);

    // 查找匹配的图书
    vector<int> foundIndexes;
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getName().find(keyword) != string::npos ||
            books[i].getId().find(keyword) != string::npos) {
            foundIndexes.push_back(i);
        }
    }

    if (foundIndexes.empty()) {
        cout << "未找到匹配的图书!\n";
        return;
    }

    // 显示找到的图书
    for (int i = 0; i < foundIndexes.size(); i++) {
        cout << "\n[" << i + 1 << "]";
        books[foundIndexes[i]].display();
    }

    cout << "\n\n选择操作: 1-修改  2-删除  0-返回\n";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 0) return;

    cout << "输入新的图书编号: ";
    int idx;
    cin >> idx;
    cin.ignore();

    if (idx < 1 || idx > foundIndexes.size()) {
        cout << "无效序号!\n";
        return;
    }

    int realIdx = foundIndexes[idx - 1];

    if (choice == 1) {  // 修改
        string name, author, newId;
        double price;

        cout << "新书名(按回车跳过): ";
        getline(cin, name);
        if (!name.empty()) books[realIdx].setName(name);

        cout << "新编号(按回车跳过): ";
        getline(cin, newId);
        if (!newId.empty()) {
            // 检查新编号是否与其他图书重复
            bool duplicate = false;
            for (int i = 0; i < books.size(); i++) {
                if (i != realIdx && books[i].getId() == newId) {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate) {
                cout << "该编号已被其他图书使用，编号修改失败！\n";
            }
            else {
                books[realIdx].setId(newId);
                cout << "编号修改成功！\n";
            }
        }

        cout << "新价格(输入负数跳过): ";
        cin >> price;
        cin.ignore();
        if (price >= 0) books[realIdx].setPrice(price);

        cout << "新作者(输入回车跳过): ";
        getline(cin, author);
        if (!author.empty()) books[realIdx].setAuthor(author);

        cout << "修改完成!\n";
    }
    else if (choice == 2) {
        books.erase(books.begin() + realIdx);
        cout << "删除成功!\n";
    }
}
// 借书
void System::borrowBook() {
    string bookId, stuId, stuName;

    cout << "===== 办理借书 =====\n";
    cout << "图书编号: ";
    getline(cin, bookId);

    // 查找图书
    Book* book = nullptr;
    for (auto& b : books) {
        if (b.getId() == bookId) {
            book = &b;
            break;
        }
    }
    if (!book) {
        cout << "图书不存在!\n";
        return;
    }
    if (book->getStock() <= 0) {
        cout << "库存不足!\n";
        return;
    }

    cout << "借书人姓名: ";
    getline(cin, stuName);
    cout << "学号: ";
    getline(cin, stuId);

    // 查找或创建学生
    Student* stu = nullptr;
    for (auto& s : students) {
        if (s.getId() == stuId) {
            stu = &s;
            break;
        }
    }
    if (!stu) {
        Student newStu(stuName, stuId);
        students.push_back(newStu);
        stu = &students.back();
    }

    // 输入日期
    int y1, m1, d1, y2, m2, d2;
    cout << "借出日期(年 月 日): ";
    cin >> y1 >> m1 >> d1;
    cout << "应还日期(年 月 日): ";
    cin >> y2 >> m2 >> d2;
    cin.ignore();

    Time outDate(y1, m1, d1);
    Time dueDate(y2, m2, d2);
    BorrowRecord rec(book->getId(), stuName, *stu, outDate, dueDate);
    records.push_back(rec);

    book->setStock(book->getStock() - 1);

    cout << "借书成功!\n";
    rec.display();
}

// 还书
void System::returnBook() {
    string bookId, stuId;

    cout << "===== 办理还书 =====\n";
    cout << "图书编号: ";
    getline(cin, bookId);
    cout << "学号: ";
    getline(cin, stuId);

    // 查找借阅记录
    for (auto& r : records) {
        if (r.getBookId() == bookId.c_str() &&
            r.getStudent().getId() == stuId &&
            r.getStatus() == LEND) {
            r.setStatus(RETURN);

            // 库存+1
            for (auto& b : books) {
                if (b.getId() == bookId) {
                    b.setStock(b.getStock() + 1);
                    break;
                }
            }

            cout << "还书成功!\n";
            r.display();
            return;
        }
    }
    cout << "未找到对应的借阅记录!\n";
}

// 删除信息
void System::deleteRecord() {
    string bookId, stuId;

    cout << "===== 删除借阅信息 =====\n";
    cout << "图书编号: ";
    getline(cin, bookId);
    cout << "学号: ";
    getline(cin, stuId);

    for (auto it = records.begin(); it != records.end(); ++it) {
        if (it->getBookId() == bookId &&
            it->getStudent().getId() == stuId) {

            // 检查是否已归还，未归还的不允许删除
            if (it->getStatus() == LEND) {
                cout << "该图书记录未归还，无法删除！请先办理还书手续。\n";
                return;
            }

            records.erase(it);
            cout << "删除成功!\n";
            return;
        }
    }
    cout << "未找到对应的借阅记录!\n";
}

// 全部保存接口
void System::save() {
    saveBooks();
    saveRecords();
    saveStudents();
}