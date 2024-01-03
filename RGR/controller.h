#include <iostream>
#include "manager_office.h"
using namespace std;

class controller {
private:
    string name;
    manager_office_development office_development;
public:
    controller() {name="default";}
    void execute() {
        office_development.read_from_file();
        while (true) {
            menu();
            int num_comm = 0;
            cout << "Input number command: \n>>>";
            cin >> num_comm;
            if (num_comm == 1) {office_development.print();}
            else if (num_comm == 2) {office_development.add_new_record();}
            else if (num_comm == 3) {
                office_development.print();
                office_development.deleted_record();
            }
            else if (num_comm == 4) {office_development.edit_record();}
            else if (num_comm == 5) {office_development.write_in_file(); break;}
            else cout << "Invalid number command"; num_comm =0;
        }
    }

    static void menu() {
        cout << "Commands: \n"
        << "1) Print all record\n"
        << "2) Creat new record\n"
        << "3) Deleted record\n"
        << "4) Edit record\n"
        << "5) Save and exit\n";
    }
};
