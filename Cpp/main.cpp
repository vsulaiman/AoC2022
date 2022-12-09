#include "day01.hpp"
#include "day02.hpp"
#include "day03.hpp"
#include "day04.hpp"
#include "day05.hpp"
#include "day06.hpp"
#include "day07.hpp"
#include "day08.hpp"
#include "day09.hpp"

int main()
{
    // Day 01
    std::cout << "---------------- Day 01 ----------------" << std::endl;
    std::vector<int> calories = day01::sum_calories("../Inputs/input01.txt");
    std::cout << "Most calories one elf carries: " << day01::part1(calories) << std::endl;
    std::cout << "Sum of calories the top 3 elves carry: " << day01::part2(calories) << std::endl;

    // Day 02
    std::cout << "\n---------------- Day 02 ----------------" << std::endl;
    std::cout << day02::part1("../Inputs/input02.txt") << std::endl;
    std::cout << day02::part2("../Inputs/input02.txt") << std::endl;

    // Day 03
    std::cout << "\n---------------- Day 03 ----------------" << std::endl;
    std::cout << day03::part1("../Inputs/input03.txt") << std::endl;
    std::cout << day03::part2("../Inputs/input03.txt") << std::endl;

    // Day 04
    std::cout << "\n---------------- Day 04 ----------------" << std::endl;
    std::cout << day04::part1("../Inputs/input04.txt") << std::endl;
    std::cout << day04::part2("../Inputs/input04.txt") << std::endl;

    // Day 05
    std::cout << "\n---------------- Day 05 ----------------" << std::endl;
    std::vector<std::vector<char>> stacks = day05::get_stacks("../Inputs/input05.txt");
    std::cout << day05::part1("../Inputs/input05.txt", stacks) << std::endl;
    std::cout << day05::part2("../Inputs/input05.txt", stacks) << std::endl;

    // Day 06
    std::cout << "\n---------------- Day 06 ----------------" << std::endl;
    std::cout << day06::part1("../Inputs/input06.txt") << std::endl;
    std::cout << day06::part2("../Inputs/input06.txt") << std::endl;

    // Day 07
    std::cout << "\n---------------- Day 07 ----------------" << std::endl;
    std::map<std::string, int> folder_sizes = day07::parse_input("../Inputs/input07.txt");
    // for (const auto &[key, value] : folder_sizes) {
    //     std::cout << '[' << key << "] = " << value << std::endl;
    // }
    std::cout << day07::part1(folder_sizes) << std::endl;
    std::cout << day07::part2(folder_sizes) << std::endl;

    // Day 08
    std::cout << "\n---------------- Day 08 ----------------" << std::endl;
    std::vector<std::vector<int>> grid = day08::parse_input("../Inputs/input08.txt");
    std::cout << day08::part1(grid) << std::endl;
    std::cout << day08::part2(grid) << std::endl;

    // Day 09
    std::cout << "\n---------------- Day 09 ----------------" << std::endl;
    std::cout << day09::part1("../Inputs/input09.txt") << std::endl;
    std::cout << day09::part2("../Inputs/input09.txt") << std::endl;

    // Day 10
    // std::cout << "\n---------------- Day 10 ----------------" << std::endl;

}