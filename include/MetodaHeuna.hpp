#ifndef METODAHEUNA_HPP
#define METODAHEUNA_HPP

#include <vector>

/**
 * @brief Rozwiązuje równanie różniczkowe metodą Heuna.
 *
 * @param dTdt Funkcja opisująca zmianę temperatury w czasie.
 * @param T0 Temperatura początkowa.
 * @param T_env Temperatura otoczenia.
 * @param k Stała chłodzenia.
 * @param t_max Maksymalny czas symulacji.
 * @param dt Krok czasowy dla metody Heuna.
 * @param temps Wektor do przechowywania temperatur w kolejnych krokach
 * czasowych.
 * @param times Wektor do przechowywania odpowiadających im chwil czasowych.
 */
void metodaHeuna(double (*dTdt)(double, double, double), double T0,
                 double T_env, double k, double t_max, double dt,
                 std::vector<double> &temps, std::vector<double> &times) {
  double T = T0;
  for (double t = 0; t <= t_max; t += dt) {
    times.push_back(t);
    temps.push_back(T);

    double f1 = dTdt(T, T_env, k);
    double f2 = dTdt(T + dt * f1, T_env, k);
    T += dt * 0.5 * (f1 + f2);
  }
}
#endif
