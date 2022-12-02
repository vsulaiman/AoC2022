#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

int main(int argc, char** argv) {
    std::ifstream f;
    f.open(argv[1]);
    std::string line;

    int total_score_v1 = 0;
    int total_score_v2 = 0;
    while(std::getline(f, line)) {
        total_score_v1 += score_v1(line);
        total_score_v2 += score_v2(line);
    }
    std::cout << total_score_v1 << std::endl;
    std::cout << total_score_v2 << std::endl;
}