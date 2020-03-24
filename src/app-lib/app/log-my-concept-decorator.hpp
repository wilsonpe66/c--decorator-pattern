#pragma once

#include <iostream>

#include "my-concept.hpp"

namespace app {

template <My_Concept My_Concept_Type>
class Log_My_Concept_Decorator {
  My_Concept_Type s;

 public:
  constexpr Log_My_Concept_Decorator(const My_Concept_Type& s) : s{s} {}
  constexpr auto operator=(const int x) noexcept -> Log_My_Concept_Decorator& {
    std::cout << "Assigned " << x << "\n";
    s = x;
    return *this;
  }
  constexpr auto update() noexcept -> Log_My_Concept_Decorator& {
    std::cout << "Updating from " << s.value() << "\n";
    s.update();
    std::cout << "Updated to " << s.value() << "\n";
    return *this;
  }
  constexpr auto value() const noexcept -> int {
    std::cout << "Has value " << s.value() << "\n";
    return s.value();
    ;
  }
};

template <My_Concept My_Concept_Type>
Log_My_Concept_Decorator(Log_My_Concept_Decorator<My_Concept_Type> value)
    ->Log_My_Concept_Decorator<Log_My_Concept_Decorator<My_Concept_Type>>;
template <My_Concept My_Concept_Type>
Log_My_Concept_Decorator(My_Concept_Type value)
    ->Log_My_Concept_Decorator<My_Concept_Type>;

}  // namespace app