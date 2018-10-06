#include "Dresseur.h"
#include <cstdlib>
#include "Fonctions.h"
#include "Pokemon.h"
//#include "Pokemon.cpp"

//main

int main()
{
	sf::RenderWindow maFenetre(sf::VideoMode(1200, 1200), "Une fenetre avec SFML");
	maFenetre.setFramerateLimit(60);// nombre de frames par seconde

									//instantiation d'un objet qui appartient à la classe Warrior
									/////////ici
	Dresseur dres;
	int pas = 0;

	// setup de la carte
	sf::Sprite background_sprite;
	sf::Texture background;
	background.loadFromFile("Sprite/background2.png", sf::IntRect(0, 0, 1200, 1200));
	background_sprite.setTexture(background);
	// gestions des hautes herbes
	sf::FloatRect hauteHerbes1(160, 80, 280, 360); //hh en haut à gauche
	sf::FloatRect hauteHerbes2(360, 640, 160, 200); //hh au milieu
	sf::FloatRect hauteHerbes3(680, 760, 360, 240); //hh en bas à droite
	sf::FloatRect hauteHerbes4(880, 1000, 160, 80);
	sf::FloatRect hauteHerbes5(560, 1080, 480, 40);
	// gestion des collisions
	sf::FloatRect mur1(0, 0, 80, 1200); // ligne d'arbres à gauche
	sf::FloatRect mur2(80, 0, 80, 376); // arbres à gauche des hh en haut
	sf::FloatRect mur3(80, 560, 200, 360); // partie haute du lac bas
	sf::FloatRect mur4(280, 560, 80, 216); // 3 arbres à droite du lac bas
	sf::FloatRect mur5(260, 920, 220, 80); // partie basse du lac bas
	sf::FloatRect mur6(480, 960, 80, 160); // 2 arbes en bas à droite du lac bas
	sf::FloatRect mur7(560, 1120, 640, 80); // ligne d'arbres en bas des hh à droite
	sf::FloatRect mur8(1040, 800, 160, 400); // ligne d'arbres à droite des hh
	sf::FloatRect mur9(1120, 0, 80, 1200); // ligne d'arbres à droites
	sf::FloatRect mur10(760, 330, 280, 6); // lac haut
	sf::FloatRect mur11(1040, 0, 80, 420); // arbres à droite du lac haut
	sf::FloatRect mur12(720, 300, 40, 76); // aie à droite de l'arène 
	sf::FloatRect mur13(440, 0, 40, 376); // aie à gauche de l'arène
	sf::FloatRect mur14(0, 0, 440, 56); // arbres en haut des hh haut
	sf::FloatRect arena(480, 0, 240, 316); // arène
	sf::FloatRect hopital(760, 600, 160, 56); // pokestop
	sf::FloatRect shop(960, 440, 160, 56); // pokeshop
	//setup batiments
	sf::Sprite pokestop_sprite;
	sf::Texture pokestop;
	pokestop.loadFromFile("Sprite/pokestop.png", sf::IntRect(0, 0, 162, 154));
	pokestop_sprite.setTexture(pokestop);
	pokestop_sprite.setPosition(759, 521);
	sf::Sprite pokeshop_sprite;
	sf::Texture pokeshop;
	pokeshop.loadFromFile("Sprite/pokeshop.png", sf::IntRect(0, 0, 176, 145));
	pokeshop_sprite.setTexture(pokeshop);
	pokeshop_sprite.setPosition(945, 372);



	// setup de la zone de combat
	sf::Sprite backcombat_sprite;
	sf::Texture backcombat;
	backcombat.loadFromFile("Sprite/arene.png", sf::IntRect(0, 0, 1200, 1200));
	backcombat_sprite.setTexture(backcombat);

	// setup d'une pokeball
	sf::Sprite pokeball_sprite;
	sf::Texture pokeball;
	pokeball.loadFromFile("Sprite/all_pokeballs.png", sf::IntRect(168, 4, 19, 32));
	pokeball_sprite.setTexture(pokeball);
	int anim_poke = 0;

	while (maFenetre.isOpen()) // première boucle
	{
		bool endmap = 1;
		bool endcombat = 0;
		bool capture = 0;
		maFenetre.clear();

		while (endmap) { // boucle liée à la map

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) break;
			std::vector<bool> detectcoll;
			// appel de la fonction membre "update" pour faire bouger l'objet
			/////ici

			for (int i = 0; i < 4; i++) { // on regarde dans chaques directions
				if (Collision(dres.d_sprite.getGlobalBounds(), mur1)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur2)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur3)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur4)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur5)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur6)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur7)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur8)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur9)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur10)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur11)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur12)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur13)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), mur14)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), arena)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), hopital)[i]
					|| Collision(dres.d_sprite.getGlobalBounds(), shop)[i]
					)
					detectcoll.push_back(1);
				else
					detectcoll.push_back(0);
			}

			// on actualise
			dres.update(detectcoll, pas);

			//adapter la fonction draw
			////ici
			maFenetre.draw(background_sprite); //pour la map
			maFenetre.draw(dres.d_sprite); //pour le dresseur
			maFenetre.draw(pokestop_sprite); //pour la supperposition
			maFenetre.draw(pokeshop_sprite);


			if ((dres.d_sprite.getGlobalBounds().intersects(hauteHerbes1)
				|| dres.d_sprite.getGlobalBounds().intersects(hauteHerbes2)
				|| dres.d_sprite.getGlobalBounds().intersects(hauteHerbes3)
				|| dres.d_sprite.getGlobalBounds().intersects(hauteHerbes4)
				|| dres.d_sprite.getGlobalBounds().intersects(hauteHerbes5))
				& (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)
					|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)
					|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)
					|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)))
			{
				int x = rand() % 100;
				if (x == 8) {
					endmap = 0;
					endcombat = 1;
				}
			}
			pas++;
			if (pas == 20)
				pas = 0;

			std::cout << "0";
			maFenetre.display();
		} // fin boucle map

		if (endcombat) 
		{
			//boucle pierre, faudra qu'on combine le tout
			/*
			// mon poke
			std::string nom = "Pikachu";
			int tab[4] = { 0,0, 131, 138 };
			Pokemon mon_pokemon;//(nom, tab);
			mon_pokemon.p_sprite.setPosition(326, 409);

			// poke sauvage
			std::string nom2 = "Goten";
			int tab2[4] = { 0,0, 109, 142 };
			Pokemon pokemon_sauvage;// (nom2, tab2);
			pokemon_sauvage.p_sprite.setPosition(763, 390);

			// interface combat selection
			sf::Sprite combat_selection_sprite;
			sf::Texture combat_selection;
			combat_selection.loadFromFile("Sprite/combat_selection.png", sf::IntRect(0, 0, 600, 242));
			combat_selection_sprite.setTexture(combat_selection);
			combat_selection_sprite.setPosition(600, 958);

			// flèche de sélection
			float xa, ya;
			sf::Sprite arrow_sprite;
			sf::Texture arrow;
			arrow.loadFromFile("Sprite/arrow.png", sf::IntRect(0, 0, 17, 66));
			arrow_sprite.setTexture(arrow);
			std::vector<bool> arrow_tab = { 0,0 };

			while (endcombat) { // boucle lié à un combat
				maFenetre.display();

				maFenetre.draw(backcombat_sprite); //pour l'arene
				maFenetre.draw(pokemon_sauvage.p_sprite);
				maFenetre.draw(mon_pokemon.p_sprite);
				maFenetre.draw(combat_selection_sprite);

				// on regarde la sélection
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
					arrow_tab[0] = 1;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
					arrow_tab[0] = 0;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
					arrow_tab[1] = 1;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
					arrow_tab[1] = 0;
				}

				// on dessine la flèche de sélection au bon endroit

				if (arrow_tab[0])
					xa = 1107;
				else
					xa = 986;
				if (arrow_tab[1])
					ya = 912;
				else
					ya = 610;
				arrow_sprite.setPosition(ya, xa);
				maFenetre.draw(arrow_sprite);


				// si on appuie sur enter

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
					if (arrow_tab[0] && arrow_tab[1]) // si on est sur fuite
						endcombat = 0;

					if (arrow_tab[0] && !arrow_tab[1]) // si on est sur capturer
						capture = 1;

					if (!arrow_tab[0] && !arrow_tab[1]) // si on est sur attaquer
					{
					}

					if (!arrow_tab[0] && arrow_tab[1]) // si on est sur équipe
					{
					}
				}
				if (capture) {
					if (anim_poke <= 71) {
						pokeball_sprite.setPosition(800, 238 + 4 * anim_poke);
						maFenetre.draw(pokeball_sprite);
						anim_poke++;
					}
					else if (anim_poke <= 77) {
						pokeball_sprite.setPosition(800, 238 + 288 - 3 * (anim_poke - 72));
						maFenetre.draw(pokeball_sprite);
						anim_poke++;
					}
					else if (anim_poke <= 83) {
						pokeball_sprite.setPosition(800, 238 + 511 - 2 * (anim_poke - 77));
						maFenetre.draw(pokeball_sprite);
						anim_poke++;
					}
					else if (anim_poke <= 90) {
						pokeball_sprite.setPosition(800, 238 + 499 - 1 * (anim_poke - 83));
						maFenetre.draw(pokeball_sprite);
						anim_poke++;
					}
				}
				std::cout << "1";
			}*/
		}
	}

	// appel du destructeur
	/////ici
	dres.~Dresseur();
	return 0;
}