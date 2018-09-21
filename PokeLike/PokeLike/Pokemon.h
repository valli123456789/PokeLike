#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Pokemon
{
public:
	Pokemon();
	~Pokemon();
	sf::Sprite p_sprite;

private:
	sf::Texture p_texture;
	int p_ID;
	sf::String p_nom;
	sf::String p_type;
	int p_pv;
	int p_atk;
	int p_atkspe;
	int p_def;
	int p_defspe;
	int p_vit;
	int p_rare;
};
