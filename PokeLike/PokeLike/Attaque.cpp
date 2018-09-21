#include "Attaque.h"
Attaque::Attaque()
{
  //initialiser les variables en allant cherchez les valeurs dans la database
  //on pourrait créer une autre méthode pour des tests unitaire si on a pas la base de données sous la main pour tester le bon fonctionnement
}
Attaque::~Attaque()
{
}

string Attaque :: a_getnom()
{
return a_nom; 
}
string Attaque :: a_gettype()
{
return a_type; 
}
int Attaque :: a_getpuissance()
{
return a_puissance;
}
string Attaque :: a_getstataffectee()
{
return stataffectée;
}
