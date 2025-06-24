#include <iostream>
#include <vector>

#include <beman/indices_view/indices.hpp>

namespace biv = beman::indices_view;

// Example given in the paper for `std::views::indices`, adapted to work with C++20.
int main() {
    std::vector rng(5, 0);

    std::cout << "[";
    bool first = true;
    for (auto i : biv::indices(std::ranges::size(rng))) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << i;
        first = false;
    }
    std::cout << "]\n";

    return 0;
}
