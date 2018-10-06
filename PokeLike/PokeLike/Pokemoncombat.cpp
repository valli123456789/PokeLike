#include "Pokemoncombat.h"
Pokemoncombat :: Pokemoncombat(Pokemon acopier)
{
	
}
Pokemoncombat::Pokemoncombat(Pokemonstock acopier)
{

}
Pokemoncombat:: ~Pokemoncombat()
{
	Pokemon::~Pokemon();	
}
int Pokemoncombat::pc_getatkcombat()
{
	return pc_atkcombat;
}
int Pokemoncombat::pc_getatkspecombat()
{
	return pc_atkspecombat;
}
int Pokemoncombat::pc_getdefcombat()
{
	return pc_defcombat;
}
int Pokemoncombat::pc_getdefspecombat()
{
	return pc_defspecombat;
}
int Pokemoncombat::pc_getvitcombat()
{
	return pc_vitcombat;
}
void Pokemoncombat::pc_getdegats(Attaque lattaque, int *matricecoef[], Pokemoncombat attaquant)
{
	int coef;
	coef = matricecoef[(*this).p_getnombretype()][lattaque.a_getnombretype()];
	int pvperdu;
	if (lattaque.a_getstataffecteeoff() == "atk")//atk phys
	{
		pvperdu = (attaquant.pc_getatkcombat()* lattaque.a_getpuissanceoff() / ((*this).pc_getdefcombat()));
	}
	else//atk spe
	{
		pvperdu = (attaquant.pc_getatkspecombat() * lattaque.a_getpuissanceoff() / ((*this).pc_getdefspecombat()));
	}
	ps_pvrestant -= pvperdu;
	if (ps_pvrestant < 0)
	{
		ps_pvrestant = 0;//pas de pv sous 0
	}
	//std::cout<<"pv restant :"<<ps_pvrestant<<std::endl;
}
void Pokemoncombat::pc_setup(Attaque lattaque)//multiplier la stat affecté par le boost par le coef
{
	if (lattaque.a_getstataffecteeset() == "atk")
	{
		pc_atkspecombat *= lattaque.a_getpuissanceset();
	}
	if (lattaque.a_getstataffecteeset() == "atkspe")
	{
		pc_atkspecombat *= lattaque.a_getpuissanceset();
	}
}