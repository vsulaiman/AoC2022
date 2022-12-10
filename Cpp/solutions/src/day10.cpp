#include "day10.hpp"

namespace day10 {
    std::vector<int> parse_input(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;

        std::vector<int> register_entries = {1};

        while (std::getline(f, line))
        {
            if (line == "noop")
            {
                register_entries.push_back(register_entries.back());
                continue;
            }
            if (line.find("addx") != std::string::npos)
            {
                register_entries.push_back(register_entries.back());
                register_entries.push_back(register_entries.back() + std::stoi(line.substr(5)));
                continue;
            }
            std::cout << "Error: " << line << std::endl;
        }
        return register_entries;
    }
    int part1(std::vector<int>& register_entries)
    {
        int sum = 0;
        sum += 20 * register_entries[19];
        sum += 60 * register_entries[59];
        sum += 100 * register_entries[99];
        sum += 140 * register_entries[139];
        sum += 180 * register_entries[179];
        sum += 220 * register_entries[219];
        return sum;
    }
    std::string part2(std::vector<int> &register_entries)
    {
        std::stringstream ss;
        for (int i = 0; i < register_entries.size() - 1; i++)
        {
            if ((register_entries[i]-1 == i % 40) || (register_entries[i] == i % 40) || (register_entries[i]+1 == (i % 40)))
            {
                ss << "#";
            }
            else
            {
                ss << ".";
            }

            if ((i+1) % 40 == 0)
            {
                ss << "\n";
            }
        }
        return ss.str();
    }
}