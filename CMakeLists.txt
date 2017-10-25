cmake_minimum_required(VERSION 2.8)
project(wiki_stats)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES wiki_stats.cpp wiki_graph.cpp wiki_graph.hpp utf8.cpp utf8.hpp)
add_executable(wiki_stats ${SOURCE_FILES})
