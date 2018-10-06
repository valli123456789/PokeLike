#include "Attaque.h"
Attaque::Attaque()
{
  //initialiser les variables en allant cherchez les valeurs dans la database
  //on pourrait créer une autre méthode pour des tests unitaire si on a pas la base de données sous la main pour tester le bon fonctionnement
}
Attaque::~Attaque()
{
}

std::string Attaque :: a_getnom()
{
return a_nom; 
}
std::string Attaque :: a_gettype()
{
return a_type; 
}
int Attaque :: a_getpuissanceoff()
{
return a_puissanceoff;
}
int Attaque :: a_getpuissanceset()
{
	return a_puissanceset;
}
std::string Attaque :: a_getstataffecteeoff()
{
return a_stataffecteeoff;
}
std::string Attaque::a_getstataffecteeset()
{
	return a_stataffecteeset;
}
float Attaque :: a_getprecision()
{
return a_precision;
}
int Attaque::a_getnombretype()
{
	//de la db : avoir le nom, puis fiare des tests pour avoir le chiffre, à mettre dans le créateur
	return a_nombretype;
}
int Attaque::a_getstatut()
{
	return a_statut;
}
