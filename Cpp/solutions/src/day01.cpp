#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    std::ifstream f;
    f.open(argv[1]);
    std::string line;

    std::vector<int> calories;
    int sum = 0;
    while(std::getline(f, line)) {
        if (line.length() == 0) {
            calories.push_back(sum);
            sum = 0;
            continue;
        }
        sum += std::stoi(line);
    }

    int max_calories[3] = {0};
    for (int i = 0; i < calories.size(); i++) {
        if (calories[i] > max_calories[2]) {
            max_calories[2] = calories[i];
            if (max_calories[2] > max_calories[1]) {
                std::swap(max_calories[1], max_calories[2]);
                if (max_calories[1] > max_calories[0]) {
                    std::swap(max_calories[0], max_calories[1]);
                }
            }
        }
    }

    std::cout << "Most calories one elf carries: " << max_calories[0] << std::endl;
    std::cout << "Sum of calories the top 3 elves carry: " << max_calories[0] + max_calories[1] + max_calories[2] << std::endl;
}