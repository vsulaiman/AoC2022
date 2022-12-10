#ifndef DAY10_HPP
#define DAY10_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

namespace day10 {
    std::vector<int> parse_input(std::string input);
    int part1(std::vector<int> &register_entries);
    std::string part2(std::vector<int> &register_entries);
}

#endif // DAY10_HPP