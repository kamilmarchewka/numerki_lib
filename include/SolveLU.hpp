#ifndef SOLVELU_HPP
#define SOLVELU_HPP

#include <iostream>
#include <vector>

#include "PrintMatrix.hpp"
#include "PrintVector.hpp"

/**
 * @brief Wykonuje dekompozycję LU macierzy A na macierze L i U.
 *
 * Funkcja rozkłada macierz wejściową A tak, że A = L * U, gdzie:
 * - L to macierz trójkątna dolna (z jedynkami na przekątnej),
 * - U to macierz trójkątna górna.
 *
 * @param A Macierz wejściowa do dekompozycji (rozmiar n x n).
 * @param L Macierz wynikowa trójkątna dolna (rozmiar n x n).
 * @param U Macierz wynikowa trójkątna górna (rozmiar n x n).
 * @param n Rozmiar macierzy (liczba wierszy i kolumn).
 */
void luDecomposition(std::vector<std::vector<double>> &A,
                     std::vector<std::vector<double>> &L,
                     std::vector<std::vector<double>> &U, int n) {

  std::vector<double> x(n, 0);

  for (int i = 0; i < n; i++) {
    for (int k = i; k < n; k++) {
      double sum = 0;
      for (int j = 0; j < i; j++)
        sum += L[i][j] * U[j][k];
      U[i][k] = A[i][k] - sum;
    }

    for (int k = i; k < n; k++) {
      if (i == k)
        L[i][i] = 1;
      else {
        double sum = 0;
        for (int j = 0; j < i; j++)
          sum += L[k][j] * U[j][i];
        L[k][i] = (A[k][i] - sum) / U[i][i];
      }
    }

    std::cout << "macierz L:" << std::endl;
    printMatrix(L, x);
    std::cout << "macierz U:" << std::endl;
    printMatrix(U, x);
  }
}

/**
 * @brief Wykonuje podstawienie wsteczne dla macierzy L i wektora b.
 *
 * Funkcja rozwiązuje układ równań liniowych Ly = b, gdzie L jest macierzą
 * trójkątną dolną.
 *
 * @param L Macierz trójkątna dolna (rozmiar n x n).
 * @param b Wektor wynikowy (rozmiar n).
 * @param n Rozmiar macierzy i wektora.
 * @return Wektor y, który jest rozwiązaniem układu równań.
 */
std::vector<double> forwardSubstitution(std::vector<std::vector<double>> &L,
                                        std::vector<double> &b, int n) {
  std::vector<double> y(n);
  for (int i = 0; i < n; i++) {
    double sum = 0;
    for (int j = 0; j < i; j++)
      sum += L[i][j] * y[j];
    y[i] = (b[i] - sum) / L[i][i];
  }
  return y;
}

/**
 * @brief Wykonuje podstawienie wsteczne dla macierzy U i wektora y.
 *
 * Funkcja rozwiązuje układ równań liniowych Ux = y, gdzie U jest macierzą
 * trójkątną górną.
 *
 * @param U Macierz trójkątna górna (rozmiar n x n).
 * @param y Wektor wynikowy (rozmiar n).
 * @param n Rozmiar macierzy i wektora.
 * @return Wektor x, który jest rozwiązaniem układu równań.
 */
std::vector<double> backwardSubstitution(std::vector<std::vector<double>> &U,
                                         std::vector<double> &y, int n) {
  std::vector<double> x(n);
  for (int i = n - 1; i >= 0; i--) {
    double sum = 0;
    for (int j = i + 1; j < n; j++)
      sum += U[i][j] * x[j];
    x[i] = (y[i] - sum) / U[i][i];
  }
  return x;
}

/**
 * @brief Wykonuje dekompozycję LU macierzy A na macierze L i U.
 *
 * Funkcja rozkłada macierz wejściową A tak, że A = L * U, gdzie:
 * - L to macierz trójkątna dolna (z jedynkami na przekątnej),
 * - U to macierz trójkątna górna.
 *
 * @param A Macierz wejściowa do dekompozycji (rozmiar n x n).
 * @param L Macierz wynikowa trójkątna dolna (rozmiar n x n).
 * @param U Macierz wynikowa trójkątna górna (rozmiar n x n).
 * @param n Rozmiar macierzy (liczba wierszy i kolumn).
 */
std::vector<double> solveLU(std::vector<std::vector<double>> &A,
                            std::vector<double> &b, int n) {
  std::vector<std::vector<double>> L(n, std::vector<double>(n, 0)),
      U(n, std::vector<double>(n, 0));
  luDecomposition(A, L, U, n);

  std::vector<double> z = forwardSubstitution(L, b, n);
  printVector("z", z);
  return backwardSubstitution(U, z, n);
}

#endif