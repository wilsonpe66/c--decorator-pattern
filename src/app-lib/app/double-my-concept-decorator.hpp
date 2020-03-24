#pragma once

#include "my-concept.hpp"

namespace app {

template <My_Concept My_Concept_Type>
class Double_My_Concept_Decorator {
  My_Concept_Type s;

 public:
  constexpr Double_My_Concept_Decorator(const My_Concept_Type& s) : s{s} {}
  constexpr auto operator=(const int x) noexcept
      -> Double_My_Concept_Decorator& {
    s = x;
    return *this;
  }
  constexpr auto update() noexcept -> Double_My_Concept_Decorator& {
    s.update().update();
    return *this;
  }
  constexpr auto value() const noexcept -> int {
    return s.value();
    ;
  }
};

template <My_Concept My_Concept_Type>
Double_My_Concept_Decorator(Double_My_Concept_Decorator<My_Concept_Type> value)
    ->Double_My_Concept_Decorator<Double_My_Concept_Decorator<My_Concept_Type>>;
template <My_Concept My_Concept_Type>
Double_My_Concept_Decorator(My_Concept_Type value)
    ->Double_My_Concept_Decorator<My_Concept_Type>;

}  // namespace app