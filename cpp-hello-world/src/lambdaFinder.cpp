#include <iostream>
#include <gtest/gtest.h>
#include "lambdaFinder.h"

constexpr auto LambdaFinder::found(const std::array<std::string_view, 4>& arr) const {
    return std::find_if(arr.begin(), arr.end(),
                        [](std::string_view str) {
                            return str.find("nut") != std::string_view::npos;
                        });
}

void LambdaFinder::doExample() const {
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };
    auto is_nut_it{ found(arr)};
    if (is_nut_it != arr.end()) {
        std::cout << "Found: " << *is_nut_it << std::endl;
    } else {
        std::cout << "No nut found." << std::endl;
    }
}

TEST(FoundFunctionTest, FindsNutInArray) {
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };
    LambdaFinder finder;
    auto it = finder.found(arr);
    ASSERT_NE(it, arr.end());
    EXPECT_EQ(*it, "walnut");
}

TEST(FoundFunctionTest, NoNutInArray) {
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "lemon", "grape" };
    LambdaFinder finder;
    auto it = finder.found(arr);
    EXPECT_EQ(it, arr.end());
}

TEST(FoundFunctionTest, NutIsFirstElement) {
    constexpr std::array<std::string_view, 4> arr{ "nutmeg", "banana", "lemon", "grape" };
    LambdaFinder finder;
    auto it = finder.found(arr);
    ASSERT_NE(it, arr.end());
    EXPECT_EQ(*it, "nutmeg");
}

TEST(FoundFunctionTest, MultipleNuts) {
    constexpr std::array<std::string_view, 4> arr{ "nutmeg", "walnut", "banana", "lemon" };
    LambdaFinder finder;
    auto it = finder.found(arr);
    ASSERT_NE(it, arr.end());
    EXPECT_EQ(*it, "nutmeg"); // Should find the first occurrence
}

