#include "day06.hpp"

namespace day06 {
    bool string_no_duplicate(std::string str)
    {
        for (unsigned int i = 0; i < str.length(); i++)
            for (unsigned int j = i + 1; j < str.length(); j++)
                if (str[i] == str[j])
                    return false;
        return true;
    }

    int part1(std::string input) {
        std::ifstream f;
        f.open(input);
        std::string line;
        std::getline(f, line);
        unsigned int i = 4;
        std::string marker_packet = line.substr(0, 4);
        while (string_no_duplicate(marker_packet) == false)
        {
            marker_packet += line[i];
            marker_packet.erase(marker_packet.begin());
            i++;
        }
        return i;
    }
    int part2(std::string input) {
        std::ifstream f;
        f.open(input);
        std::string line;
        std::getline(f, line);
        unsigned int i = 14;
        std::string marker_message = line.substr(0, 14);
        while (string_no_duplicate(marker_message) == false)
        {
            marker_message += line[i];
            marker_message.erase(marker_message.begin());
            i++;
        }
        return i;
    }
}