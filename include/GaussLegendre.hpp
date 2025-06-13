#ifndef GAUSSLEGENDRE_HPP
#define GAUSSLEGENDRE_HPP

#include <functional>
#include <iostream>
#include <vector>

/**
 * @brief Oblicza całkę funkcji za pomocą kwadratury Gaussa-Legendre'a.
 *
 * @param f Wskaźnik na funkcję, która ma zostać całkowana.
 * @param a Dolna granica całkowania.
 * @param b Górna granica całkowania.
 * @param nodes Liczba węzłów (2, 3 lub 4).
 * @return Przybliżona wartość całki.
 */
double gauss_legendre(std::function<double(double)> f, double a, double b,
                      int nodes) {
  std::vector<double> x, w;

  if (nodes == 2) {
    x = {-0.5773502692, 0.5773502692};
    w = {1.0, 1.0};
  } else if (nodes == 3) {
    x = {-0.7745966692, 0.0, 0.7745966692};
    w = {0.5555555556, 0.8888888889, 0.5555555556};
  } else if (nodes == 4) {
    x = {-0.8611363116, -0.3399810436, 0.3399810436, 0.8611363116};
    w = {0.3478548451, 0.6521451549, 0.6521451549, 0.3478548451};
  } else {
    std::cerr << "Tylko 2, 3 lub 4 węzły!\n";
    return 0;
  }

  double sum = 0;
  for (size_t i = 0; i < x.size(); ++i) {
    double xi = ((b - a) / 2.0) * x[i] + (a + b) / 2.0;
    sum += w[i] * f(xi);
  }

  return (b - a) / 2.0 * sum;
}

/**
 * @brief Oblicza całkę funkcji za pomocą kwadratury Gaussa-Legendre'a
 * z podziałem na mniejsze przedziały.
 *
 * @param f Wskaźnik na funkcję, która ma zostać całkowana.
 * @param a Dolna granica całkowania.
 * @param b Górna granica całkowania.
 * @param nodes Liczba węzłów (2, 3 lub 4).
 * @param subdivs Liczba podprzedziałów.
 * @return Przybliżona wartość całki.
 */
double gauss_legendre_subdivided(std::function<double(double)> f, double a,
                                 double b, int nodes, int subdivs) {
  double h = (b - a) / subdivs;
  double result = 0.0;

  for (int i = 0; i < subdivs; ++i) {
    double sub_a = a + i * h;
    double sub_b = sub_a + h;
    result += gauss_legendre(f, sub_a, sub_b, nodes);
  }

  return result;
}

#endif