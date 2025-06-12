#ifndef READFILETOVECTORS_HPP
#define READFILETOVECTORS_HPP

#include <fstream>
#include <iostream>
#include <sstream>

/**
 * @brief Odczytuje dwie linie z pliku i zapisuje wartości do dwóch wektorów.
 *
 * @param filePath Ścieżka do pliku, który ma zostać odczytany.
 * @param vec1 Pierwszy wektor, do którego zostaną zapisane wartości z pierwszej
 * linii.
 * @param vec2 Drugi wektor, do którego zostaną zapisane wartości z drugiej
 * linii.
 * @return true jeśli plik został pomyślnie odczytany, false w przeciwnym razie.
 */
bool readFileToVec(const std::string &filePath, std::vector<double> &vec1,
                   std::vector<double> &vec2) {

  std::ifstream file(filePath);

  // Check if file was opened successfully
  if (!file) {
    std::cerr << "Nie można otworzyć pliku!" << std::endl;
    return false;
  }

  std::string line;
  double value;

  // Read the first line
  if (std::getline(file, line)) {
    std::istringstream iss(line);
    while (iss >> value) {
      vec1.push_back(value);
    }
  }

  // Read the second line
  if (std::getline(file, line)) {
    std::istringstream iss(line);
    while (iss >> value) {
      vec2.push_back(value);
    }
  }

  file.close();

  return true;
}

#endif