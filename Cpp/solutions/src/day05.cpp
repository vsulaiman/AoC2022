#include "day05.hpp"

namespace day05 {
    std::vector<std::vector<char>> get_stacks(std::string input) {
        std::ifstream f;
        f.open(input);
        std::string line;

        std::vector<std::vector<char>> stacks = {{}};
        while (std::getline(f, line) && line.length() > 0)
        {
            // extract chars in brackets
            while (stacks.size() < line.length() / 4 + 1)
            {
                stacks.push_back({});
            }
            for (size_t i = 1; i < line.length(); i += 4)
            {
                if (isupper(line[i]))
                {
                    stacks[i / 4].insert(stacks[i / 4].begin(), line[i]);
                }
            }
        }
        return stacks;
    }
    std::string part1(std::string input, std::vector<std::vector<char>> stacks)
    {
        std::ifstream f;
        f.open(input);
        std::string line;
        while (std::getline(f, line) && line.length() > 0) {}
        std::string::size_type sz;
        int moves[3];
        while (std::getline(f, line))
        {
            sz = 0;
            for (int i = 0; i < 3; i++)
            {
                while (!isdigit(line[sz]))
                {
                    sz++;
                }
                line = line.substr(sz);
                moves[i] = std::stoi(line, &sz);
            }
            for (int i = 0; i < moves[0]; i++)
            {
                stacks[moves[2] - 1].push_back(stacks[moves[1] - 1].back());
                stacks[moves[1] - 1].pop_back();
            }
        }
        std::stringstream ss;
        for (int i = 0; i < stacks.size(); i++)
        {
            ss << stacks[i].back();
        }
        return ss.str();
    }
    std::string part2(std::string input, std::vector<std::vector<char>> stacks) {
        std::ifstream f;
        f.open(input);
        std::string line;
        while (std::getline(f, line) && line.length() > 0)
        {
        }
        std::string::size_type sz;
        int moves[3];
        while (std::getline(f, line))
        {
            sz = 0;
            for (int i = 0; i < 3; i++)
            {
                while (!isdigit(line[sz]))
                {
                    sz++;
                }
                line = line.substr(sz);
                moves[i] = std::stoi(line, &sz);
            }
            for (int i = 0; i < moves[0]; i++)
            {
                stacks[moves[2] - 1].push_back(stacks[moves[1] - 1].at(stacks[moves[1] - 1].size() - moves[0] + i));
            }
            for (int i = 0; i < moves[0]; i++)
            {
                stacks[moves[1] - 1].pop_back();
            }
        }
        std::stringstream ss;
        for (int i = 0; i < stacks.size(); i++)
        {
            ss << stacks[i].back();
        }
        return ss.str();
    }
}