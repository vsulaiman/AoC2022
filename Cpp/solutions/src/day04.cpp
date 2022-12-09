#include "day04.hpp"

namespace day04 {
    int part1(std::string input) {
        std::ifstream f;
        f.open(input);
        std::string line;

        int sum = 0;
        int beg1, end1, beg2, end2 = 0;
        size_t pos1, pos2;
        while (std::getline(f, line))
        {
            pos1 = line.find(',');
            pos2 = line.find('-');
            beg1 = std::stoi(line.substr(0, pos2));
            end1 = std::stoi(line.substr(pos2 + 1, pos1));
            pos2 = line.find('-', pos1);
            beg2 = std::stoi(line.substr(pos1 + 1, pos2));
            end2 = std::stoi(line.substr(pos2 + 1));
            if (beg1 <= beg2 && end1 >= end2)
            {
                sum++;
            }
            else if (beg1 >= beg2 && end1 <= end2)
            {
                sum++;
            }
        }
        return sum;
    }
    int part2(std::string input) {
        std::ifstream f;
        f.open(input);
        std::string line;

        int sum = 0;
        int beg1, end1, beg2, end2 = 0;
        size_t pos1, pos2;
        while (std::getline(f, line))
        {
            pos1 = line.find(',');
            pos2 = line.find('-');
            beg1 = std::stoi(line.substr(0, pos2));
            end1 = std::stoi(line.substr(pos2 + 1, pos1));
            pos2 = line.find('-', pos1);
            beg2 = std::stoi(line.substr(pos1 + 1, pos2));
            end2 = std::stoi(line.substr(pos2 + 1));
            if (beg1 <= beg2 && end1 >= end2)
            {
                sum++;
            }
            else if (beg1 >= beg2 && end1 <= end2)
            {
                sum++;
            }
            else if (beg1 <= beg2 && end1 >= beg2)
            {
                sum++;
            }
            else if (beg1 >= beg2 && beg1 <= end2)
            {
                sum++;
            }
        }
        return sum;
    }
}