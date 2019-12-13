// Copyright 2019 Kirill <your_email>

#include <gtest/gtest.h>
#include "header.hpp"

TEST(Example, EmptyTest) {
SharedPtr pointer1();
EXPEXT_EQ(pointer1.get(), nullptr);

char *test_ptr1 = new char;
*test_ptr1 = 'a';

SharedPtr<char> pointer2(test_ptr1);
EXPEXT_EQ(pointer2.get(), test_ptr1);
EXPEXT_EQ(pointer2.use_count(), 1);

pointer1 = pointer2;

SharedPtr<char> pointer3(pointer2);
EXPEXT_EQ(pointer3.get(), pointer2.get());
EXPEXT_EQ(pointer2.use_count(), 3);
EXPEXT_EQ(pointer3.use_count(), 3);

char *test_ptr2 = new char;
*test_ptr2 = 'b';
SharedPtr<char> pointer4(test_ptr2);
EXPECT_EQ(*pointer4, *test_ptr2);

pointer3 = pointer4;
EXPEXT_EQ(pointer3.get(), pointer4.get());

pointer2.Swap(pointer3);
EXPEXT_EQ(pointer2.get(), pointer4.get());
EXPEXT_EQ(pointer3.get(), pointer1.get());

pointer4.reset();
EXPECT_EQ(pointer4.use_count(), 0);
EXPECT_EQ(pointer4.get(), nullptr);

pointer3.reset(test_ptr1);
EXPEXT_EQ(pointer1.get(), nullptr);
EXPEXT_EQ(pointer3.get(), nullptr);
EXPEXT_EQ(pointer1.use_count(), 0);
EXPEXT_EQ(pointer3.use_count(), 0);

}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
