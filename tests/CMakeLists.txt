set(ff_dir ${PROJECT_SOURCE_DIR}/../functionflow/ff/include)
set(ff_libs_dir ${PROJECT_SOURCE_DIR}/../functionflow/bin)

# MESSAGE(STATUS "FF dir: " ${ff_dir})

include_directories(${ffsae_dir} ${ff_dir})
set(ffsae_libs ffsae matio blaze)
set(ff_libs ff pthread)
link_directories(${ffsae_lib_dir} ${ff_libs_dir})

add_definitions(-DUSING_FF_NONBLOCKING_QUEUE)

# add_executable(t_blaze test_blaze.cpp)
# target_link_libraries(t_blaze ${ffsae_libs})
# 
# 
# add_executable(t_dsource test_dsource.cpp)
# target_link_libraries(t_dsource ${ffsae_libs})
# 
# add_executable(t_dtype test_dtype.cpp)
# target_link_libraries(t_dtype ${ffsae_libs})
# 
# add_executable(t_math test_math.cpp)
# target_link_libraries(t_math ${ffsae_libs})
# 
# add_executable(t_matio test_matio.cpp)
# target_link_libraries(t_matio ${ffsae_libs})
# 
# add_executable(t_matlib test_matlib.cpp)
# target_link_libraries(t_matlib ${ffsae_libs})
# 
# add_executable(t_sae test_sae.cpp)
# target_link_libraries(t_sae ${ffsae_libs})
# 
# add_executable(t_slice test_slice.cpp)
# target_link_libraries(t_slice ${ffsae_libs})
# 
# add_executable(t_perf test_perf.cpp)
# target_link_libraries(t_perf ${ffsae_libs} boost_system)

add_executable(p_sae sae_para.cpp)
target_link_libraries(p_sae ${ffsae_libs} ${ff_libs})