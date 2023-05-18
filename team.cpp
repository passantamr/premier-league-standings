#include "team.hpp"
#include "match.hpp"
#include <string>

Team::Team(const std::string title)
{
    this->title = title;
}

std::string Team::getTitle()
{
    return this->title;
}
