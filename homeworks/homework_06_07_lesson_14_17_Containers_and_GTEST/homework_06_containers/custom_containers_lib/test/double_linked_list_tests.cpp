//
// Created by user on 30.08.23.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "custom_list_container.hpp"
#include <iostream>

using namespace custom_containers;


class CustomLinkedList : public ::testing::Test {
protected:
    CustomList<int> custom_list = CustomList{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
};

TEST_F(CustomLinkedList, size) {
    const unsigned long int expected_size = 10;

    ASSERT_EQ(custom_list.size(), expected_size);
}


TEST_F(CustomLinkedList, push_back) {
    custom_list.push_back(30);
}
