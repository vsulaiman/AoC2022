#ifndef DAY08_HPP
#define DAY08_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace day08 {
    bool visible(const std::vector<std::vector<int>>& grid, int i, int j);
    int scenic_score(const std::vector<std::vector<int>>& grid, int i, int j);
    std::vector<std::vector<int>> parse_input(std::string input);
    int part1(const std::vector<std::vector<int>> &grid);
    int part2(const std::vector<std::vector<int>> &grid);
}

#endif // DAY08_HPP