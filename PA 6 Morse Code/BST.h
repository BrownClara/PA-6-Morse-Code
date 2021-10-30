/*   Title: PA 6 Morse Code
*    Author: Clara Brown
*    Date Created: 10/25/21
*    Last Modified:
*
*    Description: Uses a BST to look up Morse Code characters.
*/
#pragma once
#include "BSTNode.hpp"

template <class S, class C>
class BST
{
public:
	// Constructor
	BST();
	// Destructor
	~BST();

	void insert(BSTNode<S,C>* newNode);
	void print();
	bool isEmpty();
	void search(const C& character);
	void convert();


private:
	BSTNode<S,C>* mpRoot;
	void insert(BSTNode<S, C>* pTree, BSTNode<S, C>* newNode);
	void print(BSTNode<S, C>* pTree);
	void destroyTree(BSTNode<S, C>* pTree);
	fstream MorseTableFile; 
	void search(BSTNode<S, C>* pTree, const C& character);

};

// Constructor
template <class S, class C>
BST<S, C>::BST()
{
	C character = '\0';
	S discard_temp = "";
	S morseString = "";
	this->mpRoot = nullptr;
	// open and read the file
	MorseTableFile.open("MorseTable.txt", std::ios::in);
	if (MorseTableFile.is_open())
	{
		while (MorseTableFile.eof() != true)
		{
			// read in the data
			//MorseTableFile.getline(character, 250);

			MorseTableFile >> character;
			getline(MorseTableFile, discard_temp);
			getline(MorseTableFile, morseString);

			// Create Node
			BSTNode<S,C>* New_Node = new BSTNode<S,C>(character, morseString);

			// needs to insert the data into the tree using the insert function
			// tree should be alphabetically ordered l->r
			insert(New_Node);

		}
	}

	MorseTableFile.close();
}

// Destructor
template <class S, class C>
BST<S, C>::~BST()
{
	destroyTree(this->mpRoot);
}

template <class S, class C>
void BST<S, C>::destroyTree(BSTNode<S, C>* pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());
		delete pTree;
	}
}

template <class S, class C>
void BST<S, C>::insert(BSTNode<S, C>* newNode)
{
	insert(this->mpRoot, newNode);
}

template <class S, class C>
void BST<S, C>::insert(BSTNode<S, C>* pTree, BSTNode<S, C>* newNode)
{
	if (pTree == nullptr)
	{
		this->mpRoot = newNode;
	}
	else if (pTree->getCharacter() > newNode->getCharacter())
	{
		if (pTree->getLeftPtr() == nullptr)
		{
			pTree->setLeftPtr(newNode);
		}
		else
		{
			insert(pTree->getLeftPtr(), newNode);
		}
	}
	else
	{
		if (pTree->getCharacter() < newNode->getCharacter())
		{
			if (pTree->getRightPtr() == nullptr)
			{
				pTree->setRightPtr(newNode);
			}
			else
			{
				insert(pTree->getRightPtr(), newNode);
			}
		}
	}
}

template <class S, class C>
void BST<S, C>::print()
{
	print(this->mpRoot);
}

template <class S, class C>
void BST<S, C>::print(BSTNode<S, C>* pTree)
{
	if (pTree != nullptr)
	{
		print(pTree->getLeftPtr());
		std::cout << "English Character: " << pTree->getCharacter() << endl;
		cout << "Morse Code: " << pTree->getString() << endl;
		print(pTree->getRightPtr());
	}
}


template <class S, class C>
bool BST<S, C>::isEmpty()
{
	bool empty = false;
	if (this->mpRoot == nullptr)
	{
		empty = true;
	}
	return empty;
}

template <class S, class C>
void BST<S, C>::search(const C& character)
{
	search(this->mpRoot, character);
}

template <class S, class C>
void BST<S, C>::search(BSTNode<S, C>* pTree, const C& character)
{
	if (pTree != nullptr)
	{
		search(pTree->getLeftPtr(), character);
		if (character == pTree->getCharacter()) {
			cout << pTree->getString()<< " ";
		}
		search(pTree->getRightPtr(), character);
	}
}

template <class S, class C>
void BST<S, C>::convert()
{
	// Open File
	fstream convertFile;
	convertFile.open("Convert.txt", std::ios::in);
	// Now Convert Text
	if (convertFile.is_open())
	{
		C line[100] = "";
		C character = '\0';
		S MorseString = "";
		while (!convertFile.eof())
		{
			int i = 0;
			convertFile.getline(line, 100);
			while (line[i] != '\0') {
				if (line[i] == ' ') {
					cout << "   ";
				}
				else {
					line[i] = toupper(line[i]);
					search(line[i]);
				}
				i++;
			}
			cout << endl;
		}
	}
}


