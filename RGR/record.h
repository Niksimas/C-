#include <iostream>
#include <string>
#include <stdlib.h>
#include "people.h"
#include <time.h>
using namespace std;

class record {
private:
    string object;
    float S;
    string clean;
    people client;
    string type_object[9] = {
        "��������","�������","����",
        "�������","�������� �����","������������",
        "�����","��������������� ���","������"
    };
    string type_clean[10] = {
        "�������","�����������","���������",
        "������ ����� �������","������ ����� ��","�������� �������",
        "�������� �������","������������ ���������","�����������",
        "������"
    };
public:
    record() {
        object = "��������";
        S = 40.0;
        clean = "�������";
    }
    record(string name,string surname,string number, string object, float S, string clean) {
        this->client = *(new people(name, surname, number));
        this->S = S;
        this->clean = clean;
    }
    string getObject() {
        return object;
    }
    float getS() {
        return S;
    }
    string getClean() {
        return clean;
    }
    people getClient() {
        return client;
    }
    string getClientInfo() {
        client.print();
    }
    void print() {
        client.print();
        cout << "��� �������: " << object << " - " << S <<" ��.�" << "; ��� ������: " << clean << endl;
    }
    void change() {
        cout << "�������� ����� ������, ������� �� ������ �� ���������������:\n";
        cout << "1 - ������\n";
        cout << "2 - ������� �������\n";
        cout << "3 - ��� ������\n";
        cout << "4 - ���������� � �������\n";
        int choose = 0;
        while (choose < 1 || choose>4){
            cin >> choose;
        }
        switch (choose){
        case 1:
            {
            cout << "�������� ��� �������:" << endl;
            int select = 0;
            for (int i = 0; i < 9; i++) {
                cout << "[" << i + 1 << "] " << type_object[i] << endl;
            }
            while (select < 1 || select>9) {
                cin >> select;
            }
            if (select == 9) {
                cout << "������� ���� ��� �������: ";
                cin >> object;
            }
            else object = type_object[select - 1];
            break;}
        case 2:
        {
            cout << "������� ������� (��.�.) �������: ";
            cin >> S;
            break;
        }
        case 3:
        {
            int select = 0;
            cout << "�������� ��� ������:" << endl;
            for (int i = 0; i < 10; i++) {
                cout << "[" << i + 1 << "] " << type_clean[i] << endl;
            }
            while (select < 1 || select>10) {
                cin >> select;
            }
            if (select == 10) {
                cout << "������� ������ ��� ��� ������: ";
                cin >> clean;
            }
            else clean = type_clean[select - 1];
            break;
        }
        case 4:
        {
            string name, surname, number;
            cout << "������� ��� ������ �������: ";
            cin >> name;
            cout << "������� ������� ������ �������: ";
            cin >> name;
            cout << "������� ����� �������� ������ ������� ��� ���������� �����: ";
            cin >> number;
            client = people(name, surname, number);
            break;
        }
        default:
            break;
        }
    }
};