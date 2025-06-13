#ifndef ELUERMETHOD_HPP
#define ELUERMETHOD_HPP

#include <vector>

/**
 * @brief Rozwiązuje równanie różniczkowe metodą Eulera.
 *
 * @param dTdt Funkcja opisująca zmianę temperatury w czasie.
 * @param T0 Temperatura początkowa.
 * @param T_env Temperatura otoczenia.
 * @param k Stała chłodzenia.
 * @param t_max Maksymalny czas symulacji.
 * @param h Krok czasowy dla metody Eulera.
 * @param temps Wektor do przechowywania temperatur w kolejnych krokach
 * czasowych.
 * @param times Wektor do przechowywania odpowiadających im chwil czasowych.
 */
void eulerMethod(double (*dTdt)(double, double, double), double T0,
                 double T_env, double k, double t_max, double h,
                 std::vector<double> &temps, std::vector<double> &times) {
  double T = T0;
  double t = 0.0;

  temps.clear();
  times.clear();

  while (t <= t_max) {
    temps.push_back(T);
    times.push_back(t);

    T = T + h * dTdt(T, T_env, k);
    t += h;
  }
}
#endif
