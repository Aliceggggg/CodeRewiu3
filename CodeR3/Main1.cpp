//#include "password_generator.h"
//#include <iostream>
//
//int main() {
//    setlocale(LC_ALL, "ru");
//
//    PasswordGenerator generator;
//
//    try {
//        bool running = true;
//        while (running) {
//            generator.displayMenu();
//            int choice;
//            std::cout << "\nВведите номер уровня (0 для выхода): ";
//            std::cin >> choice;
//
//            if (choice == 0) {
//                running = false;
//                continue;
//            }
//
//            if (choice < 1 || choice > 3) {
//                std::cout << "Неверный выбор!\n";
//                continue;
//            }
//
//            std::string password = generator.generatePassword(choice - 1);
//            std::cout << "Сгенерированный пароль: " << password << std::endl;
//        }
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Ошибка: " << e.what() << std::endl;
//    }
//
//    return 0;
//}
