
#include <app/double-my-concept-decorator.hpp>
#include <app/my-concept.hpp>
#include <app/my-type.hpp>

using app::Double_My_Concept_Decorator;
using app::My_Concept;
using app::My_Type;

auto tmain(My_Concept auto&& my_concept) noexcept -> int {
  my_concept = 87;
  return my_concept.update()
      .update()
      .update()
      .update()
      .update()
      .update()
      .update()
      .value();
}

auto main() -> int {
  return tmain(
      Double_My_Concept_Decorator{Double_My_Concept_Decorator{My_Type{}}});
}