#ifndef REGULAFALSI_HPP
#define REGULAFALSI_HPP

#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>

#ifndef EPSILON
#define EPSILON 1e-15
#endif
#ifndef MAX_ITER
#define MAX_ITER 100
#endif

/**
 * @brief Metoda Reguły Falsi (Regula Falsi) do znajdowania pierwiastków funkcji
 *
 * @param f Funkcja, której pierwiastek ma zostać znaleziony
 * @param a Lewy koniec przedziału
 * @param b Prawy koniec przedziału
 * @param out Strumień wyjściowy do zapisu wyników
 * @return Pierwiastek funkcji lub ostatnia wartość c, jeśli nie znaleziono
 * pierwiastka
 */
double regula_falsi(std::function<double(double)> f, double a, double b,
                    std::ofstream &out) {
  double fa = f(a), fb = f(b);
  if (fa * fb >= 0) {
    throw std::invalid_argument("Brak zmiany znaku w przedziale!");
  }

  double c, fc;
  out << "iteracja,a,b,c,f(c)\n";

  for (int i = 0; i < MAX_ITER; ++i) {
    c = (a * fb - b * fa) / (fb - fa);
    fc = f(c);

    out << i + 1 << "," << a << "," << b << "," << c << "," << fc << "\n";

    if (std::abs(fc) < EPSILON)
      return c;

    if (fa * fc < 0) {
      b = c;
      fb = fc;
    } else {
      a = c;
      fa = fc;
    }
  }

  return c;
}

/**
 * @brief Znajduje pierwiastki funkcji w zadanym przedziale i zapisuje wyniki do
 * pliku
 *
 * @param f Funkcja, której pierwiastki mają zostać znalezione
 * @param a Lewy koniec przedziału
 * @param b Prawy koniec przedziału
 * @param step Krok, co jaki sprawdzane są wartości funkcji
 * @param filename Nazwa pliku, do którego zapisywane są wyniki
 */
void find_zeros(std::function<double(double)> f, double a, double b,
                double step, const std::string &filename) {
  std::ofstream out(filename);
  if (!out.is_open()) {
    std::cerr << "Nie można otworzyć pliku: " << filename << "\n";
    return;
  }

  for (double x = a; x < b; x += step) {
    double fa = f(x);
    double fb = f(x + step);

    if (std::isnan(fa) || std::isnan(fb))
      continue;

    if (fa * fb < 0) {
      try {
        regula_falsi(f, x, x + step, out);
        out << "\n";
      } catch (...) {
      }
    }
  }

  out.close();
}
#endif