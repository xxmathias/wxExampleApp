#include <vector>
#include <algorithm>
#include "unit.hpp"

std::vector<Unit*> available_units(const std::vector<Unit*>& all_units, const std::vector<Unit*>& active_units) {
    std::vector<Unit*> available;

    for (auto& unit : all_units) {
        if (std::find(active_units.begin(), active_units.end(), unit) == active_units.end()) {
            // This unit is not in the active list, so it's available
            available.push_back(unit);
        }
    }

    return available;
}
