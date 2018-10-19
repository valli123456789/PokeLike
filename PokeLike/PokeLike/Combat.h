#pragma once
#include"Pokemon.h"
#include"Pokemonstock.h"
#include"Pokemoncombat.h"
#include"Attaque.h"
#include"Dresseur.h"

template <class a> void deroulementattaque(a lattaquant, a quisubit, int atqselect, float matricecoef[17][17])//c'est une seule partie : une phase d'attaque, à dupliquer pour contre attaque
{
	if ((lattaquant.ps_getattaque(atqselect)).a_getstatut() == 1)//que dégats
	{
		quisubit.pc_getdegats(lattaquant.ps_getattaque(atqselect), matricecoef, lattaquant);//créer la méthode dans pkmn getdegats, celle devra contenir la table de correspondance
	}
	
}


