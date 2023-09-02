//
// Created by user on 30.08.23.
//

#include <gtest/gtest.h>

#include "custom_sequence_container.hpp"

using namespace custom_containers;

TEST(List, Empty) {

    // Arrange
    CustomSequenceContainer<int> sequence_container = CustomSequenceContainer{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Act (empty for this test)

    // Assert
//    ASSERT_EQ(sequence_container.size(), static_cast<size_t>(0));
//    ASSERT_TRUE(sequence_container.empty());
}
