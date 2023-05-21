#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "graph.hpp"
#include "hydrator.hpp"
#include "standing.hpp"
#include "team.hpp"
struct sortv
{
    inline bool operator()(Standing *s1, Standing *s2)
    {
        if (s1->getPoints() == s2->getPoints())
        {
            if (s1->getGoalDiff() == s2->getGoalDiff())
            {
                if (s1->getGoalsScored() == s2->getGoalsScored())
                {
                    return s1->team.getTitle() < s2->team.getTitle();
                }
                return s1->getGoalsScored() > s2->getGoalsScored();
            }
            return s1->getGoalDiff() > s2->getGoalDiff();
        }

        return s1->getPoints() > s2->getPoints();
    }
};
int main(int argc, char const *argv[])
{
    int num = -1;
    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-w"))
        {
            num = std::atoi(argv[i + 1]);
        }
    }


    Graph graph = Graph();
    std::vector<std::vector<std::string>> content = hydrator(graph, "epl_results.csv");

    for (int i = 1; i < content.size(); i++)
    {
        graph.add_match(content[i], num);
    }

    std::vector<Standing *> standings = graph.dfs();
    std::sort(standings.begin(), standings.end(), sortv());
    std::cout << "Team"
              << ", "
              << "Matches"
              << ", "
              << "Win"
              << ", "
              << "Draw"
              << ", "
              << "Lose"
              << ", "
              << "GF"
              << ", "
              << "GA"
              << ", "
              << "GD"
              << ", "
              << "Points" << std::endl;
    std::ofstream output;
    output.open("result.csv");
    output << "Team"
           << ","
           << "Matches"
           << ","
           << "Win"
           << ","
           << "Draw"
           << ","
           << "Lose"
           << ","
           << "GF"
           << ","
           << "GA"
           << ","
           << "GD"
           << ","
           << "Points"
           << "\n";
    for (auto entry : standings)
    {
        std::cout << entry->team.getTitle() << ", " << entry->getMatches() << ", " << entry->getWin() << ", " << entry->getDraw() << ", " << entry->getLose() << ", " << entry->getGoalsScored() << ", " << entry->getGoalsRecived() << ", " << entry->getGoalDiff() << ", " << entry->getPoints() << std::endl;
        output << entry->team.getTitle() << "," << entry->getMatches() << "," << entry->getWin() << "," << entry->getDraw() << "," << entry->getLose() << "," << entry->getGoalsScored() << "," << entry->getGoalsRecived() << "," << entry->getGoalDiff() << "," << entry->getPoints() << "\n";
    }
    output.close();
    return 0;
}
