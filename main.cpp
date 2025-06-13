#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

// #include "check.hpp"
// #include "gaussElimination.hpp"
// #include "printMatrix.hpp"
// #include "printVector.hpp"
// #include "readFromFile.hpp"

using namespace std;

bool readFileToMatrix(const string &filename, vector<vector<double>> &A,
                      vector<double> &b, int &N) {
  ifstream inputFile(filename);
  if (!inputFile) {
    cerr << "Error opening file!" << endl;
    return false;
  }

  inputFile >> N;
  A.assign(N, vector<double>(N));
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

void printMatrix(vector<vector<double>> &A, vector<double> &b) {
  int N = A.size();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << setw(10) << A[i][j] << " ";
    }
    cout << " | " << setw(10) << b[i] << endl;
  }
  cout << endl;
}

std::vector<double> check(const std::vector<std::vector<double>> &A,
                          const std::vector<double> &b,
                          const std::vector<double> &x,
                          double tolerance = 1e-9) {
  int N = A.size();
  std::vector<double> residual(N, 0.0);

  for (int i = 0; i < N; i++) {
    double sum = 0.0;
    for (int j = 0; j < N; j++) {
      sum += A[i][j] * x[j];
    }
    residual[i] = sum - b[i];

    // Jeśli wartość jest bardzo mała, traktujmy ją jako zero
    if (std::fabs(residual[i]) < tolerance) {
      residual[i] = 0.0;
    }
  }

  return residual;
}

void printVector(const std::string &title, const std::vector<double> &vec) {
  std::cout << title << std::endl;
  for (const double &val : vec) {
    std::cout << val << " ";
  }
  std::cout << std::endl << std::endl;
}

void luDecomposition(vector<vector<double>> &A, vector<vector<double>> &L,
                     vector<vector<double>> &U, int n) {

  vector<double> x(n, 0);

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

    cout << "macierz L:" << endl;
    printMatrix(L, x);
    cout << "macierz U:" << endl;
    printMatrix(U, x);
  }
}

vector<double> forwardSubstitution(vector<vector<double>> &L, vector<double> &b,
                                   int n) {
  vector<double> y(n);
  for (int i = 0; i < n; i++) {
    double sum = 0;
    for (int j = 0; j < i; j++)
      sum += L[i][j] * y[j];
    y[i] = (b[i] - sum) / L[i][i];
  }
  return y;
}

vector<double> backwardSubstitution(vector<vector<double>> &U,
                                    vector<double> &y, int n) {
  vector<double> x(n);
  for (int i = n - 1; i >= 0; i--) {
    double sum = 0;
    for (int j = i + 1; j < n; j++)
      sum += U[i][j] * x[j];
    x[i] = (y[i] - sum) / U[i][i];
  }
  return x;
}

vector<double> solveLU(vector<vector<double>> &A, vector<double> &b, int n) {
  vector<vector<double>> L(n, vector<double>(n, 0)), U(n, vector<double>(n, 0));
  luDecomposition(A, L, U, n);

  vector<double> z = forwardSubstitution(L, b, n);
  printVector("z", z);
  return backwardSubstitution(U, z, n);
}

int main() {

  vector<vector<double>> A;
  vector<double> b;
  int N;

  // Wczytanie danych z pliku
  if (!readFileToMatrix("data.txt", A, b, N)) {
    return 1;
  }

  vector<double> x(N, 0);
  vector<double> z(N, 0);

  cout << "Wczytane dane:" << endl;
  cout << "N = " << N << endl;
  cout << "A = " << endl;
  printMatrix(A, b);
  printVector("b", b);
  printVector("x", x);
  printVector("z", z);

  x = solveLU(A, b, N);
  printVector("Rozwiazanie", x);

  vector<double> residual = check(A, b, x);
  printVector("sprawdzenie", residual);

  return 0;
}
