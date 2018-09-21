#include "Dresseur.h"

Dresseur::Dresseur()
{
	d_texture.loadFromFile("Sprite/sacha.png", sf::IntRect(0, 0, 32, 48));
	d_sprite.setTexture(d_texture);
}


Dresseur::~Dresseur()
{
}

void Dresseur::update()//Définition de la fonction update (qui est maintenant une fonction  membre de la classe "Dresseur")
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) // Vérifie si la flèche "Down" du clavier est appuyé
	{
		d_sprite.move(0, 2);// Dans le cas ou la condition du "if" est vérifiée La fonction "move" déplace le sprite selon le vecteur (x,y) sachant que l'axe -y est dirigé vers le bas et l'axe -x vers la droite
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		d_sprite.move(-2, 0);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		d_sprite.move(2, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		d_sprite.move(0, -2);
	}

}