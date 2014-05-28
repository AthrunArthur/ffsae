include_directories(${ffsae_dir})

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
target_link_libraries(ffsae matio)
target_link_libraries(ffsae_s matio)

SET_TARGET_PROPERTIES(ffsae_s PROPERTIES OUTPUT_NAME "ffsae")
