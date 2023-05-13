#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>
#include "match.hpp"
#include "team.hpp"

Match::Match(Team homeT, Team awayT, int homeGoals, int awayGoals, std::string date, int week)
{
    this->homeTeam = Team(homeT);
    this->awayTeam = Team(awayT);
    this->homeGoals = homeGoals;
    this->awayGoals = awayGoals;
    this->week = week;
    if (homeGoals > awayGoals)
        this->points = 3;
    else if (homeGoals == awayGoals)
        this->points = 1;

    std::tm tm = {};
    std::istringstream iss(date);
    iss >> std::get_time(&tm, "%d/%m/%Y");

    this->date = std::mktime(&tm);
}