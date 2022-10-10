// http://codeforces.com/contest/59/problem/E
// no paths from 1 to n -> -1
// otherwise, print the number of roads along the shortest path from 1 to n
// on the second line print the shortest path from 1 to n
#include <iostream>
#include <queue>
#include <set>
#include <vector>

struct Triplet {
  int first;
  int second;
  int third;

  bool operator<(const Triplet &other) const {
    if (first != other.first) {
      return first < other.first;
    }
    if (second != other.second) {
      return second < other.second;
    }
    return third < other.third;
  }
};

struct Graph {
  Graph(int n, const std::vector<std::pair<int, int>> &roads) : adj(n) {
    for (auto r : roads) {
      adj[r.first].push_back(r.second);
      adj[r.second].push_back(r.first);
    }
  }

  std::vector<std::vector<int>> adj;
};

int main() {
  int num_cities;
  int num_roads;
  int num_forbidden_triplets;
  std::cin >> num_cities >> num_roads >> num_forbidden_triplets;
  if (num_cities <= 0) {
    std::cout << -1 << std::endl;
    return 0;
  }

  std::vector<std::pair<int, int>> roads(num_roads);
  for (int i = 0; i < num_roads; ++i) {
    std::cin >> roads[i].first >> roads[i].second;
  }

  std::set<Triplet> forbidden_triplets;
  for (int i = 0; i < num_forbidden_triplets; ++i) {
    Triplet trp;
    std::cin >> trp.first >> trp.second >> trp.third;
    forbidden_triplets.insert(trp);
  }

  // graph
  // BFS
  // store previous two cities
  // set of forbidden triplets
  // push neighbours if triplet not forbidden
  Graph g{num_cities, roads};
  std::vector<int> parent(num_cities + 1, -1);
  std::queue<std::pair<int, int>> q;
  std::set<std::pair<int, int>> used;

  q.push({0, 1});
  used.insert({0, 1});
  while (!q.empty()) {
    auto city_pair = q.front();
    q.pop();

    for (int n : g.adj[city_pair.second]) {
      if (used.find({city_pair.second, n}) != used.end()) {
        continue;
      }

      Triplet trp{city_pair.first, city_pair.second, n};
      if (forbidden_triplets.find(trp) != forbidden_triplets.end()) {
        continue;
      }

      parent[n] = city_pair.second;
      used.insert({city_pair.second, n});
      q.push({city_pair.second, n});
    }
  }

  if (parent[num_cities] == -1) {
    std::cout << -1 << std::endl;
    return 0;
  }

  std::vector<int> path{num_cities};
  for (int v = parent[num_cities]; v != -1; v = parent[v]) {
    path.push_back(v);
  }
  std::reverse(path.begin(), path.end());

  std::cout << path.size() - 1 << std::endl;
  for (int v : path) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
  return 0;
}
