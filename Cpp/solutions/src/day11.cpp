#include "day11.hpp"

namespace day11 {
    Monkey::Monkey(std::vector<int> m_items, std::function<int(int)> m_inspection_function, std::function<int(int)> m_worry_test)
    {
        this->items = m_items;
        this->inspection_function = m_inspection_function;
        this->worry_test = m_worry_test;
        this->number_inspections = 0;
    }
    void Monkey::addItem(int m_item)
    {
        this->items.push_back(m_item);
    }
    bool Monkey::hasItems()
    {
        return this->items.size() > 0;
    }
    std::pair<int, int> Monkey::throwNextItem()
    {
        if (!this->hasItems()) {
            std::cout << "Error: Monkey has no items" << std::endl;
            return std::make_pair(0, 0);
        }
        this->number_inspections++;
        int item = this->items.front();
        this->items.erase(this->items.begin());
        item = this->inspection_function(item);
        item /= 3;
        return std::make_pair(this->worry_test(item), item);
    }
    std::vector<int> Monkey::getItems()
    {
        return this->items;
    }
    int Monkey::getNumberInspections()
    {
        return this->number_inspections;
    }

    std::vector<Monkey> parseInput(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;
        std::vector<Monkey> monkeys;
        while (!f.eof())
        {
            std::getline(f, line); // Monkey n

            std::getline(f, line); // Starting items:
            line = line.substr(line.find(":") + 2);
            std::vector<int> items;
            while (line.find(",") != std::string::npos)
            {
                items.push_back(std::stoi(line));
                line = line.substr(line.find(",") + 2);
            }
            items.push_back(std::stoi(line));

            std::getline(f, line); // Operation:
            std::string operation = line.substr(line.find("old") + 4, 1);
            line = line.substr(line.find("old") + 6);
            std::function<int(int)> inspection_function;
            if (isdigit(line[0])) {
                int number = std::stoi(line);
                if (operation == "+") {
                    inspection_function = [number](int item) { return item + number; };
                }
                else if (operation == "*") {
                    inspection_function = [number](int item) { return item * number; };
                }
            }
            else {
                if (operation == "+") {
                    inspection_function = [](int item) { return item + item; };
                }
                else if (operation == "*") {
                    inspection_function = [](int item) { return item * item; };
                }
                else {
                    std::cout << "Error: " << operation << "\t" << line << std::endl;
                    inspection_function = [](int item) { return item; };
                }
            }

            std::getline(f, line); // Test:
            int number = std::stoi(line.substr(line.find("by") + 3));
            std::getline(f, line); // If true:
            int monkey_true = std::stoi(line.substr(line.find("monkey") + 7));
            std::getline(f, line); // If false:
            int monkey_false = std::stoi(line.substr(line.find("monkey") + 7));
            std::function<int(int)> worry_test = [number, monkey_true, monkey_false](int item) { return item % number == 0 ? monkey_true : monkey_false; };

            monkeys.push_back(Monkey(items, inspection_function, worry_test));
            std::getline(f, line); // empty line
        }
        return monkeys;
    }
    int part1(std::vector<Monkey> monkeys)
    {
        int rounds = 20;
        for (int i = 0; i < rounds; i++)
        {
            for (int j = 0; j < monkeys.size(); j++)
            {
                while (monkeys[j].hasItems())
                {
                    std::pair<int, int> item = monkeys[j].throwNextItem();
                    monkeys[item.first].addItem(item.second);
                }
            }
            // std::cout << "Round " << i+1 << std::endl;
            // for (int j = 0; j < monkeys.size(); j++)
            // {
            //     std::cout << "Monkey " << j << ": ";
            //     std::vector<int> items = monkeys[j].getItems();
            //     for (int k = 0; k < items.size(); k++)
            //     {
            //         std::cout << items[k] << ", ";
            //     }
            //     std::cout << std::endl;
            // }
            // std::cout << std::endl;
        }
        std::vector<int> n_inspections;
        for (int i = 0; i < monkeys.size(); i++)
        {
            n_inspections.push_back(monkeys[i].getNumberInspections());
        }
        std::sort(n_inspections.begin(), n_inspections.end());
        return n_inspections.back() * n_inspections[n_inspections.size() - 2];
    }
    int part2(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;
        while (std::getline(f, line))
        {

        }
        return 0;
    }
}