#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 生成随机数
int generateRandomNumber(int maxNum) {
    return rand() % maxNum + 1;
}

// 生成四则运算题目
string generateOperation(char op, int maxNum, bool withParentheses, bool withDecimal) {
    int num1 = generateRandomNumber(maxNum);
    int num2 = generateRandomNumber(maxNum);
    string operation;

    if (op == '/') {
        while (num2 == 0) {
            num2 = generateRandomNumber(maxNum);
        }
    }

    if (withParentheses) {
        operation += "(";
    }

    operation += to_string(num1) + " " + op + " " + to_string(num2);

    if (withParentheses) {
        operation += ")";
    }

    if (withDecimal && op == '/') {
        operation += " = " + to_string((float)num1 / num2);
    }
    else {
        operation += " = ";
        switch (op) {
        case '+':
            operation += to_string(num1 + num2);
            break;
        case '-':
            operation += to_string(num1 - num2);
            break;
        case '*':
            operation += to_string(num1 * num2);
            break;
        case '/':
            operation += to_string(num1 / num2);
            break;
        }
    }

    return operation;
}

int main() {
    srand(time(0));

    int numExercises, maxNum;
    char op;
    bool withParentheses, withDecimal;
    string outputType;

    cout << "请输入题目数量：";
    cin >> numExercises;
    cout << "请选择运算符（+、-、*、/）：";
    cin >> op;
    cout << "设置最大数：";
    cin >> maxNum;
    cout << "是否有括号（1为是，0为否）：";
    cin >> withParentheses;
    cout << "是否有小数（1为是，0为否）：";
    cin >> withDecimal;
    cout << "请选择输出方式（文件、打印机等）：";
    cin >> outputType;

    ofstream outputFile;
    if (outputType == "文件") {
        outputFile.open("exercises.txt");
    }

    for (int i = 0; i < numExercises; i++) {
        string exercise = generateOperation(op, maxNum, withParentheses, withDecimal);
        cout << exercise << endl;
        if (outputType == "文件") {
            outputFile << exercise << endl;
        }
    }

    if (outputType == "文件") {
        outputFile.close();
        cout << "题目已输出到exercises.txt文件中" << endl;
    }

    return 0;
}