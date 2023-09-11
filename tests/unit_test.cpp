#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "../include/unit.hpp"

TEST_CASE("Available units are correctly identified")
{
    DwarvishFighter dwarf1, dwarf2, dwarf3;
    ElvishArcher elf1, elf2;

    std::vector<Unit *> all_units = {&dwarf1, &dwarf2, &dwarf3, &elf1, &elf2};
    std::vector<Unit *> active_units = {&dwarf1, &elf1};

    auto result = available_units(all_units, active_units);

    REQUIRE(result.size() == 3);
    CHECK(std::find(result.begin(), result.end(), &dwarf2) != result.end());
    CHECK(std::find(result.begin(), result.end(), &dwarf3) != result.end());
    CHECK(std::find(result.begin(), result.end(), &elf2) != result.end());
}
