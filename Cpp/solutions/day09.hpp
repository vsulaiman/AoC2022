#ifndef DAY09_HPP
#define DAY09_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>
#include <vector>

namespace day09 {
    int sgn(int val);
    void update_tail(std::pair<int, int> &head_pos, std::pair<int, int> &tail_pos);
    void move_head(std::pair<int, int> &head_pos, char direction);
    int part1(std::string input);
    int part2(std::string input);
}

#endif // DAY09_HPP