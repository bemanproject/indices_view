// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef BEMAN_INDICES_VIEW_INDICES_HPP
#define BEMAN_INDICES_VIEW_INDICES_HPP

#include <concepts>
#include <ranges>

namespace beman::indices_view {
    inline constexpr auto indices = [] <std::integral I> (I n) {
        return std::views::iota(I{}, n);
    };
} // namespace beman::indices_view

#endif // BEMAN_INDICES_VIEW_INDICES_HPP
