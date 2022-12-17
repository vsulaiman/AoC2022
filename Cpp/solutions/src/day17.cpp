#include "day17.hpp"

namespace day17 {
    void printGrid(std::vector<std::vector<bool>>& grid)
    {
        std::cout << std::endl;
        for (int i = grid.size() - 1; i >= 0; i--)
        {
            std::cout << "|";
            for (auto j : grid[i])
            {
                if (j)
                {
                    std::cout << "#";
                }
                else
                {
                    std::cout << "_";
                }
            }
            std::cout << "|" << std::endl;
        }
        std::cout << "+-------+" << std::endl;
    }
    template<typename T>
    struct Rock
    {
        std::vector<std::pair<T, T>> positions;
        bool collision(std::vector<std::vector<bool>> &grid, std::pair<int, int> move)
        {
            for (auto pos : positions)
            {
                if (pos.second + move.second >= 7 || pos.second + move.second < 0)
                {
                    return true;
                }
                if (pos.first + move.first < 0)
                {
                    return true;
                }
                if (pos.first + move.first < grid.size())
                {
                    if (grid[pos.first + move.first][pos.second + move.second])
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        bool move(std::vector<std::vector<bool>> &grid, char direction)
        {
            std::pair<int, int> move;
            if (direction == '>')
            {
                move = std::make_pair(0, 1);
            }
            else if (direction == '<')
            {
                move = std::make_pair(0, -1);
            }
            else if (direction == 'v')
            {
                move = std::make_pair(-1, 0);
            }
            if (!collision(grid, move))
            {
                for (auto& pos : positions)
                {
                    pos.first += move.first;
                    pos.second += move.second;
                }
                return true;
            }
            return false;
        }
    };
    template<typename T>
    Rock<T> createRock(T height, int shape)
    {
        // creates a rock directly above height with 2 units left of the rock
        Rock<T> rock;
        switch (shape)
        {
        case 1:
            /*
                ..####.
            */
            rock.positions.push_back({height, 2});
            rock.positions.push_back({height, 3});
            rock.positions.push_back({height, 4});
            rock.positions.push_back({height, 5});
            break;
        case 2:
            /*
                ...#...
                ..###..
                ...#...
            */
            rock.positions.push_back({height, 3});
            rock.positions.push_back({height + 1, 2});
            rock.positions.push_back({height + 1, 3});
            rock.positions.push_back({height + 1, 4});
            rock.positions.push_back({height + 2, 3});
            break;
        case 3:
            /*
                ....#..
                ....#..
                ..###..
            */
            rock.positions.push_back({height, 2});
            rock.positions.push_back({height, 3});
            rock.positions.push_back({height, 4});
            rock.positions.push_back({height + 1, 4});
            rock.positions.push_back({height + 2, 4});
            break;
        case 4:
            /*
                ..#....
                ..#....
                ..#....
                ..#....
            */
            rock.positions.push_back({height, 2});
            rock.positions.push_back({height + 1, 2});
            rock.positions.push_back({height + 2, 2});
            rock.positions.push_back({height + 3, 2});
            break;
        case 5:
            /*
                ..##...
                ..##...
            */
            rock.positions.push_back({height, 2});
            rock.positions.push_back({height, 3});
            rock.positions.push_back({height + 1, 2});
            rock.positions.push_back({height + 1, 3});
        }
        return rock;
    }
    template<typename T>
    void placeRock(std::vector<std::vector<bool>> &grid, T &height, Rock<T> &rock)
    {
        for (auto pos : rock.positions)
        {
            while (pos.first >= grid.size())
            {
                grid.push_back({std::vector<bool>(7, false)});
            }
            grid[pos.first][pos.second] = true;
            if (pos.first >= height)
            {
                height = pos.first + 1;
            }
        }
    }
    struct Hash
    {
        std::vector<int> depths = std::vector<int>(7, 0);
        int idx_part = 1;
        int idx_line = 0;

        bool operator==(const Hash &other) const
        {
            return (depths == other.depths) && (idx_part == other.idx_part) && (idx_line == other.idx_line);
        }
        bool operator<(const Hash &other) const
        {
            if (depths < other.depths)
            {
                return true;
            }
            else if (depths == other.depths)
            {
                if (idx_part < other.idx_part)
                {
                    return true;
                }
                else if (idx_part == other.idx_part)
                {
                    return idx_line < other.idx_line;
                }
            }
            return false;
        }
    };

    int part1(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;
        std::getline(f, line);
        // false = no rock at position, true = rock at position
        std::vector<std::vector<bool>> grid;
        int height = 0;
        int idx_line = 0;
        Rock<int> new_rock;
        bool success;

        for (int i = 0; i < 2022; i++)
        {
            new_rock = createRock(height + 3, (i%5) + 1);
            success = true;
            while (success)
            {
                success = new_rock.move(grid, line[idx_line]);
                // std::cout << success << " " << line[idx_line] << std::endl;
                idx_line = (idx_line + 1) % line.size();
                success = new_rock.move(grid, 'v');
                // std::cout << success << " v" << std::endl;
            }
            placeRock(grid, height, new_rock);
            // printGrid(grid);
        }
        return height;
    }
    long long part2(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;
        std::getline(f, line);
        // false = no rock at position, true = rock at position
        std::vector<std::vector<bool>> grid;
        long long height = 0;
        int idx_line = 0;
        Rock<long long> new_rock;
        bool success;

        std::map<Hash, std::pair<long long, long long>> hashes;
        Hash found_hash;
        std::pair<long long, long long> found_pair;
        long long cycle_moves = 0, cycle_height = 0, remaining_moves = 0;
        long long n_moves = 1000000000000;
        for (long long i = 0; i < n_moves; i++)
        {
            new_rock = createRock(height + 3, (i % 5) + 1);
            success = true;
            while (success)
            {
                success = new_rock.move(grid, line[idx_line]);
                idx_line = (idx_line + 1) % line.size();
                success = new_rock.move(grid, 'v');
            }
            placeRock(grid, height, new_rock);

            // calculate current hash
            Hash hash;
            for (int j = 0; j < 7; j++)
            {
                while (!grid[height-1-hash.depths[j]][j])
                {
                    hash.depths[j]++;
                    if (hash.depths[j] == height)
                    {
                        break;
                    }
                }
            }
            hash.idx_line = idx_line;
            hash.idx_part = ((i + 1) % 5);

            // check if hash already exists
            if (hashes.find(hash) != hashes.end())
            {
                found_hash = hash;
                found_pair = hashes[hash];
                // calculate difference between current and previous height
                cycle_height = height - found_pair.first;
                cycle_moves = i - found_pair.second;
                remaining_moves = n_moves - i;

                // std::cout << "found hash at " << i << " at height " << height << std::endl;
                // std::cout << "cycle height: " << cycle_height << " cycle moves: " << cycle_moves << std::endl;
                break;
            }
            hashes[hash] = {height, i};
        }
        long long n_cycles = remaining_moves / cycle_moves;
        remaining_moves %= cycle_moves;
        long long n_heights = n_cycles * cycle_height;
        // std::cout << "remaining moves: " << remaining_moves << std::endl;

        for (long long i = found_hash.idx_part; i < remaining_moves + found_hash.idx_part-1; i++)
        {
            new_rock = createRock(height + 3, (i % 5) + 1);
            success = true;
            while (success)
            {
                success = new_rock.move(grid, line[idx_line]);
                idx_line = (idx_line + 1) % line.size();
                success = new_rock.move(grid, 'v');
            }
            placeRock(grid, height, new_rock);
        }
        return height + n_heights;
    }
}