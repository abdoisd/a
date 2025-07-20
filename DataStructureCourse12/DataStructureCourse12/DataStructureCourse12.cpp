// DataStructureCourse12.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;
#include <stack>
#include <queue>
class Node
{
public:
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};
void printList(Node* head) {
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
void reverseList(Node*& head) {
	Node* prev = nullptr;
	Node* current = head;
	Node* next = nullptr;
	while (current != nullptr) {
		next = current->next; // Store next node
		current->next = prev; // Reverse the link
		prev = current;       // Move prev to current
		current = next;       // Move to next node
	}
	head = prev; // Update head to new first node
}
void InsertAtBeginning(Node*& head, int val) {
	Node* newNode = new Node(val);
	newNode->next = head;
	head = newNode;
}
void InsertAtEnd(Node*& head, int val) {
	Node* newNode = new Node(val);
	if (head == nullptr) {
		head = newNode;
		return;
	}
	Node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = newNode;
}
void InsertAfter(Node* prevNode, int val) {
	if (prevNode == nullptr) {
		cout << "The given previous node cannot be NULL." << endl;
		return;
	}
	Node* newNode = new Node(val);
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}
void DeleteNode(Node*& head, int key) {
	Node* current = head;
	Node* prev = nullptr;
	// If the head node itself holds the key to be deleted
	if (current != nullptr && current->data == key) {
		head = current->next; // Changed head
		delete current;       // Free old head
		return;
	}
	// Search for the key to be deleted, keep track of the previous node
	while (current != nullptr && current->data != key) {
		prev = current;
		current = current->next;
	}
	// If key was not present in linked list
	if (current == nullptr) return;
	// Unlink the node from linked list
	prev->next = current->next;
	delete current; // Free memory
}
int main()
{
	
	Node* head = new Node(1);
	Node* second = new Node(2);
	Node* third = new Node(3);
	
	head->next = second;
	second->next = third;
	printList(head);
	reverseList(head);
	printList(head);
	InsertAtBeginning(head, 0); // Insert 0 at the beginning
	printList(head); // Print the list after insertion
	InsertAtEnd(head, 4); // Insert 4 at the end
	printList(head); // Print the list after insertion
	InsertAfter(head->next, 5); // Insert 5 after the second node
	printList(head); // Print the list after insertion
	InsertAfter(head->next->next->next, 9); // Insert 5 after the second node
	printList(head); // Print the list after insertion
	DeleteNode(head, 2); // Delete the node with value 2
	printList(head); // Print the list after deletion


	
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
