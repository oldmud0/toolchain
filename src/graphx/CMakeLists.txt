project(GraphX)
cmake_minimum_required(VERSION 2.8.5)

add_library(graphx graphx.asm)
target_compile_options(graphx PUBLIC -genobj -NOigcase -NOlist -NOlistmac -quiet -sdiopt -cpu:EZ80F91 -NOdebug)
target_link_libraries(graphx -quiet -warn)
