#include <string>
#include "Character.h"

using namespace std;

Character::Character(HeroType t, const string & n, double h, double aS){
    this->type = t;
    this->name = n;
    if (h <= MAX_HEALTH){
        this->health = h;
    }
    else{
        this->health = MAX_HEALTH;
    }
    this->attackStrength = aS;
}

HeroType Character::getType() const{
    return type;
}

const string & Character::getName() const{
    return name;
}

int Character::getHealth() const{
    return static_cast<int>(health);
}

void Character::setHealth(double h){
    health = h;
}

void Character::damage(double d){
    health -= d;
}

bool Character::isAlive() const{
    if (getHealth() > 0){
        return true;
    }
    else{
        return false;
    }
}