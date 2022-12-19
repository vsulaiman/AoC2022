#include "day18.hpp"

namespace day18 {
    int part1(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;

        std::set<std::array<int, 3>> cubes;
        int x, y, z;
        while (std::getline(f, line))
        {
            x = std::stoi(line);
            y = std::stoi(line.substr(line.find(',') + 1));
            z = std::stoi(line.substr(line.find_last_of(',') + 1));
            cubes.insert({x, y, z});
        }

        int area = 6 * cubes.size();
        for (auto cube : cubes)
        {
            if (cubes.find({cube[0] + 1, cube[1], cube[2]}) != cubes.end())
                area--;
            if (cubes.find({cube[0] - 1, cube[1], cube[2]}) != cubes.end())
                area--;
            if (cubes.find({cube[0], cube[1] + 1, cube[2]}) != cubes.end())
                area--;
            if (cubes.find({cube[0], cube[1] - 1, cube[2]}) != cubes.end())
                area--;
            if (cubes.find({cube[0], cube[1], cube[2] + 1}) != cubes.end())
                area--;
            if (cubes.find({cube[0], cube[1], cube[2] - 1}) != cubes.end())
                area--;
        }
        return area;
    }
    int part2(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;

        std::set<std::array<int, 3>> cubes;
        int x, y, z;
        int x_min = 1, x_max = 1, y_min = 1, y_max = 1, z_min = 1, z_max = 1;
        while (std::getline(f, line))
        {
            x = std::stoi(line);
            y = std::stoi(line.substr(line.find(',') + 1));
            z = std::stoi(line.substr(line.find_last_of(',') + 1));
            cubes.insert({x, y, z});
            if (x < x_min)
                x_min = x;
            if (x > x_max)
                x_max = x;
            if (y < y_min)
                y_min = y;
            if (y > y_max)
                y_max = y;
            if (z < z_min)
                z_min = z;
            if (z > z_max)
                z_max = z;
        }
        int area = 6 * cubes.size();
        for (auto cube : cubes)
        {
            if (cubes.find({cube[0] + 1, cube[1], cube[2]}) != cubes.end())
                area--;
            if (cubes.find({cube[0] - 1, cube[1], cube[2]}) != cubes.end())
                area--;
            if (cubes.find({cube[0], cube[1] + 1, cube[2]}) != cubes.end())
                area--;
            if (cubes.find({cube[0], cube[1] - 1, cube[2]}) != cubes.end())
                area--;
            if (cubes.find({cube[0], cube[1], cube[2] + 1}) != cubes.end())
                area--;
            if (cubes.find({cube[0], cube[1], cube[2] - 1}) != cubes.end())
                area--;
        }
        x_min--;
        x_max++;
        y_min--;
        y_max++;
        z_min--;
        z_max++;

        std::vector<std::vector<std::vector<bool>>> grid (x_max - x_min + 1, std::vector<std::vector<bool>>(y_max - y_min + 1, std::vector<bool>(z_max - z_min + 1, false)));
        for (auto cube : cubes)
        {
            grid[cube[0] - x_min][cube[1] - y_min][cube[2] - z_min] = true;
        }
        std::set<std::array<int, 3>> queue = {{x_min, y_min, z_min}};
        std::array<int, 3> current;
        while (!queue.empty())
        {
            current = *queue.begin();
            queue.erase(queue.begin());
            grid[current[0] - x_min][current[1] - y_min][current[2] - z_min] = true;
            if (current[0] > x_min && !grid[current[0] - x_min - 1][current[1] - y_min][current[2] - z_min])
                queue.insert({current[0] - 1, current[1], current[2]});
            if (current[0] < x_max && !grid[current[0] - x_min + 1][current[1] - y_min][current[2] - z_min])
                queue.insert({current[0] + 1, current[1], current[2]});
            if (current[1] > y_min && !grid[current[0] - x_min][current[1] - y_min - 1][current[2] - z_min])
                queue.insert({current[0], current[1] - 1, current[2]});
            if (current[1] < y_max && !grid[current[0] - x_min][current[1] - y_min + 1][current[2] - z_min])
                queue.insert({current[0], current[1] + 1, current[2]});
            if (current[2] > z_min && !grid[current[0] - x_min][current[1] - y_min][current[2] - z_min - 1])
                queue.insert({current[0], current[1], current[2] - 1});
            if (current[2] < z_max && !grid[current[0] - x_min][current[1] - y_min][current[2] - z_min + 1])
                queue.insert({current[0], current[1], current[2] + 1});
        }

        int count = 0;
        std::set<std::array<int, 3>> inner_cubes;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                for (int k = 0; k < grid[i][j].size(); k++)
                {
                    if (!grid[i][j][k])
                    {
                        count++;
                        inner_cubes.insert({i + x_min, j + y_min, k + z_min});
                    }
                }
            }
        }

        int inner_area = 6 * inner_cubes.size();
        for (auto cube : inner_cubes)
        {
            if (inner_cubes.find({cube[0] + 1, cube[1], cube[2]}) != inner_cubes.end())
                inner_area--;
            if (inner_cubes.find({cube[0] - 1, cube[1], cube[2]}) != inner_cubes.end())
                inner_area--;
            if (inner_cubes.find({cube[0], cube[1] + 1, cube[2]}) != inner_cubes.end())
                inner_area--;
            if (inner_cubes.find({cube[0], cube[1] - 1, cube[2]}) != inner_cubes.end())
                inner_area--;
            if (inner_cubes.find({cube[0], cube[1], cube[2] + 1}) != inner_cubes.end())
                inner_area--;
            if (inner_cubes.find({cube[0], cube[1], cube[2] - 1}) != inner_cubes.end())
                inner_area--;
        }
        return area - inner_area;
    }
}