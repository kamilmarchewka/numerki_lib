#ifndef RECTMETFUNC_HPP
#define RECTMETFUNC_HPP

#include "Horner.hpp"

/**
 * @brief Oblicza przybliżoną wartość całki oznaczonej funkcji za pomocą metody
 * prostokątów.
 * @param f Wskaźnik do funkcji, której całkę chcemy obliczyć.
 * @param a Dolna granica całkowania.
 * @param b Górna granica całkowania.
 * @param n Liczba podziałów (prostokątów) w przedziale [a, b].
 * @return Przybliżona wartość całki oznaczonej.
 */
double rectangle_f(double (*f)(double), double a, double b, int n) {
  double dx = (b - a) / n;
  double sum = 0;
  for (int i = 0; i < n; ++i)
    sum += f(a + i * dx);
  return sum * dx;
}
#endif