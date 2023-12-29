#include <iostream>
#include <string>
#include "record.h"
#include <vector>
#include <fstream>

using namespace std;

class cleaning_service {
private:
    int n;
    record* orders;
    string type_object[9] = {
        "Квартира","Коттедж","Офис",
        "Магазин","Торговый центр","Производство",
        "Склад","Многоквартирный дом","Другое"
    };
    string type_clean[10] = {
        "Разовая","Ежемесячная","Химчистка",
        "Уборка после ремонта","Уборка после ЧП","Удаление запахов",
        "Удаление плесени","Промышленный альпинизм","Дезинфекция",
        "Другое"
    };
public:
    cleaning_service() {
        n = 2;
        setlocale(LC_ALL, "ru");
        orders = new record[n];
        for (int j = 0; j < n; j++) {
            string object, clean,name,surname,number;
            float S;
            cout << "Выберите тип объекта:" << endl;
            int select = 0;
            for (int i = 0; i < 9; i++) {
                cout << "[" << i + 1 << "] " << type_object[i] << endl;
            }
            while (select < 1 || select>9) {
                cin >> select;
            }
            if (select == 9) {
                cout << "Введите свой тип объекта: ";
                cin >> object;
            }
            else object = type_object[select - 1];
            cout << "Укажите площадь (кв.м.) объекта: ";
            cin >> S;
            select = 0;
            cout << "Выберите тип уборки:" << endl;
            for (int i = 0; i < 10; i++) {
                cout << "[" << i + 1 << "] " << type_clean[i] << endl;
            }
            while (select < 1 || select>10) {
                cin >> select;
            }
            if (select == 10) {
                cout << "Введите нужный вам тип уборки: ";
                cin >> clean;
            }
            else clean = type_clean[select - 1];
            cout << "Укажите ваше имя: ";
            cin >> name;
            cout << "Укажите вашу фамилию: ";
            cin >> name;
            cout << "Укажите ваш номер телефона для дальнейшей связи: ";
            cin >> number;
            orders[j] = record(name,surname, number, object, S, clean);
        }
    }
    void print() {
        setlocale(LC_ALL, "ru");
        for (int i = 0; i < n; i++) {
            record current_record = orders[i];
            cout << "[" << i + 1 << "] ";
            current_record.print();
        }
    }
    void addRc() {
        string object, clean, name, surname, number;
        float S;
        cout << "Выберите тип объекта:" << endl;
        int select = 0;
        for (int i = 0; i < 9; i++) {
            cout << "[" << i + 1 << "] " << type_object[i] << endl;
        }
        while (select < 1 || select>9) {
            cin >> select;
        }
        if (select == 9) {
            cout << "Введите свой тип объекта: ";
            cin >> object;
        }
        else object = type_object[select - 1];
        cout << "Укажите площадь (кв.м.) объекта: ";
        cin >> S;
        select = 0;
        cout << "Выберите тип уборки:" << endl;
        for (int i = 0; i < 10; i++) {
            cout << "[" << i + 1 << "] " << type_clean[i] << endl;
        }
        while (select < 1 || select>10) {
            cin >> select;
        }
        if (select == 10) {
            cout << "Введите нужный вам тип уборки: ";
            cin >> clean;
        }
        else clean = type_clean[select - 1];
        cout << "Укажите ваше имя: ";
        cin >> name;
        cout << "Укажите вашу фамилию: ";
        cin >> name;
        cout << "Укажите ваш номер телефона для дальнейшей связи: ";
        cin >> number;
        record newrc(name, surname, number, object, S, clean);
        record* newor = new record[n + 1];
        for (int i = 0; i < n; i++) {
            newor[i] = orders[i];
        }
        newor[n] = newrc;
        n++;
        orders = newor;
    }
    void addRcFile(record &newrc) {
        record* newor = new record[n + 1];
        for (int i = 0; i < n; i++) {
            newor[i] = orders[i];
        }
        newor[n] = newrc;
        n++;
        orders = newor;
    }
    void deleteRc(int k) {
        record* newor = new record[n - 1];
        for (int i = 0,j=0; i < n; i++,j++) {
            if (i == (k - 1))i++;
            if (i<n)newor[j] = orders[i];
        }
        n--;
        orders = newor;
    }
    void saveToFile(bool app) {
        ofstream out;
        try {
            if (app)
                out.open("orders.txt", ios::app);
            else out.open("orders.txt");
        }
        catch (const char* error_message) {
            cout << error_message << endl;
            return;
        }
        if (out.is_open())
        {
            string rcInfo;
            for (int i = 0; i < n; i++) {
                record cr_rc = orders[i];
                rcInfo = cr_rc.getClient().getName() + "||" + cr_rc.getClient().getSurname() + "||" + cr_rc.getClient().getNumber() + "||" + cr_rc.getObject() + "||" + to_string(cr_rc.getS()) + "||" + cr_rc.getClean();
                out << rcInfo << endl;
            }
            out.close();
        }
    }
    void loadFile() {
        ifstream in("orders.txt");
        if (in.is_open())
        {
            string newrc;
            while (getline(in, newrc)) {
                // вывод текста из файла
                string name = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                string surname = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                string number = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                string object = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                float S = stof(newrc.substr(0, newrc.find("||")));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                string clean = newrc.substr(0, newrc.length());
                record* newrc = new record(name,surname, number, object, S, clean);
                addRcFile(*newrc);
            }
        }
        in.close();
    }
    void changeRecord(int n) {
        orders[n - 1].change();
    }
    int getN() {
        return n;
    }
};