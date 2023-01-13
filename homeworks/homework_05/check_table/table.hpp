#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include "structures.hpp"

class Table{
public:
    Table()=default;
    ~Table();

    void init();
    bool update(const Winner& winner);
    void show_results();
    void reset_results();

private:
    // void create()
    void write_header(std::fstream& file);
    void write_row(std::fstream& file, std::string val);
    void read_row(std::fstream& file, std::string& val);
    void parse_row(const std::string& val);
    void sort();

private:
    std::fstream file_;
    std::vector<Winner> table_;
    
};