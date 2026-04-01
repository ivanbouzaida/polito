#include <iostream>
#include "razionali.hpp"

int main() {
    using R = rational<int>;

    // Test base
 
    R a(1, 2);
    R b(3, 4);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";


    // Somma
	std::cout << "a + b = " << a + b << "\n";

 
    // Sottrazione

    std::cout << "a - b = " << a - b << "\n";

    // Moltiplicazione

    std::cout << "a * b = " << a * b << "\n";

    // Divisione

    std::cout << "a / b = " << a / b << "\n";

    // Semplificazione

    R c(6, 8);
    std::cout << "6/8 semplificato = " << c << "\n"; // deve dare 3/4

    // Segni

    R d(-2, 4);
    std::cout << "-2/4 = " << d << "\n"; // deve dare -1/2

    R e(2, -4);
    std::cout << "2/-4 = " << e << "\n"; // deve dare -1/2

    // Zero

    R f(0, 5);
    std::cout << "0/5 = " << f << "\n"; // deve dare 0/1

    // INF e NaN

    R inf(1, 0);
    R neg_inf(-1, 0);
    R nan(0, 0);

    std::cout << "inf = " << inf << "\n";
    std::cout << "-inf = " << neg_inf << "\n";
    std::cout << "nan = " << nan << "\n";

    // Operazioni con INF

    std::cout << "inf + a = " << inf + a << "\n";
    std::cout << "inf + (-inf) = " << inf + neg_inf << "\n"; // NaN

    // Operazioni con NaN

    std::cout << "nan + a = " << nan + a << "\n";
    std::cout << "nan * b = " << nan * b << "\n";

    // Moltiplicazioni strane

    std::cout << "inf * 0 = " << inf * R(0,1) << "\n"; // NaN

    // Divisioni strane

    std::cout << "a / 0 = " << a / R(0,1) << "\n"; // Inf

    return 0;
}