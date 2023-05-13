#include <string>
#include <iomanip>

#ifndef MATCH_HPP // Header guard
#define MATCH_HPP
#include "team.hpp"
class Match
{
public:
    Team homeTeam, awayTeam;
    int homeGoals;
    int points = 0, awayGoals, week;
    std::time_t date;
    Match(Team homeT, Team awayT, int homeGoals, int awayGoals, std::string date, int week);
    Match() = default;
};
#endif