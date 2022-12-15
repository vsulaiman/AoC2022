#include "day15.hpp"

namespace day15 {
    int part1(std::string input, int row)
    {
        std::ifstream f;
        f.open(input);
        std::string line;
        std::vector<std::pair<int, int>> sensors;
        std::vector<int> distances;
        std::unordered_set<int> beacons_in_row;
        int xs, ys, xb, yb;
        while (std::getline(f, line))
        {
            line = line.substr(line.find("=") + 1);
            xs = std::stoi(line);
            line = line.substr(line.find("=") + 1);
            ys = std::stoi(line);
            line = line.substr(line.find("=") + 1);
            xb = std::stoi(line);
            line = line.substr(line.find("=") + 1);
            yb = std::stoi(line);
            sensors.push_back(std::make_pair(xs, ys));
            distances.push_back(std::abs(xs - xb) + std::abs(ys - yb));
            if (yb == row)
            {
                beacons_in_row.insert(xb);
            }
        }

        std::unordered_set<int> cols;
        int distance_to_row;
        for (int i = 0; i < sensors.size(); i++)
        {
            distance_to_row = std::abs(sensors[i].second - row);
            if (distance_to_row > distances[i])
            {
                continue;
            }
            cols.insert(sensors[i].first);
            for (int j = 1; j <= distances[i] - distance_to_row; j++)
            {
                cols.insert(sensors[i].first + j);
                cols.insert(sensors[i].first - j);
            }
        }
        return cols.size() - beacons_in_row.size();
    }
    long int part2(std::string input, int max_coord)
    {
        std::ifstream f;
        f.open(input);
        std::string line;
        std::vector<std::pair<int, int>> sensors;
        std::vector<int> distances;
        int xs, ys, xb, yb;
        while (std::getline(f, line))
        {
            line = line.substr(line.find("=") + 1);
            xs = std::stoi(line);
            line = line.substr(line.find("=") + 1);
            ys = std::stoi(line);
            line = line.substr(line.find("=") + 1);
            xb = std::stoi(line);
            line = line.substr(line.find("=") + 1);
            yb = std::stoi(line);
            sensors.push_back(std::make_pair(xs, ys));
            distances.push_back(std::abs(xs - xb) + std::abs(ys - yb));
        }
        std::vector<std::pair<int,int>> possible_intersections;
        int x, y;
        for (int i = 0; i < sensors.size(); i++)
        {
            x = sensors[i].first + distances[i] + 1;
            y = sensors[i].second;
            while (x > sensors[i].first)
            {
                possible_intersections.push_back(std::make_pair(x, y));
                x--;
                y--;
            }
            while (x > sensors[i].first - distances[i] - 1)
            {
                possible_intersections.push_back(std::make_pair(x, y));
                x--;
                y++;
            }
            while (x < sensors[i].first)
            {
                possible_intersections.push_back(std::make_pair(x, y));
                x++;
                y++;
            }
            while (x < sensors[i].first + distances[i] + 1)
            {
                possible_intersections.push_back(std::make_pair(x, y));
                x++;
                y--;
            }
        }
        bool empty = true;
        long int result = 4000000;
        for (auto coord : possible_intersections)
        {
            if (coord.first >= 0 && coord.first <= max_coord && coord.second >= 0 && coord.second <= max_coord)
            {
                empty = true;
                for (int n = 0; n < sensors.size(); n++)
                {
                    if (std::abs(sensors[n].first - coord.first) + std::abs(sensors[n].second - coord.second) <= distances[n])
                    {
                        empty = false;
                        break;
                    }
                }
                if (empty)
                {
                    result *= coord.first;
                    result += coord.second;
                    break;
                }
            }
        }
        return result;
    }
}