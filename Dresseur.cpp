#include "Dresseur.h"

Dresseur::Dresseur()
{
	d_texture.loadFromFile("Sprite/golbez.png", sf::IntRect(0, 0, 32, 48));
	d_sprite.setTexture(d_texture);
	d_sprite.setPosition(600, 600);
}


Dresseur::~Dresseur()
{
}

void Dresseur::update(bool t)//Définition de la fonction update (qui est maintenant une fonction  membre de la classe "Dresseur")
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) // Vérifie si la flèche "Down" du clavier est appuyé
	{
		if (t)
			d_sprite.move(0, 2);// Dans le cas ou la condition du "if" est vérifiée La fonction "move" déplace le sprite selon le vecteur (x,y) sachant que l'axe -y est dirigé vers le bas et l'axe -x vers la droite
		else
			d_sprite.move(0, -4);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (t)
			d_sprite.move(-2, 0);
		else
			d_sprite.move(4, 0);

	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (t)
			d_sprite.move(2, 0);
		else
			d_sprite.move(4, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (t)
			d_sprite.move(0, -2);
		else
			d_sprite.move(0, 4);
	}

}