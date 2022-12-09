#ifndef DAY05_HPP
#define DAY05_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

namespace day05 {
    std::vector<std::vector<char>> get_stacks(std::string input);
    std::string part1(std::string input, std::vector<std::vector<char>> stacks);
    std::string part2(std::string input, std::vector<std::vector<char>> stacks);
}

#endif // DAY05_HPP