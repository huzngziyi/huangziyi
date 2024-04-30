#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// ���������
int generateRandomNumber(int maxNum) {
    return rand() % maxNum + 1;
}

// ��������������Ŀ
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

    cout << "��������Ŀ������";
    cin >> numExercises;
    cout << "��ѡ���������+��-��*��/����";
    cin >> op;
    cout << "�����������";
    cin >> maxNum;
    cout << "�Ƿ������ţ�1Ϊ�ǣ�0Ϊ�񣩣�";
    cin >> withParentheses;
    cout << "�Ƿ���С����1Ϊ�ǣ�0Ϊ�񣩣�";
    cin >> withDecimal;
    cout << "��ѡ�������ʽ���ļ�����ӡ���ȣ���";
    cin >> outputType;

    ofstream outputFile;
    if (outputType == "�ļ�") {
        outputFile.open("exercises.txt");
    }

    for (int i = 0; i < numExercises; i++) {
        string exercise = generateOperation(op, maxNum, withParentheses, withDecimal);
        cout << exercise << endl;
        if (outputType == "�ļ�") {
            outputFile << exercise << endl;
        }
    }

    if (outputType == "�ļ�") {
        outputFile.close();
        cout << "��Ŀ�������exercises.txt�ļ���" << endl;
    }

    return 0;
}