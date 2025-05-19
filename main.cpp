#include <iostream>
#include "Dyhotomia_class.h"

int main() {
    // Створюємо об’єкт класу для обчислень
    Dyhotomia_class *dyh = new Dyhotomia_class();

    // Встановлюємо початкові значення
    dyh->встановитиМежі(2.0, 3.0);        // межі [a, b]
    dyh->встановитиТочність(1e-10);       // точність 

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

    delete dyh; 
    return 0;
}