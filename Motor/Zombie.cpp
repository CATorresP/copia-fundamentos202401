#include "Zombie.h"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void Zombie::init(float speed, glm::vec2 position)
{
	this->speed = speed;
	this->position = position;
	color.set(80, 30, 80, 255);
}

void Zombie::update(vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies)
{
	// Seguimiento simple al humano más cercano
	Human* closest_human;
	float min_distance, distance;
	glm::vec2 direction;
	glm::vec2 pos;

	std::mt19937 randomEngine(time(nullptr));
	std::uniform_real_distribution<float>randRotate(-40.0f, 40.0f);
	
	if (!humans.empty()) {
		closest_human = humans[0];
		direction = closest_human->getPosition() - this->position;
		min_distance = glm::length(direction);
		distance = 0;

		for (Human* human : humans) {
			//pos = human->getPosition();
			//direction = pos - this->position;
			distance = glm::length(human->getPosition() - this->position);
			if (min_distance > distance) {
				min_distance = distance;
				closest_human = human;
			}
		} 
		this->direction = glm::normalize(closest_human->getPosition() - this->position);
		this->position += this->direction * this->speed;
		if (collideWithLevel(levelData)) {
			this->direction = glm::rotate(this->direction, 90.0f);
			this->position += this->direction * this->speed;
		}
	}
}
