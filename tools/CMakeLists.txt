include_directories(${ffsae_dir})
set(ffsae_libs ffsae matio blaze)
link_directories(${ffsae_lib_dir})

add_executable(matview matview.cpp)
target_link_libraries(matview ${ffsae_libs})
