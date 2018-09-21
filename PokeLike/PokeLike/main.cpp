#include "Dresseur.cpp"
//#include "Pokemon.cpp"

//include ici

using namespace sf;

//main

int main()
{
	RenderWindow maFenetre(VideoMode(500, 500), "Une fenetre avec SFML");
	maFenetre.setFramerateLimit(60);// nombre de frames par seconde

									//instantiation d'un objet qui appartient à la classe Warrior
									/////////ici
	Dresseur objet;

	while (true)
	{
		maFenetre.clear(Color(181, 230, 24));

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;

		// appel de la fonction membre "update" pour faire bouger l'objet
		/////ici
		objet.update();

		//adapter la fonction draw
		////ici

		maFenetre.draw(objet.d_sprite);
		maFenetre.display();

	}

	// appel du destructeur
	/////ici
	objet.~Dresseur();
	return 0;
}