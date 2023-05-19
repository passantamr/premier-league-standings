#include <vector>
#include <string>
#include "match.hpp"

#ifndef TEAM_HPP // Header guard
#define TEAM_HPP
class Team
{
private:
    std::string title;
    int index;

public:
    bool checked = false;
    Team(std::string title, int index);
    Team() = default;
    bool operator<(const Team &other) const
    {
        return this->title < other.title;
    }
    std::string getTitle();
    int getIndex();
};
#endif