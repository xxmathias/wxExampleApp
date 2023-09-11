# Gather all header files in this directory
file(GLOB HEADER_FILES "*.hpp")
add_library(include_headers INTERFACE ${HEADER_FILES})
