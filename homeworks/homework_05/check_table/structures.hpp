#pragma once

#include <chrono>

struct Time
{
    std::chrono::seconds sec;
    std::chrono::minutes min;
    std::chrono::hours hours;
};

struct Winner
{
    int position;
    std::string user_name;
    Time recored_time;
    int high_score;
};


