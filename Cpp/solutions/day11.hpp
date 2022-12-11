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
        std::function<long int(long int)> inspection_function;
        std::function<int(int)> worry_test;
        int number_inspections;
        int reduce_by;
        long int inspectNextItem();
    public:
        Monkey(std::vector<int> m_items, std::function<long int(long int)> m_inspection_function, std::function<int(int)> m_worry_test);
        void addItem(int m_item);
        bool hasItems();
        std::pair<int, int> throwNextItem_v1();
        std::pair<int, int> throwNextItem_v2();
        std::vector<int> getItems();
        int getNumberInspections();
        void setReduceBy(int m_reduce_by);
    };
    std::vector<Monkey> parseInput(std::string input);
    int part1(std::vector<Monkey> monkeys);
    long int part2(std::vector<Monkey> monkeys);
}

#endif // DAY11_HPP