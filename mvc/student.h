#pragma once
#ifndef CMAKE_TESTAPP_STUDENT_H
#define CMAKE_TESTAPP_STUDENT_H

#endif //CMAKE_TESTAPP_STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class student {
private:
    string name, surname;
    int* mark;
    int n;
public:

    student() {
        name = "default";
        surname = "default";
        n = 10;
        mark = new int[n];
        for (int i = 0; i < n; i++) mark[i] = 0;
    }

    void markSet(int i,int vl) { mark[i] = vl; }

    student(string n_name, string n_surname) {
        name = n_name;
        surname = n_surname;
        mark = new int[n];
        int k;
        cout << "How many grades does the student have?\n>>>" << endl;
        cin >> k;
        n=k;
        cout << "Input marks:" << endl;
        int i, o;
        for (i = 0; i < n; i++) {
            cout << "[" << i + 1 << "] ";
            cin >> o;
            markSet(i, o);
        }
    }

    string getSurname() {return surname;}

    void print() {
        cout << surname << " " << name << ":\n Mark's: ";
        for (int j = 0; j < n; j++) cout << mark[j] << " ";
        cout << endl;
    }

    double mean_score() {
        double sum = 0;
        for (int i = 0; i < n; i++) sum += mark[i];
        return sum / n;
    }
};