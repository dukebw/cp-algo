// http://codeforces.com/contest/59/problem/E
#include <iostream>
#include <vector>

int main() {
  int num_cities;
  std::cin >> num_cities;
  int num_roads;
  std::cin >> num_roads;
  int num_forbidden_triplets;
  std::cin >> num_forbidden_triplets;

  std::vector<std::pair<int, int>> roads(num_roads);
  for (int i = 0; i < num_roads; ++i) {
    std::cin >> roads[i].first >> roads[i].second;
  }
}
