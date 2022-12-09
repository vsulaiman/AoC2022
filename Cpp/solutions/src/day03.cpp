#include "day03.hpp"

namespace day03 {
    int priority(char c)
    {
        if (isupper(c))
        {
            return int(c) - 64 + 26;
        }
        else
        {
            return int(c) - 96;
        }
    }

    int part1(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;

        int sum = 0;
        while (std::getline(f, line))
        {
            // part 1
            auto result = std::find_first_of(line.begin(), line.begin() + line.length() / 2,
                                             line.begin() + line.length() / 2, line.end());
            if (result != line.begin() + line.length() / 2)
            {
                sum += priority(*result);
            }
        }
        return sum;
    }

    int part2(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;

        int sum = 0;
        int i = 0;
        std::string lines[3];
        while (std::getline(f, line))
        {
            lines[i] = line;
            if (i == 2)
            {
                for (auto it = lines[0].begin(); it != lines[0].end(); ++it)
                {
                    if (std::find(lines[1].begin(), lines[1].end(), (*it)) != lines[1].end() &&
                        std::find(lines[2].begin(), lines[2].end(), (*it)) != lines[2].end())
                    {
                        sum += priority(*it);
                        break;
                    }
                }
            }
            i = (i + 1) % 3;
        }
        return sum;
    }
}