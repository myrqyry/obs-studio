cmake_minimum_required(VERSION 3.16...3.25)

find_package(CEF 95 REQUIRED)
find_package(nlohmann_json 3.11 REQUIRED)

add_library(web-browser MODULE)
add_library(OBS::web-browser ALIAS web-browser)

target_sources(
  web-browser
  PRIVATE
          web-browser-plugin.cpp
          web-browser-source.cpp
          web-browser-source.hpp)

target_compile_features(web-browser PRIVATE cxx_std_17)
target_link_libraries(web-browser PRIVATE OBS::libobs OBS::frontend-api)

set_target_properties_obs(web-browser PROPERTIES FOLDER plugins/web-browser PREFIX "")
