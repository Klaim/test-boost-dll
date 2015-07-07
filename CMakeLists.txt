cmake_minimum_required(VERSION 3.3)

set( Boost_USE_STATIC_LIBS        ON )
set( Boost_USE_MULTITHREADED      ON )
set( Boost_USE_STATIC_RUNTIME    OFF )

find_package( Boost 1.58.0 COMPONENTS filesystem system )
include_directories( ${Boost_INCLUDE_DIR} )


set( PLUGIN_API_HEADERS
  api.hpp
  plugin.hpp
)

add_executable( application application.cpp ${PLUGIN_API_HEADERS} )
target_link_libraries( application ${Boost_LIBRARIES} )

add_library( pluginA MODULE pluginA.cpp ${PLUGIN_API_HEADERS} )

add_library( pluginB MODULE pluginB.cpp ${PLUGIN_API_HEADERS} )

add_dependencies( application pluginA pluginB )
