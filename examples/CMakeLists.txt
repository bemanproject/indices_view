# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

set(ALL_EXAMPLES basic_example paper_example)

message("Examples to be built: ${ALL_EXAMPLES}")

foreach(example ${ALL_EXAMPLES})
    add_executable(beman.indices_view.examples.${example})
    target_sources(
        beman.indices_view.examples.${example}
        PRIVATE ${example}.cpp
    )
    target_link_libraries(
        beman.indices_view.examples.${example}
        PRIVATE beman::indices_view
    )
endforeach()
