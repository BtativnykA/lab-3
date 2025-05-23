#include "Dyhotomia_class.h"
#include <cmath>
#include <iostream>

// Конструктор класу
Dyhotomia_class::Dyhotomia_class() {
    // Використовуємо лямбда-функцію для компактного запису
    f = [](double x) {
        return 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
    };

    // df(x) — чисельне обчислення похідної за формулою:
    // f'(x) ≈ [f(x + dx) - f(x)] / dx
    // Використано лямбда-функцію з доступом до f
    df = [this](double x) {
        double dx = 1e-6;
        return (f(x + dx) - f(x)) / dx;
    };
}

// Деструктор класу 
Dyhotomia_class::~Dyhotomia_class() {}

// Метод для встановлення меж a і b
void Dyhotomia_class::встановитиМежі(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

// Метод для встановлення точності ε
void Dyhotomia_class::встановитиТочність(double vol_eps) {
    eps = vol_eps;
}

// Метод дихотомії 
int Dyhotomia_class::обчислитиДихотомією(double &x) {
    // Перевірка: функція повинна змінювати знак на [a; b]
    if (f(a) * f(b) > 0) {
        std::cout << "У проміжку [" << a << "; " << b << "] немає кореня або їх парна кількість.\n";
        return -1;
    }

    double c;
    // Повторюємо, поки довжина відрізка більша за точність
    while ((b - a) > eps) {
        c = (a + b) / 2.0; // середина відрізка

        // Визначаємо, у якій половині знаходиться корінь
        if (f(a) * f(c) <= 0)
            b = c; // корінь у лівій частині
        else
            a = c; // корінь у правій частині
    }

    // Кінцеве наближення до кореня
    x = (a + b) / 2.0;
    return 0;
}

// Метод Ньютона
int Dyhotomia_class::обчислитиНьютоном(double x0, double &x) {
    int макс_ітерацій = 1000; // обмеження, щоб уникнути нескінченного циклу
    int ітерація = 0;

    while (ітерація < макс_ітерацій) {
        double значенняФ = f(x0);
        double значенняПох = df(x0); // обчислення похідної

        // Перевірка, щоб не ділити на нуль
        if (fabs(значенняПох) < 1e-12) {
            std::cout << "Похідна близька до нуля. Неможливо застосувати метод Ньютона.\n";
            return -1;
        }

        // Основна формула методу Ньютона:
        double x1 = x0 - значенняФ / значенняПох;

        // Умова завершення. досягнуто точності
        if (fabs(x1 - x0) < eps) {
            x = x1;
            return 0;
        }

        // Переходимо до нової ітерації
        x0 = x1;
        ітерація++;
    }

    std::cout << "Перевищено максимальну кількість ітерацій методу Ньютона.\n";
    return -1;
}