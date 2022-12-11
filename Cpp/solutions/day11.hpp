#ifndef DAY11_HPP
#define DAY11_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>

namespace day11 {
    class Monkey
    {
    private:
        std::vector<int> items;
        std::function<int(int)> inspection_function;
        std::function<int(int)> worry_test;
        int number_inspections;
    public:
        Monkey(std::vector<int> m_items, std::function<int(int)> m_inspection_function, std::function<int(int)> m_worry_test);
        void addItem(int m_item);
        bool hasItems();
        std::pair<int, int> throwNextItem();
        std::vector<int> getItems();
        int getNumberInspections();
    };
    std::vector<Monkey> parseInput(std::string input);
    int part1(std::vector<Monkey> monkeys);
    int part2(std::string input);
}

#endif // DAY11_HPP