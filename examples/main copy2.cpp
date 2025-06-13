#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#include "EulerMethod.hpp"

using namespace std;

// Funkcja opisująca równanie różniczkowe
double dTdt(double T, double T_env, double k) {
  return -k * (pow(T, 4) - pow(T_env, 4));
}

int main() {
  int album = 9688; // 9688
  double T0 = album;
  double T_env = 0;
  double k = 8e-12;
  double t_max = 500;

  // Krok całkowania
  vector<double> krok_h = {0.1, 0.01, 0.05};

  // Obliczenia i zapis wyników
  for (double h : krok_h) {
    double index = h * 100;
    vector<double> temps, times;

    eulerMethod(dTdt, T0, T_env, k, t_max, h, temps, times);

    // Zapisz dane do pliku
    string filename = "wyniki_h_" + to_string((int)index) + ".csv";
    ofstream out(filename);
    out << "t,T\n";
    for (size_t i = 0; i < times.size(); ++i) {
      out << fixed << setprecision(2) << times[i] << "," << temps[i] << "\n";
    }
    out.close();
    cout << "Wyniki zapisane do " << filename << endl;
  }

  return 0;
}
