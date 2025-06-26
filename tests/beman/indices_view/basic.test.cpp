// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <cstdint>
#include <limits>
#include <ranges>
#include <vector>

#include <gtest/gtest.h>

#include <beman/indices_view/indices.hpp>

namespace biv = beman::indices_view;

TEST(IndicesView, basic) {
    auto idx = biv::indices(3);

    EXPECT_TRUE(std::ranges::equal(idx, std::vector{0, 1, 2}));
    EXPECT_EQ(idx.size(), 3); // Ensure sized_range concept
}

TEST(IndicesView, EdgeCases) {
    // Empty range for n = 0
    auto empty = biv::indices(0);
    EXPECT_TRUE(empty.empty());

    // Large n (check for overflows)
    auto large = biv::indices(std::numeric_limits<std::uint16_t>::max());
    EXPECT_EQ(large.size(), 65'535);
}
