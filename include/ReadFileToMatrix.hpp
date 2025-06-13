
#ifndef READFILETOMATRIX_HPP
#define READFILETOMATRIX_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief Wczytuje macierz i wektor z pliku.
 *
 * Funkcja wczytuje kwadratową macierz A oraz wektor b z pliku.
 * Pierwsza linia pliku zawiera rozmiar macierzy N.
 * Kolejne N linii zawierają elementy wektora b, a następne N linii
 * zawierają elementy macierzy A.
 *
 * @param filename Nazwa pliku do wczytania.
 * @param A Macierz, która zostanie wypełniona wczytanymi wartościami.
 * @param b Wektor, który zostanie wypełniony wczytanymi wartościami.
 * @param N Rozmiar macierzy i wektora.
 * @return true jeśli plik został poprawnie wczytany, false w przeciwnym razie.
 */

bool readFileToMatrix(const std::string &filename,
                      std::vector<std::vector<double>> &A,
                      std::vector<double> &b, int &N) {
  std::ifstream inputFile(filename);
  if (!inputFile) {
    std::cerr << "Error opening file!" << std::endl;
    return false;
  }

  inputFile >> N;
  A.assign(N, std::vector<double>(N));
  b.assign(N, 0);

  for (int i = 0; i < N; i++) {

    inputFile >> b[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      inputFile >> A[i][j];
    }
  }

  inputFile.close();
  return true;
}

#endif