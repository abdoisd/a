// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;

int main()
{
	// Déclaration d'un tableau de 5 entiers
	int nums[5];
	// Initialisation du tableau avec des valeurs
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	nums[3] = 4;
	nums[4] = 5;
	// Affichage des valeurs du tableau
	for (int i = 0; i < 5; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	// Déclaration et initialisation d'un tableau de 5 entiers en une seule ligne
	// int nums[5] = { 1, 2, 3, 4, 5 };
	int* p = nums; // Pointeur vers le premier élément du tableau
	// Affichage des valeurs du tableau en utilisant le pointeur	
	for (int i = 0; i < 5; i++)
	{
		cout << *(p + i) << " "; // Accès aux éléments du tableau via le pointeur
	}
	return 0;
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
