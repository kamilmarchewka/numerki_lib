#include <iomanip>
#include <iostream>
#include <vector>

#include "Lagrange.hpp"
#include "LagrangeSBKwadr.hpp"
#include "ReadFileToVec.hpp"

using namespace std;

int main() {

  vector<double> x, y, x_to_interpolation, y_to_interpolation;
  readFileToVec("data.txt", x, y);

  //   Choose x for interpolation (every 5th element)
  for (size_t i = 0; i < x.size(); i += 5) {
    x_to_interpolation.push_back(x[i]);
    y_to_interpolation.push_back(y[i]);
  }

  cout << "blad :"
       << lagrangeSBKwadr(x, y, x_to_interpolation, y_to_interpolation) << endl;

  double user_input;
  cout << "Podaj x do interpolacji: ";
  cin >> user_input;

  cout << "Interpolowana wartosc: "
       << lagrange(user_input, x_to_interpolation, y_to_interpolation) << endl;

  // Data for schema
  for (size_t i = 0; i < x.size(); i++) {

    cout << i << ". " << lagrange(x[i], x_to_interpolation, y_to_interpolation)
         << endl;
  }

  // Zapis danych do pliku CSV
  std::ofstream outFile("interpolacja.csv");
  if (!outFile) {
    std::cerr << "Nie można otworzyć pliku do zapisu!" << std::endl;
    return 1;
  }

  // Nagłówek
  outFile << "x,y,y_interp,is_node\n";

  // Dane
  for (size_t i = 0; i < x.size(); ++i) {
    double xi = x[i];
    double yi = y[i];
    double yi_interp = lagrange(xi, x_to_interpolation, y_to_interpolation);

    // Sprawdzenie, czy punkt to węzeł
    bool is_node = false;
    for (double x_node : x_to_interpolation) {
      if (xi == x_node) {
        is_node = true;
        break;
      }
    }

    outFile << std::fixed << std::setprecision(6) << xi << "," << yi << ","
            << yi_interp << "," << (is_node ? 1 : 0) << "\n";
  }

  outFile.close();
  std::cout << "Dane zapisane do pliku interpolacja.csv" << std::endl;

  return 0;
}
