#include "standing.hpp"
#include "match.hpp"

Standing::Standing(Team team)
{
    matches = 0;
    win = 0;
    lose = 0;
    draw = 0;
    goalsScored = 0;
    goalsRecived = 0;
    points = 0;
    this->team = team;
}

void Standing::update(Match *match, bool isHome = true)
{
    this->matches++;
    if(isHome)
        this->updateHome(match);
    else
        this->updateAway(match);
    
}
void Standing::updateHome(Match *match){
    this->points += match->points;
    this->goalsRecived += match->awayGoals;
    this->goalsScored += match->homeGoals;
    switch (match->points)
    {
    case 0:
        this->lose++;
        break;
    case 1:
        this->draw++;
        break;

    default:
        this->win++;
        break;
    }
}
void Standing::updateAway(Match *match){
    this->goalsScored += match->awayGoals;
    this->goalsRecived += match->homeGoals;
    switch (match->points)
    {
    case 0:
        this->win++;
        this->points += 3;
        break;
    case 1:
        this->draw++;
        this->points += 1;
        break;

    default:
        this->lose++;
        break;
    }
}
int Standing::getMatches()
{
    return this->matches;
}
int Standing::getWin()
{
    return this->win;
}
int Standing::getLose()
{
    return this->lose;
}
int Standing::getDraw()
{
    return this->draw;
}
int Standing::getGoalsScored()
{
    return this->goalsScored;
}
int Standing::getGoalsRecived()
{
    return this->goalsRecived;
}
int Standing::getGoalDiff()
{
    return this->goalsScored - this->goalsRecived;
}
int Standing::getPoints()
{
    return this->points;
}