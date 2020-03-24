#pragma once

namespace app {

class My_Type {
  int x = 0;

 public:
  constexpr auto operator=(const int x) noexcept -> My_Type& {
    this->x = x;
    return *this;
  }

  constexpr auto update() noexcept -> My_Type& {
    x = (x + 1) << 1;
    return *this;
  }
  constexpr auto value() const noexcept -> int { return x; }
};

}  // namespace app