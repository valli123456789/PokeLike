#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
class Dresseur
{
public:
	Dresseur();
	~Dresseur();
	void update(bool); //une fonction membre
	sf::Sprite d_sprite;

private:
	sf::Texture d_texture;
};
