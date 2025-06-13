#ifndef SIMPSONMETFUNC_HPP
#define SIMPSONMETFUNC_HPP

#include "Horner.hpp"

/**
 * @brief Oblicza całkę funkcji za pomocą metody Simpsona.
 *
 * @param f Wskaźnik na funkcję, która ma zostać całkowana.
 * @param a Dolna granica całkowania.
 * @param b Górna granica całkowania.
 * @param n Liczba podprzedziałów (musi być parzysta).
 * @return Przybliżona wartość całki.
 */
double simpson_f(double (*f)(double), double a, double b, int n) {
  if (n % 2 != 0)
    ++n;
  double dx = (b - a) / n;
  double sum = f(a) + f(b);
  for (int i = 1; i < n; ++i)
    sum += f(a + i * dx) * (i % 2 == 0 ? 2 : 4);
  return sum * dx / 3.0;
}
#endif