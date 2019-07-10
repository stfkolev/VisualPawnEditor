file(GLOB_RECURSE CPPS  ./*.cpp )

add_executable(visualpawn ${CPPS})

target_link_libraries(visualpawn nodes)
