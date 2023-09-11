# Specify the minimum required version of CMake for the project
cmake_minimum_required(VERSION 3.27.2)

# Define the project name
project(name)

# Find the required wxWidgets packages (gl, core, base) and optionally net
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})

# Define the source files for the main executable
set(SOURCE_FILES
  app.cpp
  unit.cpp
  mainframe.cpp
  NewWindow.cpp
  unit_test.cpp
)

# Create the main executable from the defined source files
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link your executable against wxWidgets libraries
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

# Set the output directory for the main executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/bin)

# Enable testing for the project
enable_testing()

# Create a test executable named 'tests_exe' from the source file 'unit_test.cpp'
add_executable(tests_exe unit_test.cpp) # Assuming unit_test.cpp is in the same directory as CMakeLists.txt

find_package(Catch2 REQUIRED)
target_link_libraries(tests_exe PRIVATE Catch2::Catch2)

# Define a test named 'UnitTests' that runs the 'tests_exe' executable
add_test(NAME UnitTests COMMAND tests_exe)

# Add a custom command to run the test executable after building it
add_custom_command(
  TARGET tests_exe
  POST_BUILD
  COMMAND tests_exe

  # Set the working directory for the test executable when it runs
  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
