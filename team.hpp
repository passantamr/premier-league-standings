#include <vector>
#include <string>
#include "match.hpp"

#ifndef TEAM_HPP // Header guard
#define TEAM_HPP
class Team
{
private:
    std::string title;

public:
    bool checked = false;
    Team(std::string title);
    Team() = default;
    bool operator<(const Team &other) const
    {
        return this->title < other.title;
    }
    std::string getTitle();
};
#endif