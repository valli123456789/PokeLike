#include "Dresseur.h"
#include <cstdlib>
//#include "Pokemon.cpp"


//main

int main()
{
	sf::RenderWindow maFenetre(sf::VideoMode(1200, 1200), "Une fenetre avec SFML");
	maFenetre.setFramerateLimit(60);// nombre de frames par seconde

									//instantiation d'un objet qui appartient à la classe Warrior
									/////////ici
	Dresseur dres;

	// setup de la carte
	sf::Sprite background_sprite;
	sf::Texture background;
	background.loadFromFile("Sprite/background2.png", sf::IntRect(0, 0, 1200, 1200));
	background_sprite.setTexture(background);
	// gestions des hautes herbes
	sf::FloatRect hauteHerbes1(160, 80, 280, 360);
	sf::FloatRect hauteHerbes2(360, 640, 160, 200);
	sf::FloatRect hauteHerbes3(680, 760, 360, 240);
	sf::FloatRect hauteHerbes4(880, 1000, 160, 80);
	sf::FloatRect hauteHerbes5(560, 1080, 480, 40);
	// gestion des collisions
	sf::FloatRect mur1(0, 0, 80, 1200);

	// setup de la zone de combat
	sf::Sprite backcombat_sprite;
	sf::Texture backcombat;
	backcombat.loadFromFile("Sprite/arene.png", sf::IntRect(0, 0, 1200, 1200));
	backcombat_sprite.setTexture(backcombat);

	while (maFenetre.isOpen()) // première boucle
	{
		bool endmap = 1;
		bool endcombat = 0;
		maFenetre.clear();
		
		while (endmap) { // boucle liée à la map

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) break;

			// appel de la fonction membre "update" pour faire bouger l'objet
			/////ici
			if(dres.d_sprite.getGlobalBounds().intersects(mur1))
			    dres.update(0);
			else
				dres.update(1);

			//adapter la fonction draw
			////ici
			maFenetre.draw(background_sprite); //pour la map
			maFenetre.draw(dres.d_sprite); //pour le dresseur

			if (dres.d_sprite.getGlobalBounds().intersects(hauteHerbes1) || dres.d_sprite.getGlobalBounds().intersects(hauteHerbes2) || dres.d_sprite.getGlobalBounds().intersects(hauteHerbes3) || dres.d_sprite.getGlobalBounds().intersects(hauteHerbes4) || dres.d_sprite.getGlobalBounds().intersects(hauteHerbes5))
			{
				int x = rand() % 100;
				if (x == 8) {
					endmap = 0;
					endcombat = 1;
				}
			}


			maFenetre.display();
		} // fin boucle map

		while (endcombat) { // boucle lié à un combat
			maFenetre.clear();

			maFenetre.draw(backcombat_sprite); //pour l'arene

			maFenetre.display();
		}


	}
	

	// appel du destructeur
	/////ici
	dres.~Dresseur();
	return 0;
}