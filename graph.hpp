#include <vector>
#include <map>
#include <string>
#include "team.hpp"
#include "match.hpp"
#include "standing.hpp"

#ifndef GRAPH_HPP // Header guard
#define GRAPH_HPP
class Graph
{
private:
    std::vector<Team*> teams;
    std::map<Team *, std::vector<Match *>> edges;
    int index = 0;

public:
    Graph();
    Team* add_team(std::string title);
    void add_match(std::vector<std::string> row);
    std::vector<Team*> getTeams();
    std::vector<Match*> getTeamMatches(Team* team);
    std::vector<Standing *> dfs();
};
#endif