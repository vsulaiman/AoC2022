#include "day01.hpp"

namespace day01 {
    std::vector<int> sum_calories(std::string input)
    {
        std::ifstream f;
        f.open(input);

        std::string line;
        std::vector<int> calories;
        int sum = 0;
        while (std::getline(f, line))
        {
            if (line.length() == 0)
            {
                calories.push_back(sum);
                sum = 0;
                continue;
            }
            sum += std::stoi(line);
        }
        return calories;
    }

    int part1(std::vector<int>& calories)
    {
        int max_calories = 0;
        for (int i = 0; i < calories.size(); i++)
        {
            if (calories[i] > max_calories)
            {
                max_calories = calories[i];
            }
        }
        return max_calories;
    }

    int part2(std::vector<int>& calories)
    {
        int max_calories[3] = {0};
        for (int i = 0; i < calories.size(); i++)
        {
            if (calories[i] > max_calories[2])
            {
                max_calories[2] = calories[i];
                if (max_calories[2] > max_calories[1])
                {
                    std::swap(max_calories[1], max_calories[2]);
                    if (max_calories[1] > max_calories[0])
                    {
                        std::swap(max_calories[0], max_calories[1]);
                    }
                }
            }
        }
        return max_calories[0] + max_calories[1] + max_calories[2];
    }
}