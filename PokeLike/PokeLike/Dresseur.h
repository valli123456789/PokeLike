#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
class Dresseur
{
public:
	Dresseur();
	~Dresseur();
	void update(std::vector<bool>); //une fonction membre
	sf::Sprite d_sprite;

private:
	sf::Texture d_texture_down;
	sf::Texture d_texture_up;
	sf::Texture d_texture_left;
	sf::Texture d_texture_right;
};
