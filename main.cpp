
#include <iostream>

#include "graph.hpp"
#include "hydrator.hpp"
int main()
{

    Graph graph = Graph();
    std::vector<std::vector<std::string>> content = hydrator(graph, "epl_results.csv");

    for (int i = 1; i < content.size(); i++)
    {
        graph.add_match(content[i]);
    }
    for (auto i : graph.getTeams())
    {
        std::cout << i->getTitle() << ":  ";
        for (auto k : graph.getTeamMatches(i))
        {

            std::cout << "( " << k->awayTeam->getTitle() << ", " << k->homeGoals << ", " << (k->checked? "CHECKED" : "NOT!") << ", " << k->awayGoals << ", " << k->points << " )";
        }
        std::cout << "\n";
    }

    return 0;
}
