/*
* @file 2-higher-order-function-2.cc
* @author Gresces
* @brief Another exmaple for high-order-function. In this example program,
*        the template function can get function param.
*/

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

// The data to be process
typedef struct People {
  std::string name;
  enum{
    MALE = 0,
    FEMALE = 1
  } sex;

  std::string operator=(People a) {
    return a.name;
  }

  friend std::ostream& operator<<(std::ostream &output, const People &D) {
    return output << "{" <<
           "Name: " << D.name << ", " <<
           "Sex: " << std::string(D.sex == MALE ? "MALE" : "FEMALE") << "}";
  }
} People;

std::vector<People> people = {
  {"A", People::MALE},
  {"B", People::FEMALE},
  {"C", People::MALE},
  {"D", People::FEMALE},
  {"E", People::FEMALE}
};

// After this line is the functions of high-order-functions.
template<typename FilterFunction, typename T>
auto names_for(const std::vector<T>& people, FilterFunction filter)
-> std::vector<T> {

  std::vector<T> result;
  for (const auto& person : people) {
    if(filter(person)) {
      result.push_back(person);
    }
  }
  return result;
}

auto main(int argc, char* argv[]) -> int {

  std::cout << "Before filter: " << std::endl;

  for (auto& ele : people) {
    std::cout << ele << std::endl;
  }

  const auto testFilter = [](People in) -> bool {
    return in.sex == People::MALE;
  };

  auto result = names_for(people, testFilter);

  std::cout << "After function<names_for>" << std::endl;
  
  for (auto& ele : result) {
    std::cout << ele << std::endl;
  }

  return 0;
}
 
