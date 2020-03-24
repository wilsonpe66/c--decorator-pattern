
#include <app/double-my-concept-decorator.hpp>
#include <app/log-my-concept-decorator.hpp>
#include <app/my-concept.hpp>
#include <app/my-type.hpp>
#include <iostream>

using app::Double_My_Concept_Decorator;
using app::Log_My_Concept_Decorator;
using app::My_Concept;
using app::My_Type;

void tmain(My_Concept auto&& my_concept) noexcept {
  std::cout << "Begin: "
               "\n";
  my_concept = 87;
  const auto x = my_concept.update()
                     .update()
                     .update()
                     .update()
                     .update()
                     .update()
                     .update()
                     .value();
  std::cout << "Result: " << x << "\n";
}

int main() {
  std::cout
      << "Log_My_Concept_Decorator -> Double_My_Concept_Decorator -> Double_My_"
         "Concept_Decorator -> My_Type"
         "\n";
  tmain(Log_My_Concept_Decorator{
      Double_My_Concept_Decorator{Double_My_Concept_Decorator{My_Type{}}}});
  std::cout
      << "Double_My_Concept_Decorator -> Double_My_Concept_Decorator -> My_Type"
         "\n";
  tmain(Double_My_Concept_Decorator{Double_My_Concept_Decorator{My_Type{}}});
  std::cout << "Double_My_Concept_Decorator -> My_Type"
               "\n";
  tmain(Double_My_Concept_Decorator{My_Type{}});
  std::cout << "My_Type"
               "\n";
  tmain(My_Type{});
  std::cout << "Log_My_Concept_Decorator -> My_Type"
               "\n";
  tmain(Log_My_Concept_Decorator{My_Type{}});
  return 0;
}