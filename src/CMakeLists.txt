set(boost_dir /home/sherry/boost_1_55_0)

link_directories(${boost_dir}/stage/lib)

include_directories(${ffsae_dir} ${boost_dir})

set(src dsource/Slice.cpp
  dsource/read.cpp
  nn/fbnn.cpp
  sae/sae.cpp
  utils/math.cpp
  utils/matlib.cpp
  utils/utils.cpp
  nn/arch.cpp)

ADD_LIBRARY(ffsae SHARED ${src})
ADD_LIBRARY(ffsae_s STATIC ${src})
target_link_libraries(ffsae matio boost_system boost_date_time boost_thread)
target_link_libraries(ffsae_s matio boost_system boost_date_time boost_thread)

SET_TARGET_PROPERTIES(ffsae_s PROPERTIES OUTPUT_NAME "ffsae")
