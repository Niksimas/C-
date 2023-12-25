#ifndef CMAKE_TESTAPP_CONTROLLER_H
#define CMAKE_TESTAPP_CONTROLLER_H

#endif //CMAKE_TESTAPP_CONTROLLER_H

#include <iostream>
#include "group.h"
using namespace std;

class controller {
private:
    group group_local;
public:

    controller() {}

    void execute() {
        int run = 1;
        while (run) {
            cout << "Commands: \n"
                 << "[1] Add new student\n"
                 << "[2] Print list inability students\n"
                 << "[3] Print list students sorted alphabetically\n"
                 << "[4] Print excellent and inability student\n"
                 << "[5] Deleted student from group\n"
                 << "[6] Exit\n";
            int var = 0;
            while (var < 1 || var > 6) {
                cout << "Input number command: ";
                cin >> var;
            }
            if (var == 6) run = 0;
            else if (var == 1) group_local.add_stud();
            else if (var == 2) group_local.list_inability_student();
            else if (var == 3) group_local.sort_stud();
            else if (var == 4) group_local.mean_score_min_max();
            else if (var == 5) group_local.delete_stud();
        }
    }

};