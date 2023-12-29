#pragma once
#include <iostream>
#include <string>
using namespace std;

class People {
private:
    string name, surname, email;
public:
    People() {
        name = "Nikita";
        surname = "Starostin";
        email = "fififi@mail.com";
    }
    People(string &n_name, string &n_surname, string &n_email) {
        name = n_name;
        surname = n_surname;
        email = n_email;
    }
    friend ostream& operator <<(ostream& out, People& p) {
        out << p.surname << " " << p.name << " " << p.email;
        return out;
    }
    string get_name() { return name; }
    string get_surname() { return surname; }
    string get_email() { return email; }
    void set_name(string &n) { name = n; }
    void set_surname(string &n) { surname = n; }
    void set_email(string &n) { email = n; }
};

class Record {
private:
    string name_project, description;
    People zakazchik=People();
public:
    Record() {
        name_project = "Test";
        description = "Opisanie testa";
        zakazchik = People();
    }
    Record(People &people, string &n_name_project, string &n_description) {
        zakazchik = people;
        name_project = n_name_project;
        description = n_description;
    }
    string get_name_project() { return name_project; }
    string get_description() { return description; }
    People get_zakazchik() { return zakazchik; }
    friend ostream& operator <<(ostream& out, Record& r) {
        out
        << "User: "<< r.zakazchik << " - "
        << "Name_project: " << r.name_project << " - "
        << "Discription: " << r.description << endl;
        return out;
    }
    void set_name_project(string &k) { name_project = k; }
    void set_description(string &k) { description = k; }
    void set_zakazchik(string &n, string &sn, string &e) {
        zakazchik.set_name(n);
        zakazchik.set_surname(sn);
        zakazchik.set_email(e);
    }

    void edit_object() {
        int selecting;
        while (true) {
            cout
            << "Choose number field for edited:\n"
            << "1) Name project\n"
            << "2) Description\n"
            << "3) Client\n";
            cin >> selecting;

            if (selecting == 1) {
                cout << "Input new name project:\n>>>" << endl;
                cin >> name_project;
                cout << "Set new name: \n>>>" << name_project;
                break;
            }
            else if (selecting == 2) {
                cout << "Input new description: \n>>>";
                cin >> description;
                cout << "Set new description: \n" << description << endl;
                break;
            }
            else if (selecting == 3) {
                string name, surname, number;
                cout << "Input new name client: \n>>>";
                cin >> name;
                cout << "Input new surname client: \n>>>";
                cin >> name;
                cout << "Input new email for client: \n>>>";
                cin >> number;
                zakazchik = People(name, surname, number);
                break;
            }
            else {
                cout << "Invalid number command\n";
            }
        }
    }
};