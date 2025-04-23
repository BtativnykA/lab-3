#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

class Dyhotomia_class {
private:
    double a;    // Ліва межа
    double b;    // Права межа
    double eps;  // Точність

    double функція(double x);       // f(x)
    double похідна(double x);       // f'(x)

public:
    Dyhotomia_class();              // Конструктор
    ~Dyhotomia_class();             // Деструктор

    void встановитиМежі(double vol_a, double vol_b); 
    void встановитиТочність(double vol_eps);         

    int обчислитиДихотомією(double &x);             
    int обчислитиНьютоном(double x0, double &x);     
};

#endif