#ifndef SrBladKwadrat_HPP
#define SrBladKwadrat_HPP

#include <vector>

/**
 * @brief Oblicza średni błąd kwadratowy (MSE) pomiędzy dwoma wektorami.
 *
 * @param ref Wektor referencyjny (wartości oczekiwane).
 * @param calculated Wektor obliczonych wartości.
 * @return Średni błąd kwadratowy.
 */
double SrBladKwadrat(const std::vector<double> &ref,
                     const std::vector<double> &calculated) {
  double suma = 0.0;
  for (size_t i = 0; i < ref.size(); ++i) {
    double blad = ref[i] - calculated[i];
    suma += blad * blad;
  }
  return suma / ref.size();
}

#endif