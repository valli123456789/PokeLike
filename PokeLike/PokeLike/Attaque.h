#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
class Attaque {

public:
	Attaque();
	~Attaque();
	std::string a_getnom();
	std::string a_gettype();
	int a_getpuissance();
	std::string a_getstataffectee();
	float a_getprecision();


private:
	int a_id;
	std::string a_nom;
	std::string a_type;
	int a_puissance;
	std::string a_stataffectee;//def(spe), atk(spe), vit, precis, crit????
	float a_precision;
	//pourquoi ne pas créer une variable booléen par type d'attaque au lieu du typecode, niveau mémoire c'est un peu mieux qu'un gros int
//genre un truc ainsi, qui serait stocké dans la database, au lieu du typecode,  des interrupteurs différents???
	/*bool a_normalok;
	bool a_fireok;
	bool a_fightingok;
	bool a_waterok;
	bool a_flyingok;
	bool a_grassok;
	bool a_poison;
	bool a_electric;
	bool a_ground;
	bool a_psychic;
	bool a_rock;
	bool a_ice;
	bool a_bug;
	bool a_dragon;
	bool a_ghost;
	bool a_dark;
	bool asteel;
	bool a_fairy;*/

};

