#include <iostream>
#include <vector>
#include <ranges>

auto isMod3(int num) -> bool { return (num % 3 == 0)? true : false; }

auto main(int , char**) -> int {

  for (auto x : std::ranges::iota_view(1)
                | std::ranges::views::filter(isMod3)
                | std::ranges::views::take(10)) {
    std::cout << x << std::endl;
  }

  std::vector<int> v{1,2,3,4,5};
  v | std::views::reverse; // useless, v not changed
  for (auto x : v | std::views::reverse) {
    std::cout << x << " ";
  }
  
  return 0;
}
