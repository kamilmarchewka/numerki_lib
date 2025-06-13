#ifndef PRINTMATRIX_HPP
#define PRINTMATRIX_HPP

#include <iomanip>
#include <iostream>
#include <vector>

/**
 * @brief Wyświetla macierz rozszerzoną [A|b] w sformatowany sposób.
 *
 * @param A Macierz współczynników.
 * @param b Wektor wyrazów wolnych (prawa strona równania).
 */
void printMatrix(std::vector<std::vector<double>> &A, std::vector<double> &b) {
  int N = A.size();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << std::setw(10) << A[i][j] << " ";
    }
    std::cout << " | " << std::setw(10) << b[i] << std::endl;
  }
  std::cout << std::endl;
}

#endif