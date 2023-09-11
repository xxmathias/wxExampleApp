# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.1)

# Define the project name
project(name)

# Find the necessary wxWidgets packages
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})

# List source files for the main app
set(MAIN_APP_SOURCE_FILES
  src/app.cpp
  src/unit.cpp
  src/mainframe.cpp
  src/NewWindow.cpp
)

# Create an executable for our main app
add_executable(${PROJECT_NAME} ${MAIN_APP_SOURCE_FILES})

# Link the main app with the wxWidgets libraries
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

# Set the output directory for the app's executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

# Enable testing
enable_testing()

# List source files for our tests
set(TEST_SOURCE_FILES
  tests/unit_test.cpp
  tests/catch_amalgamated.cpp
  src/unit.cpp # If our tests depend on this file
)

# Create an executable for our tests
add_executable(tests_exe ${TEST_SOURCE_FILES})

# Include the Catch2 amalgamated version
target_include_directories(tests_exe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Name the test and specify which executable to run for it
add_test(NAME UnitTests COMMAND tests_exe)

# Automatically run tests after building
add_custom_command(
  TARGET tests_exe
  POST_BUILD
  COMMAND tests_exe
  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
