
include_directories(${ffsae_dir})
set(ffsae_libs ffsae matio blaze)
link_directories(${ffsae_lib_dir})

add_executable(t_blaze test_blaze.cpp)
target_link_libraries(t_blaze ${ffsae_libs})


add_executable(t_dsource test_dsource.cpp)
target_link_libraries(t_dsource ${ffsae_libs})

add_executable(t_dtype test_dtype.cpp)
target_link_libraries(t_dtype ${ffsae_libs})

add_executable(t_math test_math.cpp)
target_link_libraries(t_math ${ffsae_libs})

add_executable(t_matio test_matio.cpp)
target_link_libraries(t_matio ${ffsae_libs})

add_executable(t_matlib test_matlib.cpp)
target_link_libraries(t_matlib ${ffsae_libs})

add_executable(t_sae test_sae.cpp)
target_link_libraries(t_sae ${ffsae_libs})

add_executable(t_slice test_slice.cpp)
target_link_libraries(t_slice ${ffsae_libs})

add_executable(t_perf test_perf.cpp)
target_link_libraries(t_perf ${ffsae_libs} boost_system)

