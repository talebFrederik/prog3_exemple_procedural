/**
 * Simulation d'un combat entre 1 joueur et un ennemi al�atoire parmi 5
 *
 * @file exemple_procedural.cpp
 *
 * @brief This message displayed in Doxygen Files index
 *
 * @author Fr�d�rik Taleb
 * Contact: taleb.frederik@carrefour.cegepvicto.ca
 *
 */

#include <iostream>
#include <string>
#include <random>

int main()
{
	// Propri�t�s du joueur
	int joueurHp(50);
	std::string joueurArmeNom("�p�e");
	int joueurArmeDommage(10);

	// Propri�t�s des ennemis
	std::string ennemisNoms[5]{ "minautor", "gobelin", "voleur", "mercenaire", "magicien" };
	int ennemisHp[5]{ 35,30,25,50,20 };
	int ennemisDmg[5]{ 8,4,12,6,16 };

	// Propri�t�s de la partie
	bool partieTerminee(false);
	char strategie('o');
	int toucheJoueur{};
	int toucheEnnemi{};

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

	// La boucle de jeux demande si le joueur veux �tre offensif ou d�fensif
	// La r�solution de combat commence par le joueur puis l'ennemi
	// Les r�sultats sont affich�s au fur et � mesure
	// Si le joueur ou l'ennemi n'ont plus de point de vie, on sort de la boucle
	while (!partieTerminee)
	{
		std::cout << "\#\n";
		std::cout << "\#\n";
		std::cout << "Choisir votre strategie pour le tour \n" << "Offensif ecrire o \n" << "Defensif ecrire d \n";
		std::cin >> strategie;
		std::cout << "\#\n";
		std::system("CLS");

		toucheEnnemi = dist1(rng);
		toucheJoueur = dist1(rng);

		// offensif :	tous les dommages + 1, les combatants touchent avec 40% ou plus
		if (strategie == 'o')
		{
			// Si le joueur touche, on affiche le lanc� et on fait les dommage � l'ennemi
			// Sinon on affiche l'�chec du coup
			// Puis on affiche les points de vie restants de l'ennemi
			if (toucheEnnemi >= 40)
			{
				std::cout << "Vous avez touche l'ennemi avec un lance de " << toucheEnnemi << "\n";
				ennemisHp[ennemi] -= joueurArmeDommage + 1;
			}
			else
			{
				std::cout << "Vous avez rate le " << ennemisNoms[ennemi] << "\n";
			}
			std::cout << "Il reste " << ennemisHp[ennemi] << " points de vie au " << ennemisNoms[ennemi] << "\n\n";
			
			// Si l'ennemi touche, on affiche les dommages re�us
			// Sinon on affiche l'�chec du coup de l'ennemi
			// Puis on affiche les points de vie restants du joueur
			if (toucheJoueur >= 40)
			{
				std::cout << "Le " << ennemisNoms[ennemi] << " vous a fait " << ennemisDmg[ennemi] + 1 << " degats.\n";
				joueurHp -= ennemisDmg[ennemi] + 1;
			}
			else
			{
				std::cout << "Le " << ennemisNoms[ennemi] << " vous a rate! \n";
			}
			std::cout << "Il vous reste " << joueurHp << " points de vie. \n\n";
		}

		// d�fensif :	tous les dommages -1, les combatants touchent avec 60% ou plus
		if (strategie == 'd')
		{
			// Si le joueur touche, on affiche le lanc� et on fait les dommage � l'ennemi
			// Sinon on affiche l'�chec du coup
			// Puis on affiche les points de vie restants de l'ennemi
			if (toucheEnnemi >= 60)
			{
				std::cout << "Vous avez touche l'ennemi avec un lance de " << toucheEnnemi << "\n";
				ennemisHp[ennemi] -= joueurArmeDommage - 1;
			}
			else
			{
				std::cout << "Vous avez rate le " << ennemisNoms[ennemi] << "\n";
			}
			std::cout << "Il reste " << ennemisHp[ennemi] << " points de vie au " << ennemisNoms[ennemi] << "\n\n";

			// Si l'ennemi touche, on affiche les dommages re�us
			// Sinon on affiche l'�chec du coup de l'ennemi
			// Puis on affiche les points de vie restants du joueur
			if (toucheJoueur >= 60)
			{
				std::cout << "Le " << ennemisNoms[ennemi] << " vous a fait " << ennemisDmg[ennemi] - 1 << " degats.\n";
				joueurHp -= ennemisDmg[ennemi] - 1;
			}
			else
			{
				std::cout << "Le " << ennemisNoms[ennemi] << " vous a rate! \n";
			}
			std::cout << "Il vous reste " << joueurHp << " points de vie. \n\n";
		}

		if (joueurHp <= 0 || ennemisHp[ennemi] <= 0)
		{
			partieTerminee = true;
		}

		std::cout << "\#\n";
	}

	// Afficher le message de fin de partie
	std::cout << ennemisNoms[ennemi] << ": " << ennemisHp[ennemi] << " points de vie. \n";
	std::cout << "Joueur: " << joueurHp << " points de vie. \n";
	std::cout << "Partie terminee!";
}
