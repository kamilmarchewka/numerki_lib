#ifndef METODAPKTSR_HPP
#define METODAPKTSR_HPP

#include <vector>

/**
 * @brief Rozwiązuje równanie różniczkowe metodą punktu środkowego.
 *
 * @param dTdt Funkcja opisująca zmianę temperatury w czasie.
 * @param T0 Temperatura początkowa.
 * @param T_env Temperatura otoczenia.
 * @param k Stała chłodzenia.
 * @param t_max Maksymalny czas symulacji.
 * @param dt Krok czasowy dla metody punktu środkowego.
 * @param times Wektor do przechowywania chwil czasowych.
 * @param temps Wektor do przechowywania temperatur w kolejnych krokach
 * czasowych.
 */
void metodaPunktuSrodkowego(double (*dTdt)(double, double, double), double T0,
                            double T_env, double k, double t_max, double dt,
                            std::vector<double> &times,
                            std::vector<double> &temps) {
  double T = T0;
  for (double t = 0; t <= t_max; t += dt) {
    times.push_back(t);
    temps.push_back(T);

    double k1 = dTdt(T, T_env, k);
    double T_mid = T + 0.5 * dt * k1;
    double k2 = dTdt(T_mid, T_env, k);

    T += dt * k2;
  }
}

#endif