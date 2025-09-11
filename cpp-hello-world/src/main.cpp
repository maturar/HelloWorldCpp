#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <gtest/gtest.h>

// Function to find the first string containing "nut"
// This function works with lambdas and is constexpr.
constexpr auto found(const std::array<std::string_view, 4>& arr) {
    return std::find_if(arr.begin(), arr.end(),
                        [](std::string_view str) {
                            return str.find("nut") != std::string_view::npos;
                        });
}

int main() {
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };
    auto is_nut_it{ found(arr)};
    if (is_nut_it != arr.end()) {
        std::cout << "Found: " << *is_nut_it << std::endl;
    } else {
        std::cout << "No nut found." << std::endl;
    }
    return 0;
}


TEST(FoundFunctionTest, FindsNutInArray) {
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };
    auto it = found(arr);
    ASSERT_NE(it, arr.end());
    EXPECT_EQ(*it, "walnut");
}

TEST(FoundFunctionTest, NoNutInArray) {
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "lemon", "grape" };
    auto it = found(arr);
    EXPECT_EQ(it, arr.end());
}

TEST(FoundFunctionTest, NutIsFirstElement) {
    constexpr std::array<std::string_view, 4> arr{ "nutmeg", "banana", "lemon", "grape" };
    auto it = found(arr);
    ASSERT_NE(it, arr.end());
    EXPECT_EQ(*it, "nutmeg");
}

TEST(FoundFunctionTest, MultipleNuts) {
    constexpr std::array<std::string_view, 4> arr{ "nutmeg", "walnut", "banana", "lemon" };
    auto it = found(arr);
    ASSERT_NE(it, arr.end());
    EXPECT_EQ(*it, "nutmeg"); // Should find the first occurrence
}

