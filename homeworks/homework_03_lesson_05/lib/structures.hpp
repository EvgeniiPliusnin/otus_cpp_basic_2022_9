#pragma once

#include <chrono>

struct Result {
    std::string user_name;
    std::chrono::duration<std::chrono::seconds> record_time;
    int score;
};

