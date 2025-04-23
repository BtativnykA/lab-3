#include <iostream>
#include "Dyhotomia_class.h"

int main() {
    Dyhotomia_class *dyh = new Dyhotomia_class(); // Створення об'єкта класу

    dyh->встановитиМежі(2.0, 3.0);     // Встановлення початкового проміжку [a, b]
    dyh->встановитиТочність(1e-10);    // Встановлення точності ε

    double корінь;
    int вибір;

    std::cout << "Оберіть метод:\n";
    std::cout << "1 - Метод дихотомії\n";
    std::cout << "2 - Метод Ньютона\n";
    std::cout << "Ваш вибір: ";
    std::cin >> вибір;

    switch (вибір) {
        case 1:
            std::cout << "\nМетод дихотомії:\n";
            if (dyh->обчислитиДихотомією(корінь) == 0)
                std::cout << "Знайдено корінь: x = " << корінь << "\n";
            break;

        case 2:
            std::cout << "\nМетод Ньютона:\n";
            if (dyh->обчислитиНьютоном(2.5, корінь) == 0)
                std::cout << "Знайдено корінь: x = " << корінь << "\n";
            break;

        default:
            std::cout << "Невірний вибір!\n";
    }

    delete dyh; // Очищення пам'яті
    return 0;
}