#ifndef PRINTVECTOR_HPP
#define PRINTVECTOR_HPP

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Prints the contents of a vector with a title.
 *
 * @param title The title to print before the vector contents.
 * @param vec The vector to print.
 */
void printVector(const std::string &title, const std::vector<double> &vec) {
  std::cout << title << std::endl;
  for (const double &val : vec) {
    std::cout << val << " ";
  }
  std::cout << std::endl << std::endl;
}

#endif