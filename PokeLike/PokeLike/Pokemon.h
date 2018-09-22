#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Attaque.h"

class Pokemon
{
public:
	Pokemon();
	~Pokemon();
	sf::Sprite p_sprite;
	sf::String p_getnom();
	sf::String p_gettype();
	int p_getpv();
	int p_getatk();
	int p_getatkspe();
	int p_getdef();
	int p_getdefspe();
	int p_getvit();
	int p_getrare();
	int p_getevdonne();
	std::string p_gettypeev();

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
	int p_evdonne;
	std::string p_typeev;
	Attaque p_listeatq[4];
};
