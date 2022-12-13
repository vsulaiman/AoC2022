#ifndef DAY13_HPP
#define DAY13_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

namespace day13 {
    std::vector<std::string> splitList(std::string input);
    int compareLists(std::vector<std::string> left, std::vector<std::string> right);
    bool isSmaller(std::string left, std::string right);
    int part1(std::string input);
    int part2(std::string input);
}

#endif // DAY13_HPP