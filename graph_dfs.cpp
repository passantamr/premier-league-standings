
#include <iostream>
#include <stack>
#include <vector>

#include "standing.hpp"
#include "graph.hpp"

using namespace std;

vector<Standing *> Graph::dfs()
{
    vector<Standing *> standings(this->getTeams().size());
    for (auto &i : this->getTeams())
    {
        standings[i->getIndex()] = new Standing(*i);
    }

    stack<Match *> stack;

    stack.push(this->getTeamMatches(this->getTeams()[0])[0]);

    while (!stack.empty())
    {
        Match *match = stack.top();
        stack.pop();

        if (!match->checked)
        {
            /* cout << match->homeTeam->getTitle() << " vs " << match->awayTeam->getTitle() << endl; */
            standings[match->homeTeam->getIndex()]->update(match, true);
            standings[match->awayTeam->getIndex()]->update(match, false);

            match->checked = true;

            for (Team *team : match->teams())
            {
                for (Match *otherMatch : this->getTeamMatches(team))
                {
                    if (!otherMatch->checked)
                    {
                        stack.push(otherMatch);
                    }
                }
            }
        }
    }

    return standings;
}