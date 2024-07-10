/**
 * @file: examples/3-function-objects.cc
 * @author: Gresces
 * @date: 2024-7-9
 * @brief: How to imply a method on a object.
*/

#include <utility>
template<class T, typename Function>
decltype(auto) call_on_object(T&& object, Function function) {
  return function(std::forward(object));
}
