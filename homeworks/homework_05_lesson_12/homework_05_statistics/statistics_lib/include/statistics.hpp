//
// Created by user on 22.07.23.
//

#ifndef HOMEWORK_05_LESSON_12_STATISTICS_HPP
#define HOMEWORK_05_LESSON_12_STATISTICS_HPP

namespace statistics {

    class IStatistics {
    public:
        virtual ~IStatistics() = default;

        virtual void update(double next) = 0;

        virtual double eval() const = 0;

        virtual const char *name() const = 0;
    };

}

#endif //HOMEWORK_05_LESSON_12_STATISTICS_HPP
