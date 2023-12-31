#pragma once
#include <iostream>
#include <vector>

template<typename S>
std::ostream& operator<<(std::ostream& os, const std::vector<S>& vector) {
  for (auto element : vector) {
    os << element << " ";
  }
  return os;
}
