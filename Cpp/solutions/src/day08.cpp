#include "day08.hpp"

namespace day08 {
    bool visible(const std::vector<std::vector<int>>& grid, int i, int j)
    {
        if (i == 0 || j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1)
        {
            return true;
        }
        bool top = true;
        for (int k = 0; k < i; k++)
        {
            if (grid[k][j] >= grid[i][j])
            {
                top = false;
            }
        }
        bool bottom = true;
        for (int k = i + 1; k < grid.size(); k++)
        {
            if (grid[k][j] >= grid[i][j])
            {
                bottom = false;
            }
        }
        bool left = true;
        for (int k = 0; k < j; k++)
        {
            if (grid[i][k] >= grid[i][j])
            {
                left = false;
            }
        }
        bool right = true;
        for (int k = j + 1; k < grid[i].size(); k++)
        {
            if (grid[i][k] >= grid[i][j])
            {
                right = false;
            }
        }
        return (top || bottom || left || right);
    }

    int scenic_score(const std::vector<std::vector<int>>& grid, int i, int j)
    {
        if (i == 0 || j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1)
        {
            return 0;
        }
        int top = 0;
        for (int k = i - 1; k >= 0; k--)
        {
            top++;
            if (grid[k][j] >= grid[i][j])
            {
                break;
            }
        }
        int bottom = 0;
        for (int k = i + 1; k < grid.size(); k++)
        {
            bottom++;
            if (grid[k][j] >= grid[i][j])
            {
                break;
            }
        }
        int left = 0;
        for (int k = j - 1; k >= 0; k--)
        {
            left++;
            if (grid[i][k] >= grid[i][j])
            {
                break;
            }
        }
        int right = 0;
        for (int k = j + 1; k < grid[i].size(); k++)
        {
            right++;
            if (grid[i][k] >= grid[i][j])
            {
                break;
            }
        }
        return top * bottom * left * right;
    }

    std::vector<std::vector<int>> parse_input(std::string input) {
        std::ifstream f;
        f.open(input);
        std::string line;

        std::vector<std::vector<int>> grid;
        while (std::getline(f, line))
        {
            std::vector<int> row;
            for (int i = 0; i < line.size(); i++)
            {
                row.push_back(line[i] - '0');
            }
            grid.push_back(row);
        }
        return grid;
    }

    int part1 (const std::vector<std::vector<int>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (visible(grid, i, j))
                {
                    sum++;
                }
            }
        }
        return sum;
    }

    int part2 (const std::vector<std::vector<int>>& grid) {
        int max_score = 0;
        int score;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                score = scenic_score(grid, i, j);
                if (score > max_score)
                {
                    max_score = score;
                }
            }
        }
        return max_score;
    }
}