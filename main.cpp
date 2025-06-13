#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <vector>

const double A = -1.0;
const double B = 2.0;
const int N = 1000;

using Func = std::function<double(double)>;

double horner(const std::vector<double> &coeffs, double x) {
  double result = 0.0;
  for (int i = coeffs.size() - 1; i >= 0; --i) {
    result = result * x + coeffs[i];
  }
  return result;
}

double simpson_f(const Func &f, double a, double b, int n) {
  if (n % 2 != 0)
    ++n;
  double dx = (b - a) / n;
  double sum = f(a) + f(b);
  for (int i = 1; i < n; ++i)
    sum += f(a + i * dx) * (i % 2 == 0 ? 2 : 4);
  return sum * dx / 3.0;
}

void leastSquares(const Func &f, int degree, std::vector<double> &coeffs) {
  coeffs.resize(degree + 1);
  std::vector<std::vector<double>> G(degree + 1,
                                     std::vector<double>(degree + 1));
  std::vector<double> b(degree + 1);

  for (int i = 0; i <= degree; ++i) {
    for (int j = 0; j <= degree; ++j) {
      G[i][j] =
          simpson_f([=](double x) { return std::pow(x, i + j); }, A, B, N);
    }
  }

  for (int i = 0; i <= degree; ++i) {
    b[i] =
        simpson_f([=, &f](double x) { return f(x) * std::pow(x, i); }, A, B, N);
  }

  for (int i = 0; i <= degree; ++i) {
    for (int j = i + 1; j <= degree; ++j) {
      double factor = G[j][i] / G[i][i];
      for (int k = i; k <= degree; ++k) {
        G[j][k] -= factor * G[i][k];
      }
      b[j] -= factor * b[i];
    }
  }

  for (int i = degree; i >= 0; --i) {
    coeffs[i] = b[i];
    for (int j = i + 1; j <= degree; ++j) {
      coeffs[i] -= G[i][j] * coeffs[j];
    }
    coeffs[i] /= G[i][i];
  }
}

double computeError(const Func &f, const std::vector<double> &coeffs) {
  return simpson_f(
      [&](double x) {
        double err = f(x) - horner(coeffs, x);
        return err * err;
      },
      A, B, N);
}

int main() {
  Func f = [](double x) {
    return std::exp(x) * std::cos(5 * x) - std::pow(x, 3);
  };

  std::vector<double> coeffs;

  for (int deg = 0; deg <= 10; deg += 1) {
    leastSquares(f, deg, coeffs);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Współczynniki aproksymującego wielomianu stopnia " << deg
              << ":\n";
    for (int i = 0; i < coeffs.size(); ++i) {
      std::cout << "c[" << i << "] = " << coeffs[i] << "\n";
    }

    double error = computeError(f, coeffs);
    std::cout << "\nBłąd średniokwadratowy (L²): " << error << "\n";
  }

  return 0;
}
