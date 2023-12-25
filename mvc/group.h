#ifndef CMAKE_TESTAPP_GROUP_H
#define CMAKE_TESTAPP_GROUP_H

#endif //CMAKE_TESTAPP_GROUP_H
#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include <vector>
using namespace std;

class group {
private:
    int n;
    student* stud_group;
public:

    group() {
        n = 1;
        cout<<"To start working in the system, enter the name and surname of the students in the number " << n << ":\n";
        stud_group = new student[n];
        for (int i = 0; i < n; i++) {
            string name, surname;
            cin >> name >> surname;
            stud_group[i] = (student(name, surname));
        }
    }

    void print() {
        for (int i = 0; i < n; i++) {
            student current_student = stud_group[i];
            cout << "[" << i + 1 << "] ";
            current_student.print();
        }
    }

    void add_stud() {
        string name, surname;
        cout << "Input name, surname student:\n";
        cin >> name >> surname;
        student * new_st_group = new student[n + 1];
        for (int i = 0; i < n; i++) new_st_group[i] = stud_group[i];
        new_st_group[n] = student(name, surname);
        n++;
        stud_group = new_st_group;
    }

    void delete_stud() {
        stud_group->print();
        cout << "Input number student for deleted:\n";
        int k;
        cin >> k;
        student* newst = new student[n - 1];
        for (int i = 0,j=0; i < n; i++,j++) {
            if (i == (k - 1))i++;
            if (i<n)newst[j] = stud_group[i];
        }
        n--;
        stud_group = newst;
    }

    void sort_stud() {
        cout << "List students sorted alphabetically:\n";
        student* tpm_stud_group = new student[n];
        for (int i = 0; i < n; i++) tpm_stud_group[i] = stud_group[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (tpm_stud_group[j].getSurname() > tpm_stud_group[j + 1].getSurname()) {
                    student copy_stud = tpm_stud_group[j];
                    tpm_stud_group[j] = tpm_stud_group[j + 1];
                    tpm_stud_group[j + 1] = copy_stud;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            student current_student = tpm_stud_group[i];
            cout << "[" << i + 1 << "] ";
            current_student.print();
        }
    }

    void mean_score_min_max() {
        student bad, best;
        float mean_score_max = 0, mean_score_min = 5;
        for (int i = 0; i < n; i++) {
            student tpm_student = stud_group[i];
            double tpm_score = tpm_student.mean_score();
            if (tpm_score >= mean_score_max) {
                mean_score_max = tpm_score;
                best = tpm_student;
            }
            if (tpm_score <= mean_score_min) {
                mean_score_min = tpm_score;
                bad = tpm_student;
            }
        }
        cout << "Excellent student:\n" << mean_score_max << " - ";
        best.print();
        cout << "The inability of the student:\n" << mean_score_min << " - ";
        bad.print();
    }

    void list_inability_student(){
        int m = 1;
        cout << "List inability students in group:\n";
        for (int i = 0; i < n; i++) {
            student current_student = stud_group[i];
            if (current_student.mean_score() < 2.5) {
                cout << "[" << m << "] ";
                current_student.print();
                m++;
            }
        }
    }
};