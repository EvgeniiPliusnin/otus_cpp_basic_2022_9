#pragma once

#include <chrono>
#include <unordered_set>

struct Result {
    std::string user_name;
    std::chrono::seconds record_time;
    int score;
};

//std::unordered_set<int>
