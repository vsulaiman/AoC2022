#ifndef DAY12_HPP
#define DAY12_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>
#include <functional>

namespace day12 {
    struct Square {
        int height;
        int distance = std::numeric_limits<int>::max();
        std::pair<int, int> predecessor;
    };
    bool compareDistance(const std::vector<std::vector<Square>> &grid, const std::pair<int, int> &a, const std::pair<int, int> &b);
    bool inGrid(const std::vector<std::vector<Square>> &grid, std::pair<int, int> coord);
    std::vector<std::vector<Square>> parseInput(std::string input, std::pair<int, int> &start, std::pair<int, int> &end);
    int part1(std::vector<std::vector<Square>> grid, std::pair<int, int> start, std::pair<int, int> end);
    int part2(std::vector<std::vector<Square>> grid, std::pair<int, int> end);
}

#endif // DAY12_HPP