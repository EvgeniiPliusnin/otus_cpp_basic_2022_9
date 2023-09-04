//
// Created by user on 30.08.23.
//

#include "gtest/gtest.h"

#include "custom_list_container.hpp"

#include <iostream>

using namespace custom_containers;

class CustomLinkedList_Fixture : public ::testing::Test {
protected:
    CustomList<int> custom_list = CustomList{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
};

TEST_F(CustomLinkedList_Fixture, size) {
    const unsigned long int expected_size = 10;
    ASSERT_EQ(custom_list.size(), expected_size);
    custom_list.push_back(100);
    ASSERT_EQ(custom_list.size(), expected_size + 1);
}


TEST_F(CustomLinkedList_Fixture, push_back) {
    const unsigned long int expected_value = 100;
    custom_list.push_back(100);
    ASSERT_EQ(custom_list.back(), expected_value);
}

TEST_F(CustomLinkedList_Fixture, push_front) {
    const unsigned long int expected_value = 100;
    custom_list.push_front(100);
    ASSERT_EQ(custom_list.front(), expected_value);
}

TEST_F(CustomLinkedList_Fixture, insert) {
    const unsigned long int expected_value = 555;

    unsigned long int position = 5;
    custom_list.insert(position, 555);
    ASSERT_EQ(custom_list[position], expected_value);

    position = 0;
    custom_list.insert(position, 555);
    ASSERT_EQ(custom_list[position], expected_value);

    position = custom_list.size() - 1;
    custom_list.insert(position, 555);
    ASSERT_EQ(custom_list[position], expected_value);

}

TEST_F(CustomLinkedList_Fixture, pop_front) {
    CustomList<int> without_front = CustomList{1, 2, 3, 4, 5, 6, 7, 8, 9};
    custom_list.pop_front();
    ASSERT_EQ(without_front.size(), custom_list.size());
    for (unsigned long int index = 0; index < without_front.size(); ++index) {
        ASSERT_EQ(without_front[index], custom_list[index]);
    }
}

TEST_F(CustomLinkedList_Fixture, pop_back) {
    CustomList<int> without_back = CustomList{0, 1, 2, 3, 4, 5, 6, 7, 8};
    custom_list.pop_back();
    ASSERT_EQ(without_back.size(), custom_list.size());
    for (unsigned long int index = 0; index < without_back.size(); ++index) {
        ASSERT_EQ(without_back[index], custom_list[index]);
    }
}

TEST_F(CustomLinkedList_Fixture, remove_middle) {
    CustomList<int> without_front = CustomList{1, 2, 3, 4, 5, 6, 7, 8, 9};
    custom_list.pop_front();
    ASSERT_EQ(without_front.size(), custom_list.size());
    for (unsigned long int index = 0; index < without_front.size(); ++index) {
        ASSERT_EQ(without_front[index], custom_list[index]);
    }
}