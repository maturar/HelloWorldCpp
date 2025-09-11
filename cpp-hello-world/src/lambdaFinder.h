#pragma once
#include <array>
#include <string_view>
#include <algorithm>

class LambdaFinder{
    public:
        void doExample();
        constexpr auto found(const std::array<std::string_view, 4>& arr);
};
