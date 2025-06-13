#ifndef TRAPMETFUNC_HPP
#define TRAPMETFUNC_HPP

#include "Horner.hpp"

/**
 * @brief Oblicza całkę funkcji za pomocą metody trapezów.
 *
 * @param f Wskaźnik na funkcję, która ma zostać całkowana.
 * @param a Dolna granica całkowania.
 * @param b Górna granica całkowania.
 * @param n Liczba podprzedziałów.
 * @return Przybliżona wartość całki.
 */
double trapezoid_f(double (*f)(double), double a, double b, int n) {
  double dx = (b - a) / n;
  double sum = 0.5 * (f(a) + f(b));
  for (int i = 1; i < n; ++i)
    sum += f(a + i * dx);
  return sum * dx;
}
#endif