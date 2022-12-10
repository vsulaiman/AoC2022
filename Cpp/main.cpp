#include "day01.hpp"
#include "day02.hpp"
#include "day03.hpp"
#include "day04.hpp"
#include "day05.hpp"
#include "day06.hpp"
#include "day07.hpp"
#include "day08.hpp"
#include "day09.hpp"
#include "day10.hpp"
#include "day11.hpp"
#include "day12.hpp"
#include "day13.hpp"
#include "day14.hpp"
#include "day15.hpp"
#include "day16.hpp"
#include "day17.hpp"
#include "day18.hpp"
#include "day19.hpp"
#include "day20.hpp"
#include "day21.hpp"
#include "day22.hpp"
#include "day23.hpp"
#include "day24.hpp"
#include "day25.hpp"

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
    std::cout << "\n---------------- Day 10 ----------------" << std::endl;
    std::vector<int> register_entries = day10::parse_input("../Inputs/input10.txt");
    std::cout << day10::part1(register_entries) << std::endl;
    std::cout << day10::part2(register_entries) << std::endl; // BPJAZGAP

    // Day 11
    // std::cout << "\n---------------- Day 11 ----------------" << std::endl;
    // std::cout << day11::part1("../Inputs/input11.txt") << std::endl;
    // std::cout << day11::part2("../Inputs/input11.txt") << std::endl;

    // Day 12
    // std::cout << "\n---------------- Day 12 ----------------" << std::endl;
    // std::cout << day12::part1("../Inputs/input12.txt") << std::endl;
    // std::cout << day12::part2("../Inputs/input12.txt") << std::endl;

    // Day 13
    // std::cout << "\n---------------- Day 13 ----------------" << std::endl;
    // std::cout << day13::part1("../Inputs/input13.txt") << std::endl;
    // std::cout << day13::part2("../Inputs/input13.txt") << std::endl;

    // Day 14
    // std::cout << "\n---------------- Day 14 ----------------" << std::endl;
    // std::cout << day14::part1("../Inputs/input14.txt") << std::endl;
    // std::cout << day14::part2("../Inputs/input14.txt") << std::endl;

    // Day 15
    // std::cout << "\n---------------- Day 15 ----------------" << std::endl;
    // std::cout << day15::part1("../Inputs/input15.txt") << std::endl;
    // std::cout << day15::part2("../Inputs/input15.txt") << std::endl;

    // Day 16
    // std::cout << "\n---------------- Day 16 ----------------" << std::endl;
    // std::cout << day16::part1("../Inputs/input16.txt") << std::endl;
    // std::cout << day16::part2("../Inputs/input16.txt") << std::endl;

    // Day 17
    // std::cout << "\n---------------- Day 17 ----------------" << std::endl;
    // std::cout << day17::part1("../Inputs/input17.txt") << std::endl;
    // std::cout << day17::part2("../Inputs/input17.txt") << std::endl;

    // Day 18
    // std::cout << "\n---------------- Day 18 ----------------" << std::endl;
    // std::cout << day18::part1("../Inputs/input18.txt") << std::endl;
    // std::cout << day18::part2("../Inputs/input18.txt") << std::endl;

    // Day 19
    // std::cout << "\n---------------- Day 19 ----------------" << std::endl;
    // std::cout << day19::part1("../Inputs/input19.txt") << std::endl;
    // std::cout << day19::part2("../Inputs/input19.txt") << std::endl;

    // Day 20
    // std::cout << "\n---------------- Day 20 ----------------" << std::endl;
    // std::cout << day20::part1("../Inputs/input20.txt") << std::endl;
    // std::cout << day20::part2("../Inputs/input20.txt") << std::endl;

    // Day 21
    // std::cout << "\n---------------- Day 21 ----------------" << std::endl;
    // std::cout << day21::part1("../Inputs/input21.txt") << std::endl;
    // std::cout << day21::part2("../Inputs/input21.txt") << std::endl;

    // Day 22
    // std::cout << "\n---------------- Day 22 ----------------" << std::endl;
    // std::cout << day22::part1("../Inputs/input22.txt") << std::endl;
    // std::cout << day22::part2("../Inputs/input22.txt") << std::endl;

    // Day 23
    // std::cout << "\n---------------- Day 23 ----------------" << std::endl;
    // std::cout << day23::part1("../Inputs/input23.txt") << std::endl;
    // std::cout << day23::part2("../Inputs/input23.txt") << std::endl;

    // Day 24
    // std::cout << "\n---------------- Day 24 ----------------" << std::endl;
    // std::cout << day24::part1("../Inputs/input24.txt") << std::endl;
    // std::cout << day24::part2("../Inputs/input24.txt") << std::endl;

    // Day 25
    // std::cout << "\n---------------- Day 25 ----------------" << std::endl;
    // std::cout << day25::part1("../Inputs/input25.txt") << std::endl;
    // std::cout << day25::part2("../Inputs/input25.txt") << std::endl;
}