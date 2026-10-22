#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
    char result[10] = "abcdef";
    String::strncpy(result, "hi", 2);
    EXPECT_STREQ(result, "hi");
    
    String::strncpy(result, "hello", 3);
    EXPECT_STREQ(result, "hel");
}

TEST(StringFunction, strcat) {
    char result[20] = "Hello";
    String::strcat(result, " World");
    EXPECT_STREQ(result, "Hello World");
}

TEST(StringFunction, strncat) {
    char result[20] = "Hello";
    String::strncat(result, " World!", 3);
    EXPECT_STREQ(result, "Hello Wo");
}

TEST(StringFunction, strcmp) {
    EXPECT_EQ(String::strcmp("abc", "abc"), 0);
    EXPECT_LT(String::strcmp("abc", "abd"), 0);
    EXPECT_GT(String::strcmp("abd", "abc"), 0);
}

TEST(StringFunction, strncmp) {
    EXPECT_EQ(String::strncmp("abcdef", "abxyz", 2), 0);
    EXPECT_LT(String::strncmp("abc", "abd", 3), 0);
}

TEST(StringFunction, reverse_cpy) {
    char result[20];
    String::reverse_cpy(result, "hello");
    EXPECT_STREQ(result, "olleh");
    
    String::reverse_cpy(result, "");
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strchr) {
    const char *s = "hello";
    EXPECT_EQ(*(String::strchr(s, 'e')), 'e');
    EXPECT_EQ(String::strchr(s, 'z'), nullptr);
}

TEST(StringFunction, strstr) {
    const char *haystack = "hello world";
    EXPECT_STREQ(String::strstr(haystack, "world"), "world");
    EXPECT_EQ(String::strstr(haystack, "foo"), nullptr);
}
