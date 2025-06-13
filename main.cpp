#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#include "EulerMethod.hpp"
#include "MetodaBisekcji.hpp"
#include "MetodaHeuna.hpp"
#include "MetodaNewtona.hpp"
#include "MetodaPktSr.hpp"
#include "MetodaRK4.hpp"
#include "MetodaSiecznych.hpp"
#include "PrintMatrix.hpp"
#include "PrintVector.hpp"
#include "ReadFileToMatrix.hpp"
#include "RegulaFalsi.hpp"
#include "SolveLU.hpp"
#include "SrBladKwadrat.hpp"

using namespace std;

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

  return 0;
}
