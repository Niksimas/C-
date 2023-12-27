#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "people_record.h"
#include "office.h"

using namespace std;

class manager_office_development {
private:
    int n=0;
    Record* recordes;
public:
    manager_office_development() {
//        n = 2;
//        recordes = new Record[n];
//        recordes[0] = Record(People(), "Name project1", "Discription1");
//        recordes[0] = Record(People("Name", "Surname", "email"), "Name project2", "Discription2");
    }
    void print() {
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ") " << recordes[i] << endl;
        }
    }
    void add_new_record() {
        while (true) {
            string name, surname, email, name_project, description;
            cout << "Input name and surname: ";
            cin >> name >> surname;
            cout << "Input email: ";
            cin >> email;
            cout << "Input name_project: ";
            cin >> name_project;
            cout << "Input description: ";
            cin >> description;
            string check;
            cout << "Check the correctness of the data (y/n): \n"
            << "User: " << name << " " << surname << " " << email << endl
            << "Name project: " << name_project << endl
            << "Description:\n" << description;
            cin >> check;
            if (check == "y") {
                Record new_record(People(name, surname, email), name_project, description);
                Record *new_recordes = new Record[n + 1];
                for (int i = 0; i < n; i++) {
                    new_recordes[i] = recordes[i];
                }
                new_recordes[n] = new_record;
                n++;
                recordes = new_recordes;
                cout << "Record saved!\n";
                break;
            }
        }
    }
    void deleted_record() {
        Record* new_records = new Record[n - 1];
        int k;
        cout << "Input number record for deleted:\n";
        cin >> k;
        for (int i=0, j=0; i<n; i++) {
            if (i != (k-1)) {
                new_records[j] = recordes[j];
                j++;
            }
        }
        n--;
        recordes = new_records;
    }
    void save_to_file(){
        ofstream out_data("record.txt", ofstream::app);
        if (!out_data.is_open()) cout<<"Errors open file!";
        else { for (int i = 0; i < n; i++) out_data.write((char *) &recordes[i], sizeof(Record)); }
        out_data.close();
        cout<<"Save and close";
    }
    void loading_from_file() {
        ifstream in_data("record.txt", ofstream::in);
        if (!in_data.is_open())cout<<"Errors open file!";
        else{
            Record temp_record;
            while (in_data.read((char*)&temp_record, sizeof(Record))) {
                Record* new_records = new Record[n + 1];
                for (int i = 0; i < n; i++) {
                    new_records[i] = recordes[i];
                }
                new_records[n] = temp_record;
                n++;
                recordes = new_records;
            }
        }
        in_data.close();
    }
    void edit_record() {
        int k;
        print();
        cout << "Input number record for edited:\n";
        recordes[k-1].edit_object();
        cout << "Record successful edited!" << endl;
    }
};













