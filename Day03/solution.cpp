#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int priority(char c) {
    if(isupper(c)) {
        return int(c)-64+26;
    }
    else {
        return int(c)-96;
    }
}

int main(int argc, char** argv) {
    std::ifstream f;
    f.open(argv[1]);
    std::string line;

    int sum = 0;
    int i = 0;
    std::string lines[3];
    int sum2 = 0;

    while(std::getline(f, line)) {
        // part 1
        auto result = std::find_first_of(line.begin(), line.begin()+line.length()/2,
                                        line.begin()+line.length()/2, line.end());
        if (result != line.begin()+line.length()/2)
        {
            sum += priority(*result);
        }
        // part 2
        lines[i] = line;
        if (i==2) {
            for (auto it = lines[0].begin(); it != lines[0].end(); ++it) {
                if (std::find(lines[1].begin(), lines[1].end(), (*it)) != lines[1].end() &&
                    std::find(lines[2].begin(), lines[2].end(), (*it)) != lines[2].end()) {
                    sum2 += priority(*it);
                    break;
                }
            }
        }
        i = (i+1)%3;
    }
    std::cout << sum << std::endl;
    std::cout << sum2 << std::endl;
}