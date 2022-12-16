#include "day16.hpp"

namespace day16 {
    std::unordered_map<std::string, Valve> parseInput(std::string input)
    {
        std::ifstream f;
        f.open(input);
        std::string line;
        std::unordered_map<std::string, Valve> valves;
        while (std::getline(f, line))
        {
            Valve v;
            v.name = line.substr(6, line.find(" has")-6);
            line = line.substr(line.find('=') + 1);
            v.flow_rate = std::stoi(line);
            line = line.substr(line.find("valve"));
            line = line.substr(line.find(' ') + 1);
            while (line.find(',') != std::string::npos)
            {
                v.tunnels.push_back(line.substr(0, line.find(',')));
                line = line.substr(line.find(',') + 2);
            }
            v.tunnels.push_back(line);
            valves[v.name] = v;
        }
        return valves;
    }
    void floyd_warshall(std::unordered_map<std::string, Valve> &valves)
    {
        for (auto v : valves)
        {
            for (auto w : valves)
            {
                if (v.first != w.first)
                {
                    valves[v.first].distances[w.first] = 1000000;
                }
                else
                {
                    valves[v.first].distances[w.first] = 0;
                }
            }
        }
        for (auto v : valves)
        {
            for (auto t : v.second.tunnels)
            {
                valves[v.first].distances[t] = 1;
            }
        }
        for (auto k : valves)
        {
            for (auto i : valves)
            {
                for (auto j : valves)
                {
                    if (i.second.distances[j.first] > i.second.distances[k.first] + k.second.distances[j.first])
                    {
                        valves[i.first].distances[j.first] = i.second.distances[k.first] + k.second.distances[j.first];
                    }
                }
            }
        }
    }
    int part1(std::unordered_map<std::string, Valve> valves)
    {
        std::vector<std::string> relevant_valves;
        for (auto v : valves)
        {
            if (v.second.flow_rate > 0)
            {
                relevant_valves.push_back(v.first);
            }
        }
        return dfs(30, 0, "AA", valves, relevant_valves, std::set<std::string>());
    }
    int dfs(int max_time, int current_time, std::string valve, std::unordered_map<std::string, Valve>& valves, std::vector<std::string>& relevant_valves, std::set<std::string> opened)
    {
        if (opened.size() == relevant_valves.size())
        {
            return 0;
        }
        int pressure = 0;
        for (auto v : relevant_valves)
        {
            if (opened.count(v))
            {
                continue;
            }
            int new_time = current_time + valves[valve].distances[v] + 1;
            if (new_time < max_time)
            {
                opened.insert(v);
                pressure = std::max(pressure, valves[v].flow_rate * (max_time - new_time) + dfs(max_time, new_time, v, valves, relevant_valves, opened));
                opened.erase(v);
            }
        }
        return pressure;
    }
    int part2(std::unordered_map<std::string, Valve> valves)
    {
        std::vector<std::string> relevant_valves;
        for (auto v : valves)
        {
            if (v.second.flow_rate > 0)
            {
                relevant_valves.push_back(v.first);
            }
        }
        return dfs(26, 0, "AA", valves, relevant_valves, std::set<std::string>());
    }
}