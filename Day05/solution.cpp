#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    std::ifstream f;
    f.open(argv[1]);
    std::string line;

    std::vector<std::vector<char>> stacks = {{}};
    while(std::getline(f, line) && line.length() > 0) {
        // extract chars in brackets
        while(stacks.size() < line.length()/4 + 1) {
            stacks.push_back({});
        }
        for (size_t i=1; i < line.length(); i += 4) {
            if (isupper(line[i])) {
                stacks[i/4].insert(stacks[i/4].begin(),line[i]);
            }
        }
    }
    std::vector<std::vector<char>> new_stacks = stacks;

    std::string::size_type sz;
    int moves[3];
    while(std::getline(f, line)) {
        sz = 0;
        for (int i = 0; i < 3; i++){
            while(!isdigit(line[sz])) {
                sz++;
            }
            line = line.substr(sz);
            moves[i] = std::stoi(line, &sz);
        }
        // part 1
        for (int i = 0; i < moves[0]; i++) {
            stacks[moves[2]-1].push_back(stacks[moves[1]-1].back());
            stacks[moves[1]-1].pop_back();
        }
        // part 2
        for (int i = 0; i < moves[0]; i++)
        {
            new_stacks[moves[2] - 1].push_back(new_stacks[moves[1] - 1].at(new_stacks[moves[1] - 1].size() - moves[0] + i));
        }
        for (int i = 0; i < moves[0]; i++)
        {
            new_stacks[moves[1] - 1].pop_back();
        }
    }
    for (int i = 0; i < stacks.size(); i++)
    {
        std::cout << stacks[i].back();
    }
    std::cout << std::endl;
    for (int i = 0; i < new_stacks.size(); i++)
    {
        std::cout << new_stacks[i].back();
    }
}