cmake_minimum_required(VERSION 3.10)

project(SFML_App)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17) # Or a later standard if needed
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_GENERATOR_PLATFORM x64)

set(SFML_ROOT "C:/SFML-3.0.0")
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIB_DIR "${SFML_ROOT}/lib")

set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")

set(SFML_LIBRARIES C:/SFML-3.0.0/lib/sfml-system.lib C:/SFML-3.0.0/lib/sfml-graphics.lib C:/SFML-3.0.0/lib/sfml-window.lib C:/SFML-3.0.0/lib/sfml-audio.lib)

# the following variable is not defined at all
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(SFML_LIBRARIES  C:/SFML-3.0.0/lib/sfml-system-d.lib C:/SFML-3.0.0/lib/sfml-graphics-d.lib C:/SFML-3.0.0/lib/sfml-window-d.lib C:/SFML-3.0.0/lib/sfml-audio-d.lib)
endif()

# include SFML headers
include_directories(${SFML_INCLUDE_DIR})

add_executable(${PROJECT_NAME} src/Tennis.cpp)
#add_executable(${PROJECT_NAME} src/SoundCapture.cpp)

# Link SFML libraries
#target_link_directories(${PROJECT_NAME} PRIVATE ${SFML_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SFML_LIBRARIES})

# Copy SFML shared libraries to the output directory (for running the executable)
if(WIN32)
    foreach(LIB ${SFML_DEPENDENCIES})
        add_custom_command(
            TARGET SFML_App POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${LIB}"
                    "$<TARGET_FILE_DIR:SFML_App>"
            DEPENDS $<TARGET_FILE:SFML_App>
        )
    endforeach()
endif()

# Copy resources folder after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)
