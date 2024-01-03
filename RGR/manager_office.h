#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "people_record.h"

using namespace std;

class manager_office_development {
private:
    int n = 0;
    vector <Record> recordes;
public:
    manager_office_development() {
        n = 1;
        Record newr = Record();
        recordes.emplace_back(newr);
    }
    void print() {
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ") " << recordes[i] << endl;
        }
    }
    void add_new_record() {
        string name, surname, email, name_project, description, check;
        while (true) {
            cout << "Input name: \n>>>";
            cin >> name;
            cout << "Input surname: \n>>>";
            cin >> surname;
            cout << "Input email: \n>>>";
            cin >> email;
            cout << "Input name_project: \n>>>";
            cin >> name_project;
            cout << "Input description: \n>>>";
            cin >> description;
            cout
                    << "User: " << name << " " << surname << " -- " << email << endl
                    << "Name project: " << name_project << endl
                    << "Description:\n" << description << endl;
            cout << "Check the correctness of the data (y/n): \n>>>";
            cin >> check;
            if (check == "y") {
                People newp = People(name, surname, email);
                Record new_record(newp, name_project, description);
                n++;
                recordes.push_back(new_record);
                cout << "Record saved!\n";
                break;
            }
        }
    }
    void deleted_record() {
        int k;
        cout << "Input number record for deleted:\n>>>";
        cin >> k;
        recordes.erase(recordes.begin()+k-1);
        n--;
        cout << "Record delited!\n";
    }
    void edit_record() {
        int k;
        print();
        cout << "Input number record for edited:\n";
        cin >> k;
        recordes[k - 1].edit_object();
        cout << "Record successful edited!\n" << endl;
    }

    void write_in_file(){
        ofstream out_data("record.txt", ios::out);
        if (!out_data.is_open()) cout << "Errors open file!\n";
        else {
            out_data << recordes.size() << endl;
            for (int i = 0; i < n; i++) {
                out_data
                << recordes[i].get_zakazchik().get_name() << "\n"
                << recordes[i].get_zakazchik().get_surname() << "\n"
                << recordes[i].get_zakazchik().get_email() << "\n"
                << recordes[i].get_name_project() << "\n"
                << recordes[i].get_description() << "\nk\n";
            }
        }
        out_data.close();
        cout << "Save and close\n";
    }
    void read_from_file() {
        ifstream in_data("record.txt", ios::in);
        if (!in_data.is_open())cout << "Errors open file!\n";
        else {
            int k = 0;
            string name="def", surname="def", email="def", name_proj="def", tmp_description="test", description="";
            Record newr = Record();
            in_data >> k;
            for (; 0 < k; k--) {
                n++;
                in_data >> name >> surname >> email >> name_proj;
                while (true){
                    in_data >> tmp_description;
                    if (tmp_description == "k")break;
                    description = description + " " + tmp_description;
                }
                newr.set_name_project(name_proj);
                newr.set_description(description);
                newr.set_zakazchik(name, surname, email);
                recordes.emplace_back(newr);
            }
        }
        in_data.close();
        cout << "Records loading is file successful!\n";
    }
};
