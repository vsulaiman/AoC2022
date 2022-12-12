#include "day12.hpp"

namespace day12 {
    bool compareDistance(const std::vector<std::vector<Square>> &grid,const std::pair<int, int> &a, const std::pair<int, int> &b)
    {
        return grid[a.first][a.second].distance < grid[b.first][b.second].distance;
    }
    bool inGrid(const std::vector<std::vector<Square>> &grid, std::pair<int, int> coord)
    {
        return coord.first >= 0 && coord.first < grid.size() && coord.second >= 0 && coord.second < grid[0].size();
    }
    std::vector<std::vector<Square>> parseInput(std::string input, std::pair<int, int> &start, std::pair<int, int> &end)
    {
        std::ifstream f;
        f.open(input);
        std::string line;
        std::vector<std::vector<Square>> grid;
        int n_row = 0;
        while (std::getline(f, line))
        {
            std::vector<Square> row;
            int n_col = 0;
            for (char c : line)
            {
                Square s;
                if (c == 'S') {
                    start = std::make_pair(n_row, n_col);
                    c = 'a';
                }
                else if (c == 'E')
                {
                    end = std::make_pair(n_row, n_col);
                    c = 'z';
                }
                s.height = c - 'a';
                row.push_back(s);
                n_col++;
            }
            grid.push_back(row);
            n_row++;
        }
        return grid;
    }
    int part1(std::vector<std::vector<Square>> grid, std::pair<int, int> start, std::pair<int, int> end)
    {
        std::vector<std::pair<int, int>> queue = { start };
        grid[start.first][start.second].distance = 0;
        while (!queue.empty())
        {
            std::pair<int, int> current = queue.front();
            if (current == end)
            {
                break;
            }
            queue.erase(queue.begin());
            std::vector<std::pair<int, int>> neighbours = {
                std::make_pair(current.first - 1, current.second),
                std::make_pair(current.first + 1, current.second),
                std::make_pair(current.first, current.second - 1),
                std::make_pair(current.first, current.second + 1) };
            for (std::pair<int, int> neighbour : neighbours)
            {
                if (inGrid(grid, neighbour) && grid[neighbour.first][neighbour.second].height <= grid[current.first][current.second].height + 1)
                {
                    int new_distance = grid[current.first][current.second].distance + 1;
                    if (new_distance < grid[neighbour.first][neighbour.second].distance)
                    {
                        grid[neighbour.first][neighbour.second].distance = new_distance;
                        grid[neighbour.first][neighbour.second].predecessor = current;
                        queue.push_back(neighbour);
                    }
                }
            }
            std::sort(queue.begin(), queue.end(), std::bind(compareDistance, grid, std::placeholders::_1, std::placeholders::_2));
        }
        return grid[end.first][end.second].distance;
    }
    int part2(std::vector<std::vector<Square>> grid, std::pair<int, int> end)
    {
        std::vector<std::pair<int, int>> queue = {end};
        std::pair<int, int> current = end;
        grid[end.first][end.second].distance = 0;
        while (!queue.empty())
        {
            current = queue.front();
            if (grid[current.first][current.second].height == 0)
            {
                break;
            }
            queue.erase(queue.begin());
            std::vector<std::pair<int, int>> neighbours = {
                std::make_pair(current.first - 1, current.second),
                std::make_pair(current.first + 1, current.second),
                std::make_pair(current.first, current.second - 1),
                std::make_pair(current.first, current.second + 1)};
            for (std::pair<int, int> neighbour : neighbours)
            {
                if (inGrid(grid, neighbour) && grid[neighbour.first][neighbour.second].height + 1 >= grid[current.first][current.second].height)
                {
                    int new_distance = grid[current.first][current.second].distance + 1;
                    if (new_distance < grid[neighbour.first][neighbour.second].distance)
                    {
                        grid[neighbour.first][neighbour.second].distance = new_distance;
                        grid[neighbour.first][neighbour.second].predecessor = current;
                        queue.push_back(neighbour);
                    }
                }
            }
            std::sort(queue.begin(), queue.end(), std::bind(compareDistance, grid, std::placeholders::_1, std::placeholders::_2));
        }
        return grid[current.first][current.second].distance;
    }
}