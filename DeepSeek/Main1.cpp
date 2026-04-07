//#include <iostream>
//#include <string>
//#include "password_generator.h"
//
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    int choice;
//
//    cout << "\n========================================\n";
//    cout << "        ГЕНЕРАТОР ПАРОЛЕЙ\n";
//    cout << "========================================\n\n";
//
//    while (true) {
//        cout << "Выберите уровень сложности:\n";
//        cout << "1 - Лёгкий (8 символов, только буквы)\n";
//        cout << "2 - Средний (12 символов, буквы и цифры)\n";
//        cout << "3 - Сложный (16 символов, буквы+цифры+символы)\n";
//        cout << "0 - Выход\n\n";
//        cout << "Ваш выбор: ";
//        cin >> choice;
//
//        if (choice == 0) {
//            cout << "\nДо свидания!\n";
//            break;
//        }
//
//        if (choice < 1 || choice > 3) {
//            cout << "\nОшибка! Выберите 1, 2, 3 или 0\n\n";
//            continue;
//        }
//
//        cout << "\nСколько паролей сгенерировать? ";
//        int count;
//        cin >> count;
//
//        if (count <= 0) {
//            cout << "Ошибка! Нужно положительное число\n\n";
//            continue;
//        }
//
//        cout << "\n--- Ваши пароли ---\n";
//        for (int i = 1; i <= count; i++) {
//            cout << i << ". " << generatePassword(choice) << endl;
//        }
//        cout << "--------------------\n\n";
//    }
//
//    return 0;
//}