#ifndef METODABISEKCJA_HPP
#define METODABISEKCJA_HPP

#include <cmath>

#ifndef EPSILON
#define EPSILON 1e-15
#endif
#ifndef MAX_ITER
#define MAX_ITER 100
#endif

/**
 * @brief Rozwiązuje równanie nieliniowe metodą bisekcji.
 *
 * @param f Funkcja, której pierwiastek ma zostać znaleziony.
 * @param a Lewy koniec przedziału, w którym szukamy pierwiastka.
 * @param b Prawy koniec przedziału, w którym szukamy pierwiastka.
 * @return Pierwiastek funkcji lub NAN, jeśli warunki nie są spełnione.
 */
double metodaBisekcji(double (*f)(double), double a, double b) {
  if (f(a) * f(b) > 0 || isnan(f(a)) || isnan(f(b)))
    return NAN;
  double c;
  for (int i = 0; i < MAX_ITER; i++) {
    c = (a + b) / 2;
    if (fabs(f(c)) < EPSILON || fabs(b - a) < EPSILON)
      return c;
    if (f(a) * f(c) < 0)
      b = c;
    else
      a = c;
  }
  return c;
}

#endif