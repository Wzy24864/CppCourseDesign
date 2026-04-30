#include "System.h"
using std::cin;
using std::cout;
using std::string;

void printConsole() {
    cout << "\n===== 欢迎使用图书管理系统! =====\n";
    cout << "1.新进图书信息的录入\n";
    cout << "2.更改图书信息\n";
    cout << "3.办理借书手续\n";
    cout << "4.办理还书手续\n";
    cout << "5.删除借阅信息\n";
    cout << "6.保存文件\n";
    cout << "7.查看帮助文档\n";
    cout << "8.退出程序\n";
    cout << "请输入数字以继续:";
}

int main() {
    System sys;
    string m = "NULL";
    while (true) {
        printConsole();
        cin >> m;
        cin.ignore();
        if (m.size() == 1 && ('1' <= m[0] && m[0] <= '8')) {
            int op = stoi(m);
            switch (op) {
            case 1:
                sys.newBookEnter();
                break;
            case 2:
                sys.manageBook();
                break;
            case 3:
                sys.borrowBook();
                break;
            case 4:
                sys.returnBook();
                break;
            case 5:
                sys.deleteRecord();
                break;
            case 6:
                sys.save();
                break;
            case 7:
                cout << "正在打开帮助文档...\n";
                system("start Readme.md");
                break;
            case 8:
                cout << "感谢您的使用！程序即将退出。\n";
                return 0;
            }
        }
        else {
            cout << "输入内容有误，请输入1-8的数字!\n";
        }
    }
}