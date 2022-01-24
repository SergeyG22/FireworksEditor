cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(PROJECT_NAME Fireworks)
project(${PROJECT_NAME})

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
        TGUI
	GIT_REPOSITORY https://github.com/texus/TGUI.git
	GIT_TAG 0.8
)
FetchContent_MakeAvailable(TGUI)


add_executable(${PROJECT_NAME} 
src/main.cpp

src/Graphics/fireworks.cpp
    include/fireworks.h
src/Graphics/gui.cpp
    include/gui.h
include/number_generator.h
) 

set_target_properties(
     ${PROJECT_NAME} PROPERTIES
     CXX_STANDARD 14
     CXX_STANDARD_REQUIRED ON
     CXX_EXTENSIONS NO
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        sfml-audio
        sfml-graphics
        sfml-system
        sfml-window
	sfml-network
	tgui 
	tgui-d
)



