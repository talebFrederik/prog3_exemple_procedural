/**
 * Simulation d'un combat entre 1 joueur et un ennemi aléatoire parmi 5
 *
 * @file exemple_procedural.cpp
 *
 * @brief This message displayed in Doxygen Files index
 *
 * @author Frédérik Taleb
 * Contact: taleb.frederik@carrefour.cegepvicto.ca
 *
 */

#include <iostream>
#include <string>
#include <random>

int main()
{
	// Propriétés du joueur
	int joueurHp(50);
	std::string joueurArmeNom("épée");
	int joueurArmeDommage(10);

	// Propriétés des ennemis
	std::string ennemisNoms[5]{ "minautor", "gobelin", "voleur", "mercenaire", "magicien" };
	int ennemisHp[5]{ 35,30,25,50,20 };
	int ennemisDmg[5]{ 8,4,12,6,16 };

	// Propriétés de la partie
	bool partieTerminee(false);
	char strategie('o');
	int toucheJoueur{};
	int toucheEnnemi{};

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

	// La boucle de jeux demande si le joueur veux être offensif ou défensif
	// La résolution de combat commence par le joueur puis l'ennemi
	// Les résultats sont affichés au fur et à mesure
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
			// Si le joueur touche, on affiche le lancé et on fait les dommage à l'ennemi
			// Sinon on affiche l'échec du coup
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
			
			// Si l'ennemi touche, on affiche les dommages reçus
			// Sinon on affiche l'échec du coup de l'ennemi
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

		// défensif :	tous les dommages -1, les combatants touchent avec 60% ou plus
		if (strategie == 'd')
		{
			// Si le joueur touche, on affiche le lancé et on fait les dommage à l'ennemi
			// Sinon on affiche l'échec du coup
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

			// Si l'ennemi touche, on affiche les dommages reçus
			// Sinon on affiche l'échec du coup de l'ennemi
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
