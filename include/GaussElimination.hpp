#ifndef GAUSSELIMINATION_HPP
#define GAUSSELIMINATION_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "PrintMatrix.hpp"

using namespace std;
/**
 * @brief Wykonuje eliminację Gaussa na macierzy rozszerzonej [A|b], aby
 * rozwiązać układ równań liniowych Ax = b.
 *
 * @param A Macierz współczynników.
 * @param b Wektor wyrazów wolnych (prawa strona równania).
 * @param x Wektor rozwiązania (wyjście).
 */
void gaussianElimination(vector<vector<double>> &A, vector<double> &b,
                         vector<double> &x) {
  int N = A.size();
  for (int k = 0; k < N; k++) {
    // Partial pivoting: find max absolute value in column k below diagonal
    int maxRow = k;
    for (int i = k + 1; i < N; i++) {
      if (abs(A[i][k]) > abs(A[maxRow][k])) {
        maxRow = i;
      }
    }

    // Swap rows if needed
    // if (maxRow != k) {
    swap(A[k], A[maxRow]);
    swap(b[k], b[maxRow]);
    // }

    // Make sure we don't divide by zero
    if (abs(A[k][k]) < 1e-10) {
      cerr << "Nieskonczenie wiele rozwiazan / uklad jest sprzeczny" << endl;
      return;
    }

    // Elimination process
    for (int i = k + 1; i < N; i++) {
      double factor = A[i][k] / A[k][k];
      for (int j = k; j < N; j++) {
        A[i][j] -= factor * A[k][j];
      }
      b[i] -= factor * b[k];
    }

    // Print matrix at each step
    cout << "Step " << k + 1 << ":\n";
    printMatrix(A, b);
  }

  // Back-substitution
  for (int i = N - 1; i >= 0; i--) {
    double sum = b[i];
    for (int j = i + 1; j < N; j++) {
      sum -= A[i][j] * x[j];
    }
    x[i] = sum / A[i][i];
  }
}

#endif