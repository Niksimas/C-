#pragma once
#include <iostream>
#include <string>
using namespace std;

class People {
private:
	string name, surname, email;
public:
    People() {
		name = "default";
		surname = "default";
		email = "000@mail.com";
	}
    People(string n_name, string n_surname, string n_email) {
		name = n_name;
		surname = n_surname;
        email = n_email;
	}

    friend ostream& operator <<(ostream &out, People &p){
        out << p.surname << " " << p.name << "\t" << p.email << "\t";
        return out;
    }
};

class Record {
private:
    string name_project, description;
    People zakazchik;
public:
    Record() {
        name_project = "default";
        description = "default";
        zakazchik = People();
    }
    Record(People people, string n_name_project, string n_description) {
        zakazchik = people;
        name_project = n_name_project;
        description = n_description;
    }
    friend ostream& operator <<(ostream &out, Record &r){
        out
        << "User: " << r.zakazchik << "\t"
        << "Name project: " << r.name_project << "\t"
        << "Description project: \n" << r.description << "\t";
        return out;
    }
    void edit_object() {
        int selecting;
        while (true){
            cout
            << "Choose number field for edited:\n"
            << "1) Name project\n"
            << "2) Description\n"
            << "3) Client\n";
            cin >> selecting;

            if (selecting == 1){
                cout << "Input new name project:" << endl;
                cin >> name_project;
                cout << "Set new name: " << name_project;
                break;
            }else if (selecting == 2){
                cout << "Input new description: ";
                cin >> description;
                cout << "Set new description: \n" << description;
                break;
            }else if (selecting == 3){
                string name, surname, number;
                cout << "Input new name client: ";
                cin >> name;
                cout << "Input new surname client: ";
                cin >> name;
                cout << "Input new email for client: ";
                cin >> number;
                zakazchik = People(name, surname, number);
                break;
            } else{
                cout << "Invalid number command\n";
            }
        }
    }
};