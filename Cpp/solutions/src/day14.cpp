#include "day14.hpp"

namespace day14 {
    int sgn(int val)
    {
        return (0 < val) - (val < 0);
    }
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
                if (line.begin() + sz == line.end()) { line = ""; }
                else { line = line.substr(sz + 4); }
                // include all points between x1, y1 and x2, y2
                int x_diff = x2 - x1;
                int y_diff = y2 - y1;
                for (int i = 1; i < std::abs(x_diff); i++)
                {
                    if (y_diff > 0) {std::cout << "Error!" << std::endl; }
                    rocks_sand.insert(std::make_pair(x1 + sgn(x_diff)*i, y1));
                }
                for (int i = 1; i < std::abs(y_diff); i++)
                {
                    if (x_diff > 0) {std::cout << "Error!" << std::endl; }
                    rocks_sand.insert(std::make_pair(x1, y1 + sgn(y_diff)*i));
                }
                x1 = x2;
                y1 = y2;
            }
        }
        // for (int i=0; i<=y_max; i++)
        // {
        //     for (int j=x_min; j<= x_max; j++)
        //     {
        //         if(rocks_sand.count(std::make_pair(j, i))) { std::cout << "#"; }
        //         else {std::cout << "_"; }
        //     }
        //     std::cout << std::endl;
        // }

        int n_sand = 0;
        while (true)
        {
            int new_x = 500;
            int new_y = 0;
            bool below = !rocks_sand.count(std::make_pair(new_x, new_y+1));
            bool left = !rocks_sand.count(std::make_pair(new_x-1, new_y+1));
            bool right = !rocks_sand.count(std::make_pair(new_x+1, new_y+1));
            while(below || left || right)
            {
                if (below) { new_y++; }
                else if (left) { new_x--; new_y++; }
                else if (right) { new_x++; new_y++; }
                if (new_x < x_min || new_x > x_max || new_y > y_max) 
                { 
                    // for (int i=0; i<=y_max; i++)
                    // {
                    //     for (int j=x_min; j<= x_max; j++)
                    //     {
                    //         if(rocks_sand.count(std::make_pair(j, i))) { std::cout << "#"; }
                    //         else {std::cout << "_"; }
                    //     }
                    //     std::cout << std::endl;
                    // }
                    return n_sand; 
                }
                below = !rocks_sand.count(std::make_pair(new_x, new_y+1));
                left = !rocks_sand.count(std::make_pair(new_x-1, new_y+1));
                right = !rocks_sand.count(std::make_pair(new_x+1, new_y+1));
            }
            rocks_sand.insert(std::make_pair(new_x, new_y));
            n_sand++;
        }
        return 0;
    }
    int part2(std::string input)
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
                if (line.begin() + sz == line.end()) { line = ""; }
                else { line = line.substr(sz + 4); }
                // include all points between x1, y1 and x2, y2
                int x_diff = x2 - x1;
                int y_diff = y2 - y1;
                for (int i = 1; i < std::abs(x_diff); i++)
                {
                    if (y_diff > 0) {std::cout << "Error!" << std::endl; }
                    rocks_sand.insert(std::make_pair(x1 + sgn(x_diff)*i, y1));
                }
                for (int i = 1; i < std::abs(y_diff); i++)
                {
                    if (x_diff > 0) {std::cout << "Error!" << std::endl; }
                    rocks_sand.insert(std::make_pair(x1, y1 + sgn(y_diff)*i));
                }
                x1 = x2;
                y1 = y2;
            }
        }
        // for (int i=0; i<=y_max; i++)
        // {
        //     for (int j=x_min; j<= x_max; j++)
        //     {
        //         if(rocks_sand.count(std::make_pair(j, i))) { std::cout << "#"; }
        //         else {std::cout << "_"; }
        //     }
        //     std::cout << std::endl;
        // }

        int n_sand = 0;
        while (!rocks_sand.count(std::make_pair(500, 0)))
        {
            int new_x = 500;
            int new_y = 0;
            bool below = !rocks_sand.count(std::make_pair(new_x, new_y+1));
            bool left = !rocks_sand.count(std::make_pair(new_x-1, new_y+1));
            bool right = !rocks_sand.count(std::make_pair(new_x+1, new_y+1));
            while(below || left || right)
            {
                if (below) { new_y++; }
                else if (left) { new_x--; new_y++; }
                else if (right) { new_x++; new_y++; }
                if (new_y > y_max) 
                { 
                    break;
                }
                below = !rocks_sand.count(std::make_pair(new_x, new_y+1));
                left = !rocks_sand.count(std::make_pair(new_x-1, new_y+1));
                right = !rocks_sand.count(std::make_pair(new_x+1, new_y+1));
            }
            rocks_sand.insert(std::make_pair(new_x, new_y));
            n_sand++;
        }
        // for (int i=0; i<=y_max; i++)
        // {
        //     for (int j=x_min; j<= x_max; j++)
        //     {
        //         if(rocks_sand.count(std::make_pair(j, i))) { std::cout << "#"; }
        //         else {std::cout << "_"; }
        //     }
        //     std::cout << std::endl;
        // }
        return n_sand;
    }
}