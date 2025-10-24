#include <iostream>
#include <vector>
#include <memory>
#include "include/Rhombus.h"
#include "include/Pentagon.h"
#include "include/Hexagon.h"

#include <windows.h>

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(65001);
    #endif

    std::vector<std::shared_ptr<Figure>> figures;
    int choice;

    while (true) {
        std::cout << "\nМеню:\n"
                  << "1. Добавить ромб\n"
                  << "2. Добавить пятиугольник\n"
                  << "3. Добавить шестиугольник\n"
                  << "4. Показать все фигуры\n"
                  << "5. Общая площадь\n"
                  << "6. Удалить фигуру по индексу\n"
                  << "0. Выход\n> ";
        std::cin >> choice;

        if (choice == 0) break;

        if (choice >= 1 && choice <= 3) {
            std::shared_ptr<Figure> f;
            if (choice == 1) f = std::make_shared<Rhombus>();
            else if (choice == 2) f = std::make_shared<Pentagon>();
            else f = std::make_shared<Hexagon>();
            std::cin >> *f;
            figures.push_back(f);
        }
        else if (choice == 4) {
            int i = 0;
            for (auto& f : figures) {
                std::cout << i++ << ") " << *f
                          << "\n  Центр: (" << f->center().x << ", " << f->center().y << ")"
                          << "\n  Площадь: " << static_cast<double>(*f) << "\n";
            }
        }
        else if (choice == 5) {
            double total = 0;
            for (auto& f : figures)
                total += static_cast<double>(*f);
            std::cout << "Общая площадь: " << total << "\n";
        }
        else if (choice == 6) {
            int idx;
            std::cout << "Введите индекс фигуры для удаления: ";
            std::cin >> idx;
            if (idx >= 0 && idx < figures.size())
                figures.erase(figures.begin() + idx);
            else
                std::cout << "Неверный индекс!\n";
        }
    }
}
