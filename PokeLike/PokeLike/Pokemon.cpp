#include "Pokemon.h"



Pokemon::Pokemon()
{
}


Pokemon::~Pokemon()
{
}

sf::String Pokemon::p_getnom()
{
	return p_nom;
}
sf::String Pokemon::p_gettype()
{
	return p_type;
}
int Pokemon::p_getpv()
{
	return p_pv;
}
int Pokemon::p_getatk()
{
	return p_atk;
}
int Pokemon::p_getatkspe()
{
	return p_atkspe;
}
int Pokemon::p_getdef()
{
	return p_def;
}
int Pokemon::p_getdefspe()
{
	return p_defspe;
}
int Pokemon::p_getvit()
{
	return p_vit;
}
int Pokemon::p_getrare()
{
	return p_rare;
}
int Pokemon::p_getevdonne()
{
	return p_evdonne;
}
std::string Pokemon::p_gettypeev()
{
	return p_typeev;
}
