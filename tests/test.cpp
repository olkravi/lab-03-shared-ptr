// Copyright 2019 Kirill <your_email>

#include <gtest/gtest.h>
#include "header.hpp"

TEST(Example, EmptyTest) {
SharedPtr<char> pointer1;
EXPECT_EQ(pointer1.get(), nullptr);

char *test_ptr1 = new char;
*test_ptr1 = 'a';

SharedPtr<char> pointer2(test_ptr1);
EXPECT_EQ(pointer2.get(), test_ptr1);
EXPECT_EQ(pointer2.use_count(), 1);

SharedPtr<char> pointer3(pointer2);
EXPECT_EQ(pointer3.get(), pointer2.get());
EXPECT_EQ(pointer2.use_count(), 3);
EXPECT_EQ(pointer3.use_count(), 3);

char *test_ptr2 = new char;
*test_ptr2 = 'b';
SharedPtr<char> pointer4(test_ptr2);
EXPECT_EQ(*pointer4, *test_ptr2);

pointer3 = pointer4;
EXPECT_EQ(pointer3.get(), pointer4.get());

pointer2.Swap(pointer3);
EXPECT_EQ(pointer2.get(), pointer4.get());
EXPECT_EQ(pointer3.get(), test_ptr1);

pointer4.reset();
EXPECT_EQ(pointer4.use_count(), 0);
EXPECT_EQ(pointer4.get(), nullptr);

pointer2.reset(test_ptr1);
EXPECT_EQ(pointer2.get(), test_ptr1);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
