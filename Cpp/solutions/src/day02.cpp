#include "day02.hpp"

namespace day02 {
    int score_v1(std::string round) {
        if (round == "A Y") {return 6 + 2;}
        if (round == "B Z") {return 6 + 3;}
        if (round == "C X") {return 6 + 1;}
        if (round == "A Z") {return 0 + 3;}
        if (round == "B X") {return 0 + 1;}
        if (round == "C Y") {return 0 + 2;}
        if (round == "A X") {return 3 + 1;}
        if (round == "B Y") {return 3 + 2;}
        if (round == "C Z") {return 3 + 3;}
    }

    int score_v2(std::string round) {
        if (round == "A Y") {return 3 + 1;}
        if (round == "B Z") {return 6 + 3;}
        if (round == "C X") {return 0 + 2;}
        if (round == "A Z") {return 6 + 2;}
        if (round == "B X") {return 0 + 1;}
        if (round == "C Y") {return 3 + 3;}
        if (round == "A X") {return 0 + 3;}
        if (round == "B Y") {return 3 + 2;}
        if (round == "C Z") {return 6 + 1;}
    }

    int part1(std::string input) {
        std::ifstream f;
        f.open(input);
        std::string line;
        int total_score = 0;
        while (std::getline(f, line))
        {
            total_score += score_v1(line);
        }
        return total_score;
    }

    int part2(std::string input) {
        std::ifstream f;
        f.open(input);
        std::string line;
        int total_score = 0;
        while (std::getline(f, line))
        {
            total_score += score_v2(line);
        }
        return total_score;
    }
}
