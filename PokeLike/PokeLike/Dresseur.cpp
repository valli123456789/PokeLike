#include "Dresseur.h"

Dresseur::Dresseur()
{
	d_texture_down.loadFromFile("Sprite/sacha1.png", sf::IntRect(0, 0, 34, 54));
	d_texture_up.loadFromFile("Sprite/sacha1.png", sf::IntRect(116, 0, 34, 54));
	d_texture_left.loadFromFile("Sprite/sacha1.png", sf::IntRect(77, 0, 34, 54));
	d_texture_right.loadFromFile("Sprite/sacha1.png", sf::IntRect(35, 0, 34, 54));
	d_sprite.setTexture(d_texture_down);
	d_sprite.setPosition(600, 600);
}


Dresseur::~Dresseur()
{
}

void Dresseur::update(std::vector<bool> collision)//Définition de la fonction update (qui est maintenant une fonction  membre de la classe "Dresseur")
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) // Vérifie si la flèche "Down" du clavier est appuyé
	{
		d_sprite.setTexture(d_texture_down);
		if (!collision[3])
		d_sprite.move(0, 2);// Dans le cas ou la condition du "if" est vérifiée La fonction "move" déplace le sprite selon le vecteur (x,y) sachant que l'axe -y est dirigé vers le bas et l'axe -x vers la droite
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		d_sprite.setTexture(d_texture_left);
		if (!collision[0])
		d_sprite.move(-2, 0);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		d_sprite.setTexture(d_texture_right);
		if (!collision[1])
		d_sprite.move(2, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		d_sprite.setTexture(d_texture_up);
		if (!collision[2])
		d_sprite.move(0, -2);
	}

}