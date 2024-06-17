#pragma once
#include "Agent.h"
#include <random>
#include <ctime>
#include <glm/gtx/rotate_vector.hpp>
#include "Human.h"
class Zombie :
    public Agent
{
    glm::vec2 direction;
public:
    Zombie();
    ~Zombie();
    void init(float speed, glm::vec2 position);
    void update(vector<string>& levelData,
        vector<Human*>& humans,
        vector<Zombie*>& zombies);
};

