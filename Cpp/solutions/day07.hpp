#ifndef DAY07_HPP
#define DAY07_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

namespace day07 {
    std::map<std::string, int> parse_input(std::string input);
    int part1(const std::map<std::string, int> &folder_sizes);
    int part2(std::map<std::string, int> &folder_sizes);
}

#endif // DAY07_HPP