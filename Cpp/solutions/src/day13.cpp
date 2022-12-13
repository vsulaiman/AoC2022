#include "day13.hpp"

namespace day13 {
    std::vector<std::string> splitList(std::string input)
    {
        input = input.substr(1, input.size() - 2);
        std::vector<std::string> result;
        while (input.size() > 0)
        {
            if (input[0] == '[')
            {
                int count = 1;
                std::string::iterator it = input.begin();
                while (count > 0)
                {
                    it++;
                    if (*it == '[')
                    {
                        count++;
                    }
                    else if (*it == ']')
                    {
                        count--;
                    }
                }
                result.push_back(std::string(input.begin(), it+1));
                input = std::string(it + 1, input.end());
                if (input[0] == ',')
                {
                    input = input.substr(1);
                }
            }
            else
            {
                std::string partial_input = "";
                if (input.find('[') == std::string::npos)
                {
                    partial_input = input;
                    input = "";
                }
                else
                {
                    partial_input = input.substr(0, input.find('[') - 1);
                    input = input.substr(input.find('['));
                }
                std::string temp = "";
                for (auto c : partial_input)
                {
                    if (c == ',')
                    {
                        result.push_back(temp);
                        temp = "";
                    }
                    else
                    {
                        temp += c;
                    }
                }
                result.push_back(temp);
            }
        }
        return result;
    }
    int compareLists(std::vector<std::string> left, std::vector<std::string> right)
    {
        // std::cout << "Compare [";
        // for (auto s : left)
        // {
        //     std::cout << s << ",";
        // }
        // std::cout << "] with [";
        // for (auto s : right)
        // {
        //     std::cout << s << ",";
        // }
        // std::cout << "]" << std::endl;
        int result = 0;
        while (left.size() != 0 && right.size() != 0)
        {
            if (isdigit(left[0][0]) && isdigit(right[0][0])){
                int left_int = std::stoi(left[0]);
                int right_int = std::stoi(right[0]);
                // std::cout << "here: " << left_int << ":" << right_int << std::endl;
                if (left_int < right_int) { return 1; }
                if (left_int > right_int) { return -1; }
                left.erase(left.begin());
                right.erase(right.begin());
                continue;
            }
            if (!isdigit(left[0][0]) && !isdigit(right[0][0]))
            {
                int help = compareLists(splitList(left[0]), splitList(right[0]));
                if (help != 0) { return help; }
                left.erase(left.begin());
                right.erase(right.begin());
                continue;
            }
            if (isdigit(left[0][0]) && !isdigit(right[0][0]))
            {
                int help = compareLists(std::vector<std::string> ({left[0]}), splitList(right[0]));
                if (help != 0) { return help; }
                left.erase(left.begin());
                right.erase(right.begin());
                continue;
            }
            if (!isdigit(left[0][0]) && isdigit(right[0][0]))
            {
                int help = compareLists(splitList(left[0]), std::vector<std::string> ({right[0]}));
                if (help != 0) { return help; }
                left.erase(left.begin());
                right.erase(right.begin());
                continue;
            }
        }
        if (left.size() == 0 && right.size() != 0) { return 1; }
        if (right.size() == 0 && left.size() != 0) { return -1; }
        return result;
    }
    int part1(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line1, line2;
        int index = 1;
        int sum = 0;
        while (!f.eof())
        {
            std::getline(f, line1);
            std::getline(f, line2);

            // std::vector<std::string> elements1 = splitList(line1);
            // std::vector<std::string> elements2 = splitList(line2);
            // for (auto s : elements1)
            // {
            //     std::cout << s << "..";
            // }
            // std::cout << std::endl;
            // for (auto s : elements2)
            // {
            //     std::cout << s << "..";
            // }
            // std::cout << std::endl;
            // std::cout << std::endl;

            // std::cout << std::endl;
            // std::cout << line1 << std::endl
            //           << line2 << std::endl;
            // std::cout << compareLists(splitList(line1), splitList(line2)) << std::endl;
            if (compareLists(splitList(line1), splitList(line2)) > 0)
            {
                sum += index;
                // std::cout << index << std::endl;
            }
            std::getline(f, line1); // empty line
            index++;
        }
        return sum;
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