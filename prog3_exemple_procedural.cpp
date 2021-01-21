// exemple_procedural.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <random>

int main()
{
	// Propriétés du joueur
	int joueurHp(100);
	std::string joueurArmeNom("épée");
	int joueurArmeDommage(5);

	// Propriétés des ennemis
	std::string ennemisNoms[5]{ "orc", "goblin", "assassin", "mercenaire", "magicien" };
	int ennemisHp[5]{ 70,60,50,100,40 };
	int ennemisDmg[5]{ 2,1,3,1,4 };

	// Propriétés de la partie
	bool partieTerminee(false);

	// Génération d'un nombre aléatoire
	std::random_device rd;
	std::mt19937 rng(rd());
	// dist1 sert à normaliser le nombre généré entre 1 et 100
	std::uniform_int_distribution<> dist1(1, 100);
	// dist2 sert à normaliser le nombre généré entre 0 et 4 pour choisir un ennemi aléatoirement
	std::uniform_int_distribution<> dist2(0, 4);

	// Choisir un ennemi à affronter au hasard
	int ennemi(dist2(rng));
	std::cout << "Vous affrontez un " << ennemisNoms[ennemi] << "! \n";

	//for (int i = 0; i < 10; ++i)
	//{
	//	std::cout << dist1(rng) << '\n';
	//}
}
