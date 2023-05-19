
#include <iostream>
#include <vector>
#include <algorithm>

#include "graph.hpp"
#include "hydrator.hpp"
#include "standing.hpp"
#include "team.hpp"

int main(int argc, char *argv[])
{

    Graph graph = Graph();
    std::vector<std::vector<std::string>> content = hydrator(graph, "epl_results.csv");

    for (int i = 1; i < content.size(); i++)
    {
        graph.add_match(content[i]);
        }

        std::vector<Standing *> standings = graph.dfs();
        /* std::sort(standings.begin(), standings.end()); */
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
        for (auto entry : standings)
        {
            std::cout << entry->team.getTitle() << ", " << entry->getMatches() << ", " << entry->getWin() << ", " << entry->getDraw() << ", " << entry->getLose() << ", " << entry->getGoalsScored() << ", " << entry->getGoalsRecived() << ", " << entry->getGoalDiff() << ", " << entry->getPoints() << std::endl;
        }

        return 0;
    }
