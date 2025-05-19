#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

#include <functional> 

// Клас для реалізації методів дихотомії та Ньютона
class Dyhotomia_class {
private:
    double a;       // ліва межа 
    double b;       // права межа 
    double eps;     //  точність

    std::function<double(double)> f;  // функція  яку досліджуємо
    std::function<double(double)> df; // похідна  обчислювана

public:
    Dyhotomia_class();  // конструктор
    ~Dyhotomia_class(); // деструктор

    void встановитиМежі(double vol_a, double vol_b);  
    void встановитиТочність(double vol_eps);        

    int обчислитиДихотомією(double &x); 
    int обчислитиНьютоном(double x0, double &x); 
};

#endif