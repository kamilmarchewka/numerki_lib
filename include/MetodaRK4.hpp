#ifndef METODARK4_HPP
#define METODARK4_HPP

#include <vector>

/**
 * @brief Rozwiązuje równanie różniczkowe metodą Rungego-Kutty czwartego rzędu.
 *
 * @param dTdt Funkcja opisująca zmianę temperatury w czasie.
 * @param T0 Temperatura początkowa.
 * @param T_env Temperatura otoczenia.
 * @param k Stała chłodzenia.
 * @param t_max Maksymalny czas symulacji.
 * @param dt Krok czasowy dla metody Rungego-Kutty.
 * @param times Wektor do przechowywania chwil czasowych.
 * @param temps Wektor do przechowywania temperatur w kolejnych krokach
 * czasowych.
 */
void metodaRK4(double (*dTdt)(double, double, double), double T0, double T_env,
               double k, double t_max, double dt, std::vector<double> &times,
               std::vector<double> &temps) {
  double T = T0;
  for (double t = 0; t <= t_max; t += dt) {
    times.push_back(t);
    temps.push_back(T);

    double k1 = dTdt(T, T_env, k);
    double k2 = dTdt(T + 0.5 * dt * k1, T_env, k);
    double k3 = dTdt(T + 0.5 * dt * k2, T_env, k);
    double k4 = dTdt(T + dt * k3, T_env, k);

    T += (dt / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
  }
}
#endif
