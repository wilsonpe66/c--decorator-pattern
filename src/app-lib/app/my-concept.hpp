#pragma once

#include <concepts>

namespace app {

template <typename T>
concept My_Concept = requires(T s, int x) {
  { s = x }
  ->std::convertible_to<T>;
  { s.update() }
  ->std::convertible_to<T>;
}
&&requires(const T& s, int x) {
  { s.value() }
  ->std::convertible_to<int>;
};

}  // namespace app