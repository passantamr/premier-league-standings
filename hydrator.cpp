#include "graph.hpp"
#include "hydrator.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
std::vector<std::vector<std::string>> hydrator(Graph &graph, std::string file_name)
{

    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;

    std::fstream file(file_name, std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            std::stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        exit(1);
    return content;
}