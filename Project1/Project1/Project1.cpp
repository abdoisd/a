// Project1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;
struct stAdress { string city; };
struct stContactInfo { string tel;stAdress Adress; };
enum enGender { mall, femelle };
enum enStatusmarital { singel, married };
struct stPerson { string Name; stContactInfo contactimfo; enGender gender;enStatusmarital statusmarrital; };
int main()
{
	

	stPerson Person1;
	Person1.Name = "salah";
	Person1.contactimfo.Adress.city = "Casa";
	Person1.contactimfo.tel = "060212152";
	Person1.gender == enGender::mall;
	Person1.statusmarrital == enStatusmarital::married;

	cout << Person1.statusmarrital << endl;
	return 0;
}

// Exécuter le programme : Ctrl+F5 ou men
// 
// 
// u Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
