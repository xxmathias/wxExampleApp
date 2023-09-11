# Minimum CMake version? Because we're not cavemen.
cmake_minimum_required(VERSION 3.27.2)

# "name"? Really? Well, every project needs a name, even if it's... this.
project(name)

# Hunting for wxWidgets. It's like a treasure hunt, but less fun.
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})

# Our main app's source files. The "A-Team" of our project.
set(MAIN_APP_SOURCE_FILES
  src/app.cpp
  src/unit.cpp
  src/mainframe.cpp
  src/NewWindow.cpp
)

# Turning source files into an executable. It's like magic, but more tedious.
add_executable(${PROJECT_NAME} ${MAIN_APP_SOURCE_FILES})

# Linking with wxWidgets. Because our app needs some fancy shoes to dance.
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

# Where should our masterpiece end up? In the limelight, of course.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/bin)

# Testing? Sure, because we're not confident enough in our code.
enable_testing()

# Our test files. The "B-Team", but don't tell them that.
set(TEST_SOURCE_FILES
  tests/unit_test.cpp
  tests/catch_amalgamated.cpp
  src/unit.cpp
)

# Making an executable for tests. Because they need to feel special too.
add_executable(tests_exe ${TEST_SOURCE_FILES})

# Including directories for our "B-Team".
target_include_directories(tests_exe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# Naming our test. It's like naming a pet, but less commitment.
add_test(NAME UnitTests COMMAND tests_exe)

# Running tests after building. Because we love living on the edge.
add_custom_command(
  TARGET tests_exe
  POST_BUILD
  COMMAND tests_exe
  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

# And that's it. Wasn't that... fun?
