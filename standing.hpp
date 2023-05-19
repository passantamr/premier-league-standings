#include <vector>
#include <string>
#include "match.hpp"

#ifndef STANDING_HPP // Header guard
#define STANDING_HPP
class Standing
{
private:
    int matches, win, lose, draw, goalsScored, goalsRecived, points;
    void updateHome(Match *);
    void updateAway(Match *);

public:
    Team team;
    Standing(Team);
    void update(Match *, bool);
    int getMatches();
    int getWin();
    int getLose();
    int getDraw();
    int getGoalsScored();
    int getGoalsRecived();
    int getPoints();
    int getGoalDiff();
};
#endif