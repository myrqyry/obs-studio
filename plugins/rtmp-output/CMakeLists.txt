cmake_minimum_required(VERSION 3.16...3.25)

add_library(rtmp-output MODULE)
add_library(OBS::rtmp-output ALIAS rtmp-output)

target_sources(
  rtmp-output
  PRIVATE
          rtmp-output.c)

target_link_libraries(rtmp-output PRIVATE OBS::libobs)

set_target_properties_obs(rtmp-output PROPERTIES FOLDER plugins/rtmp-output PREFIX "")
