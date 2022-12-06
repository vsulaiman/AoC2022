#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool string_no_duplicate(std::string str) {
    for (unsigned int i = 0; i<str.length(); i++)
        for (unsigned int j = i+1; j<str.length(); j++)
            if (str[i] == str[j])
                return false;
    return true;
}

int main(int argc, char** argv) {
    std::ifstream f;
    f.open(argv[1]);
    std::string line;

    while(std::getline(f, line)) {
        unsigned int i = 4;
        std::string marker_packet = line.substr(0, 4);
        while (string_no_duplicate(marker_packet) == false)
        {
            marker_packet += line[i];
            marker_packet.erase(marker_packet.begin());
            i++;
        }
        std::cout << i << "\t";

        unsigned int j = 14;
        std::string marker_message = line.substr(0, 14);
        while (string_no_duplicate(marker_message) == false)
        {
            marker_message += line[j];
            marker_message.erase(marker_message.begin());
            j++;
        }
        std::cout << j << std::endl;
    }
}