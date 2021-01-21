// exemple_procedural.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <random>

int main()
{
	// Propri�t�s du joueur
	int joueurHp(100);
	std::string joueurArmeNom("�p�e");
	int joueurArmeDommage(5);

	// Propri�t�s des ennemis
	std::string ennemisNoms[5]{ "orc", "goblin", "assassin", "mercenaire", "magicien" };
	int ennemisHp[5]{ 70,60,50,100,40 };
	int ennemisDmg[5]{ 2,1,3,1,4 };

	// Propri�t�s de la partie
	bool partieTerminee(false);

	// G�n�ration d'un nombre al�atoire
	std::random_device rd;
	std::mt19937 rng(rd());
	// dist1 sert � normaliser le nombre g�n�r� entre 1 et 100
	std::uniform_int_distribution<> dist1(1, 100);
	// dist2 sert � normaliser le nombre g�n�r� entre 0 et 4 pour choisir un ennemi al�atoirement
	std::uniform_int_distribution<> dist2(0, 4);

	// Choisir un ennemi � affronter au hasard
	int ennemi(dist2(rng));
	std::cout << "Vous affrontez un " << ennemisNoms[ennemi] << "! \n";

	//for (int i = 0; i < 10; ++i)
	//{
	//	std::cout << dist1(rng) << '\n';
	//}
}
