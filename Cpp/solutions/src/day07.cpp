#include "day07.hpp"

namespace day07 {
    std::map<std::string, int> parse_input(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;

        std::string current_path = "";
        std::map<std::string, int> file_sizes;
        while (std::getline(f, line))
        {
            if (line[0] == '$')
            {
                auto found = line.find(' ', 2);
                if (line.substr(2, found - 2) == "cd")
                {
                    if (line.substr(found + 1) == "..")
                    {
                        current_path.pop_back();
                        current_path = current_path.substr(0, current_path.find_last_of('/') + 1);
                        if (current_path.empty())
                        {
                            current_path = "/";
                        }
                    }
                    else if (line.substr(found + 1) == "/")
                    {
                        current_path = "/";
                    }
                    else
                    {
                        current_path += line.substr(found + 1) + "/";
                    }
                }
            }
            else if (isdigit(line[0]))
            {
                std::string::size_type sz;
                int size = std::stoi(line, &sz);
                file_sizes[current_path + line.substr(sz + 1)] = size;
            }
        }

        // sum data
        std::map<std::string, int> folder_sizes{{"/", 0}};
        for (const auto &[key, value] : file_sizes)
        {
            // std::cout << '[' << key << "] = " << value << std::endl;
            folder_sizes["/"] += value;
            current_path = key.substr(0, key.find_last_of('/') + 1);
            while (current_path.size() > 1)
            {
                if (folder_sizes.count(current_path))
                {
                    folder_sizes[current_path] += value;
                }
                else
                {
                    folder_sizes[current_path] = value;
                }
                current_path.pop_back();
                current_path = current_path.substr(0, current_path.find_last_of('/') + 1);
            }
        }
        return folder_sizes;
    }
    int part1(const std::map<std::string, int> &folder_sizes)
    {
        int sum = 0;
        for (const auto &[key, value] : folder_sizes)
        {
            if (value <= 100000)
            {
                sum += value;
            }
        }
        return sum;
    }
    int part2(std::map<std::string, int> &folder_sizes)
    {
        int needed_space = folder_sizes["/"] - 40000000;
        int smallest = folder_sizes["/"];
        for (const auto &[key, value] : folder_sizes)
        {
            if (value >= needed_space && value < smallest)
            {
                smallest = value;
            }
        }
        return smallest;
    }
}