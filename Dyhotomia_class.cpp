#include "Dyhotomia_class.h"
#include <cmath>
#include <iostream>

Dyhotomia_class::Dyhotomia_class() {}
Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::встановитиМежі(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::встановитиТочність(double vol_eps) {
    eps = vol_eps;
}

// Функція f(x) = 3sin(√x) + 0.35x - 3.8
double Dyhotomia_class::функція(double x) {
    return 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
}

// Чисельне наближення похідної
double Dyhotomia_class::похідна(double x) {
    double dx = 1e-6;
    return (функція(x + dx) - функція(x)) / dx;
}

// Метод дихотомії (ділення навпіл)
int Dyhotomia_class::обчислитиДихотомією(double &x) {
    if (функція(a) * функція(b) > 0) {
        std::cout << "У проміжку [" << a << "; " << b << "] немає кореня або їх парна кількість.\n";
        return -1;
    }

    double c;
    while ((b - a) > eps) {
        c = (a + b) / 2.0;
        if (функція(a) * функція(c) <= 0)
            b = c;
        else
            a = c;
    }

    x = (a + b) / 2.0;
    return 0;
}

// Метод Ньютона
int Dyhotomia_class::обчислитиНьютоном(double x0, double &x) {
    int макс_ітерацій = 1000;
    int ітерація = 0;

    while (ітерація < макс_ітерацій) {
        double значенняФ = функція(x0);
        double значенняПох = похідна(x0);

        if (fabs(значенняПох) < 1e-12) {
            std::cout << "Похідна близька до нуля. Неможливо застосувати метод Ньютона.\n";
            return -1;
        }

        double x1 = x0 - значенняФ / значенняПох;

        if (fabs(x1 - x0) < eps) {
            x = x1;
            return 0;
        }

        x0 = x1;
        ітерація++;
    }

    std::cout << "Перевищено максимальну кількість ітерацій методу Ньютона.\n";
    return -1;
}