#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <vector>
#include <cstdint>

enum class WeaponType {
    arcane, 
    blade, 
    cold,
    fire, 
    impact,
    pierce
};

class Weapon {
public:
    Weapon(std::string name, uint32_t damage, uint32_t strikes, WeaponType type, bool is_ranged)
        : name_(name), damage_(damage), strikes_(strikes), type_(type), is_ranged_(is_ranged) {}
    std::string name() const {return name_;}
    uint32_t damage() const {return damage_;}
    uint32_t strikes() const {return strikes_;}
    WeaponType type() const {return type_;}
    bool is_ranged() const {return is_ranged_;}
private:
    std::string name_;
    uint32_t damage_;
    uint32_t strikes_;
    WeaponType type_;
    bool is_ranged_;
};


#endif