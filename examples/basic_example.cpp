#include <iostream>

#include <beman/indices_view/indices.hpp>

namespace biv = beman::indices_view;

// Example usage of indices_view to print indices from 0 to n-1; very basic example.
int main() {
    for (auto i : biv::indices(5)) {
        std::cout << i; // prints 01234
    }
    return 0;
}
