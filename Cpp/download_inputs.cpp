#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "includes/httplib.h"
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    std::string day = argv[1];
    httplib::Client client("https://adventofcode.com");
    client.set_follow_location(true);

    char *tmp = std::getenv("AOC_SESSION");
    if (tmp == nullptr)
    {
        throw std::runtime_error("You need to set the AOC_SESSION env variable with your cookie");
    }
    std::string session(tmp);

    httplib::Headers headers = {{"Cookie", "session=" + session}};
    auto result = client.Get(("/2022/day/" + std::to_string(std::stoi(day)) + "/input"), headers);
    if (result->status != 200)
    {
        throw std::runtime_error("Could not download input: {}" + result->body);
    }

    std::ofstream stream;
    stream.open("../Inputs/input" + day + ".txt");
    stream << result->body;
    stream.close();
}