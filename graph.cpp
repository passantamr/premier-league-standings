#include <vector>
#include <string>
#include <algorithm>

#include "team.hpp"
#include "graph.hpp"
#include "match.hpp"

Graph::Graph(){};
void Graph::add_match(std::vector<std::string> row,int limit,int date)
{

    int week = std::stoi(row[0]);
    int matchdate;
    if(limit>0){
        if(week <= limit){
            auto home = this->add_team((std::string)row[2]);
            auto away = this->add_team((std::string)row[3]);
            if (row[4] != "-" || row[5] != "-" || row[6] != "-")
            {
                auto m = new Match(home, away, std::stoi(row[4]), std::stoi(row[5]), (std::string)row[1], std::stoi(row[0]));
                this->edges[home].push_back(m);
            }
        }
    }else if(date >0){
        std::tm tm = {};
        std::istringstream iss((std::string)row[1]);
        iss >> std::get_time(&tm, "%d/%m/%Y");
        matchdate = std::mktime(&tm);

        if(matchdate<= date){
            auto home = this->add_team((std::string)row[2]);
            auto away = this->add_team((std::string)row[3]);
            if (row[4] != "-")
            {
                auto m = new Match(home, away, std::stoi(row[4]), std::stoi(row[5]), (std::string)row[1], std::stoi(row[0]));
                this->edges[home].push_back(m);
            }
        }

    }else{
        auto home = this->add_team((std::string)row[2]);
        auto away = this->add_team((std::string)row[3]);
        if (row[4] != "-")
        {
            auto m = new Match(home, away, std::stoi(row[4]), std::stoi(row[5]), (std::string)row[1], std::stoi(row[0]));
            this->edges[home].push_back(m);
        }
    }
}
Team *Graph::add_team(std::string title)
{
    auto it = std::find_if(this->teams.begin(), this->teams.end(), [title](Team *team)
                           { return team->getTitle() == title; });

    if (it == this->teams.end())
    {
        
        auto team = new Team(title, this->index++);
        this->teams.push_back(team);
        return team;
    }
    return (*it);
}

std::vector<Team *> Graph::getTeams()
{
    return this->teams;
};
std::vector<Match *> Graph::getTeamMatches(Team *team)
{
    return this->edges[team];
}
