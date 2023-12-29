#include <iostream>
#include "orders.h"
using namespace std;

class controller {
private:
    cleaning_service current_service;
public:
    controller() {
    }
    void execute() {
        int run = 1;
        while (run) {
            menu();
            int var = 0;
            while (var < 1 || var > 8) {
                cout << "Input variant: ";
                cin >> var;
            }
            if (var == 8) {
                run = 0;
            }
            if (var == 1) {
                current_service.print();
            }
            if (var == 2) {
                current_service.addRc();
                cout << "Заказ успешно создан!";
            }
            if (var == 3) {
                current_service.print();
                cout << "Введите номер заказа, которой надо удалить:\n";
                int n;
                cin >> n;
                current_service.deleteRc(n);
            }
            if (var == 4) {
                current_service.saveToFile(true);
                cout << "Заказы успешно сохранены!" << endl;
            }
            if (var == 5) {
                current_service.saveToFile(false);
            }
            if (var == 6) {
                current_service.loadFile();
                cout << "Заказы из файла успешно загружены!" << endl;
            }
            if (var == 7) {
                cout << "Выберите заказ, который следует отредактировать:" << endl;
                int choose= 0;
                while (choose < 1 || choose>current_service.getN() + 1) {
                    current_service.print();
                    cout << "[" << current_service.getN() + 1 << "] " << "Отмена." << endl;
                    cin >> choose;

                }
                current_service.changeRecord(choose);
                cout << "Заказ успешно отредактирован!" << endl;
            }
        }
    }

    void menu() {
        cout << "Commands: " << endl;
        cout << "[1] Вывести все заказы" << endl;
        cout << "[2] Создать новую запись о заказе" << endl;
        cout << "[3] Удалить запись о заказе" << endl;
        cout << "[4] Добавить текущие заказы в файл" << endl;
        cout << "[5] Перазаписать текущий файл с заказами" << endl;
        cout << "[6] Загрузить заказы из файла" << endl;
        cout << "[7] Отредактировать заказ" << endl;
        cout << "[8] Выход из программы" << endl;
    }
};