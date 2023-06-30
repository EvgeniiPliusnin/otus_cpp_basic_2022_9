#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>

class Timer
{
public:
    void start()
    {
        start_time_ = std::chrono::system_clock::now();
        is_running_ = true;
    }

    void stop()
    {
        end_time_ = std::chrono::system_clock::now();
        is_running_ = false;
    }

    std::chrono::seconds get_elapsed_seconds()
    {
        std::chrono::time_point<std::chrono::system_clock> timer_point;

        if(is_running_)
        {
            timer_point = std::chrono::system_clock::now();
        }
        else
        {
            timer_point = end_time_;
        }

        return std::chrono::duration_cast<std::chrono::seconds>(timer_point - start_time_);
    }

private:
    std::chrono::time_point<std::chrono::system_clock> start_time_;
    std::chrono::time_point<std::chrono::system_clock> end_time_;
    bool is_running_ = false;
};