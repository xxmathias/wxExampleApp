# Let's start by setting the minimum CMake version we need
cmake_minimum_required(VERSION 3.27.2)

# Giving our project a cool name
project(name)

# Hunting down the wxWidgets packages we'll need
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})

# Listing out the source files for our main app
set(MAIN_APP_SOURCE_FILES
  app.cpp
  unit.cpp
  mainframe.cpp
  NewWindow.cpp
)

# Let's turn those source files into an executable
add_executable(${PROJECT_NAME} ${MAIN_APP_SOURCE_FILES})

# Linking our app with the wxWidgets libraries
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

# Setting where our app's executable should end up
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/bin)

# Time to set up testing!
enable_testing()

# Listing out the source files for our tests
set(TEST_SOURCE_FILES
  unit_test.cpp
  catch_amalgamated.cpp
  unit.cpp # If our tests depend on this file
)

# Making an executable out of our test source files
add_executable(tests_exe ${TEST_SOURCE_FILES})

# Since we're using the Catch2 amalgamated version, we need to include it
target_include_directories(tests_exe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Naming our test and telling CMake which executable to run for it
add_test(NAME UnitTests COMMAND tests_exe)

# After building, let's run our tests automatically
add_custom_command(
  TARGET tests_exe
  POST_BUILD
  COMMAND tests_exe
  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
