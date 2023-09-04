//
// Created by user on 30.08.23.
//

#include <gtest/gtest.h>

#include "custom_sequence_container.hpp"

using namespace custom_containers;

class CustomSequenceContainer_Fixture : public ::testing::Test {
protected:
    CustomSequenceContainer<int> sequence_container = CustomSequenceContainer{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
};

TEST_F(CustomSequenceContainer_Fixture, size) {
    unsigned long int expected_size = 10;
    ASSERT_EQ(expected_size, sequence_container.size());
}

TEST_F(CustomSequenceContainer_Fixture, push_back) {
    int expected_value = 888;
    sequence_container.push_back(expected_value);
    ASSERT_EQ(expected_value, sequence_container[10]);
}

TEST_F(CustomSequenceContainer_Fixture, push_front) {
    int expected_value = 111;
    sequence_container.push_front(expected_value);
    ASSERT_EQ(expected_value, sequence_container[0]);
}

TEST_F(CustomSequenceContainer_Fixture, insert) {
    int expected_value = 555;
    unsigned long int position = 5;
    sequence_container.insert(position, expected_value);
    ASSERT_EQ(expected_value, sequence_container[position]);
}

TEST_F(CustomSequenceContainer_Fixture, pop_back) {
    CustomSequenceContainer<int> without_back = CustomSequenceContainer{0, 1, 2, 3, 4, 5, 6, 7, 8};
    sequence_container.pop_back();
    ASSERT_EQ(sequence_container.size(), without_back.size());
    for (unsigned long int index = 0; index < without_back.size(); ++index) {
        ASSERT_EQ(sequence_container[index], without_back[index]);
    }
}

TEST_F(CustomSequenceContainer_Fixture, pop_front) {
    CustomSequenceContainer<int> without_front = CustomSequenceContainer{1, 2, 3, 4, 5, 6, 7, 8, 9};
    sequence_container.pop_front();
    ASSERT_EQ(without_front.size(), sequence_container.size());
    for (unsigned long int index = 0; index < without_front.size(); ++index) {
        ASSERT_EQ(without_front[index], sequence_container[index]);
    }
}

TEST_F(CustomSequenceContainer_Fixture, erase) {
    CustomSequenceContainer<int> reference_container = CustomSequenceContainer{0, 1, 2, 3, 4, 6, 7, 8, 9};
    sequence_container.erase(5);
    ASSERT_EQ(reference_container.size(), sequence_container.size());
    for (unsigned long int index = 0; index < reference_container.size(); ++index) {
        ASSERT_EQ(reference_container[index], sequence_container[index]);
    }

    sequence_container.erase();
    ASSERT_EQ(0, sequence_container.size());
}

TEST_F(CustomSequenceContainer_Fixture, get_value) {
    const int expected_value = 9;
    ASSERT_EQ(sequence_container[9], expected_value);
}
