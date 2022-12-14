#include "day14.hpp"

namespace day14 {
    int part1(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;
        int x_min = 500;
        int x_max = 500;
        int y_max = 0;
        int x1, y1, x2, y2;
        std::set<std::pair<int, int>> rocks_sand;
        while (std::getline(f, line))
        {
            std::string::size_type sz;
            x1 = std::stoi(line, &sz);
            line = line.substr(sz + 1);
            y1 = std::stoi(line, &sz);
            rocks_sand.insert(std::make_pair(x1, y1));
            line = line.substr(sz + 4);
            if (x1 < x_min)
            {
                x_min = x1;
            }
            if (x1 > x_max)
            {
                x_max = x1;
            }
            if (y1 > y_max)
            {
                y_max = y1;
            }
            while (line.size() > 0)
            {
                x2 = std::stoi(line, &sz);
                line = line.substr(sz + 1);
                y2 = std::stoi(line, &sz);
                rocks_sand.insert(std::make_pair(x2, y2));
                if (x2 < x_min)
                {
                    x_min = x2;
                }
                if (x2 > x_max)
                {
                    x_max = x2;
                }
                if (y2 > y_max)
                {
                    y_max = y2;
                }
                if (line.begin() + sz == line.end()) {break;}
                line = line.substr(sz + 4);
                // todo: include all points between x1, y1 and x2, y2
                x1 = x2;
                y1 = y2;
            }
        }
        // for (auto it = rocks_sand.begin(); it != rocks_sand.end(); ++it)
        // {
        //     std::cout << it->first << " " << it->second << std::endl;
        // }
        std::cout << "(" << x_min << "," << x_max << ") & " << y_max << std::endl;
        return 0;
    }
    int part2(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;
        while (std::getline(f, line))
        {

        }
        return 0;
    }
}