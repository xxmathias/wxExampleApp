#ifndef UNIT_HPP
#define UNIT_HPP

#include <string>
#include <cstdint>
#include "weapon.hpp"

class Unit {
public:
    Unit(std::string name, uint32_t health, uint32_t moves, Weapon melee_weapon, Weapon ranged_weapon)
        : name_(name), health_(health), moves_(moves), melee_weapon_(melee_weapon),ranged_weapon_(ranged_weapon) {}
    ~Unit() {}
    virtual std::string type_name() const = 0;
    std::string name() const { return name_; }
    uint32_t health() const { return health_; }
    uint32_t moves() const { return moves_; }
    const Weapon& melee_weapon() const { return melee_weapon_; }
    const Weapon& ranged_weapon() const { return ranged_weapon_; }
    
private:
    std::string name_;
    uint32_t health_;
    uint32_t moves_;
    Weapon melee_weapon_;
    Weapon ranged_weapon_;
};

std::vector<Unit*> available_units(const std::vector<Unit*>& all_units, const std::vector<Unit*>& active_units);

class DrakeBurner : public Unit {
public:
    DrakeBurner()
        : Unit("Drake Burner", 42, 5, Weapon("claws", 7, 2, WeaponType::blade, false), Weapon("Fire Breath", 6, 4, WeaponType::fire, true)) {}
    std::string type_name() const override { return "Drake Burner"; }
};

class DwarvishFighter : public Unit {
    public: DwarvishFighter() : Unit("Dwarvish Fighter", 38, 4, Weapon("Axe", 7, 3, WeaponType::blade, false), Weapon("Hammer", 8, 2, WeaponType::impact, false)) {}
    std::string type_name() const override { return "Dwarvish Fighter"; }
};

class ElvishArcher : public Unit {
    public: ElvishArcher() : Unit("Elvish Archer", 29, 6, Weapon("Sword", 5, 2, WeaponType::blade, false), Weapon("Bow", 5, 4, WeaponType::pierce, true)) {}
    std::string type_name() const override { return "Elvish Archer"; }

};

#endif // UNIT_HPP