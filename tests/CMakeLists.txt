file(GLOB TEST_SOURCE_FILES "*.cpp")

# Füge die Datei mit der Definition der Funktion hinzu, falls sie vorhanden ist
list(APPEND TEST_SOURCE_FILES "../src/unit.cpp")

add_executable(tests_exe ${TEST_SOURCE_FILES})

