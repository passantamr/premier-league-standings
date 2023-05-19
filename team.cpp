#include "team.hpp"
#include "match.hpp"
#include <string>

Team::Team(const std::string title, int index)
{
    this->title = title;
    this->index = index;
}

std::string Team::getTitle()
{
    return this->title;
}
int Team::getIndex()
{
    return this->index;
}
