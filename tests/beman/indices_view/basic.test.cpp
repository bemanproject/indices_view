// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <algorithm>
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

    // The code below doesn't work on Clang versions older than 18.1.0.
    // The root cause of the issue is described in https://github.com/llvm/llvm-project/issues/67551; it's a compiler
    // bug and not a problem in our library code. The bug was fixed in LLVM in
    // https://github.com/llvm/llvm-project/pull/67819, which is contained in all Clang versions starting from 18.1.0.
    // This godbolt example (https://godbolt.org/z/fjbo87MbK) shows that the code compiles if Clang is v18.1.0, and
    // doesn't compile on any Clang version older that. Until XCode ships with a Clang version that contains the fix,
    // we cannot use this test in our MacOS builds. We can use this table
    // (https://en.wikipedia.org/wiki/Xcode#Xcode_15.0_-_16.x_(since_visionOS_support)_2) to track the status of
    // AppleClang versions and their corresponding Clang versions.
#if !defined(_LIBCPP_VERSION) || _LIBCPP_VERSION >= 180100
    // Large n (check for overflows)
    auto large = biv::indices(std::numeric_limits<std::uint16_t>::max());
    EXPECT_EQ(large.size(), 65'535);
#endif
}
