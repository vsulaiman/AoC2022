#ifndef DAY16_HPP
#define DAY16_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

namespace day16 {
    struct Valve
    {
        std::string name;
        int flow_rate;
        std::vector<std::string> tunnels;
        std::unordered_map<std::string, int> distances;
    };
    std::unordered_map<std::string, Valve> parseInput(std::string input);
    void floyd_warshall(std::unordered_map<std::string, Valve> &valves);
    int dfs(int max_time, int current_time, std::string valve, std::unordered_map<std::string, Valve> &valves, std::vector<std::string> &relevant_valves, std::set<std::string> opened);
    int part1(std::unordered_map<std::string, Valve> valves);
    int part2(std::unordered_map<std::string, Valve> valves);
}

#endif // DAY16_HPP