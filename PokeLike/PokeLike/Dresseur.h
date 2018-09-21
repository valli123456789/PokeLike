#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef DRESSEUR_H_INCLUDED//vu qu'un soucis se présentait (permutation circulaire préprocesseur du à la création attive des fichiers de la classe CCC sans avoir eu fini avec la classe animal d'abord, mettre ceci, pas oublier endif
#define DRESSEUR_H_INCLUDED

class Dresseur
{
public:
	Dresseur();
	~Dresseur();
	void update(); //une fonction membre
	sf::Sprite d_sprite;

private:
	sf::Texture d_texture;
};

#endif