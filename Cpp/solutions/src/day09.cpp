#include "day09.hpp"

namespace day09 {
    int sgn(int val)
    {
        return (0 < val) - (val < 0);
    }

    void update_tail(std::pair<int, int> &head_pos, std::pair<int, int> &tail_pos)
    {
        int x_diff = head_pos.first - tail_pos.first;
        int y_diff = head_pos.second - tail_pos.second;
        if (abs(x_diff) <= 1 && abs(y_diff) <= 1)
        {
            return;
        }
        if (abs(x_diff) > 1 && abs(y_diff) <= 1)
        {
            tail_pos.first += x_diff - sgn(x_diff);
            tail_pos.second = head_pos.second;
            return;
        }
        if (abs(y_diff) > 1 && abs(x_diff) <= 1)
        {
            tail_pos.second += y_diff - sgn(y_diff);
            tail_pos.first = head_pos.first;
            return;
        }
        if (abs(x_diff) > 1 && abs(y_diff) > 1)
        {
            tail_pos.first += x_diff - sgn(x_diff);
            tail_pos.second += y_diff - sgn(y_diff);
            return;
        }
        std::cout << "Error: " << x_diff << ", " << y_diff << std::endl;
    }

    void move_head(std::pair<int, int> &head_pos, char direction)
    {
        switch (direction)
        {
        case 'L':
            head_pos.first--;
            break;
        case 'R':
            head_pos.first++;
            break;
        case 'U':
            head_pos.second++;
            break;
        case 'D':
            head_pos.second--;
            break;
        }
    }

    int part1(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;

        std::pair<int, int> head_pos = {0, 0};
        std::pair<int, int> tail_pos = {0, 0};
        std::set<std::pair<int, int>> visited;
        visited.insert(tail_pos);

        while (std::getline(f, line))
        {
            for (int i = 0; i < std::stoi(line.substr(1)); i++)
            {
                // part 1
                move_head(head_pos, line[0]);
                update_tail(head_pos, tail_pos);
                visited.insert(tail_pos);
            }
        }
        return visited.size();
    }
    int part2(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;

        std::vector<std::pair<int, int>> snake;
        for (int i = 0; i < 10; i++)
        {
            snake.push_back({0, 0});
        }
        snake.shrink_to_fit();
        std::set<std::pair<int, int>> visited;
        visited.insert(snake.back());
        while (std::getline(f, line))
        {
            for (int i = 0; i < std::stoi(line.substr(1)); i++)
            {
                // part 2
                move_head(snake[0], line[0]);
                for (int j = 1; j < snake.size(); j++)
                {
                    update_tail(snake[j - 1], snake[j]);
                }
                visited.insert(snake.back());
            }
        }
        return visited.size();
    }
}