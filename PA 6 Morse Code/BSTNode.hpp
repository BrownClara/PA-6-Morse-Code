/*   Title: PA 6 Morse Code
*    Author: Clara Brown
*    Date Created: 10/25/21
*    Last Modified:
*
*    Description: Uses a BST to look up Morse Code characters.
*/
#pragma once
#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::fstream;

template<typename S, typename C>
class BSTNode
{
public:
	// Constructors
	BSTNode();
	BSTNode(C& character, S& newString);

	//Destructors
	~BSTNode();


	//Setters
	void setCharacter(C& newChar);
	void setString(S& newString);
	void setLeftPtr(BSTNode<S,C>* newPtr);
	void setRightPtr(BSTNode<S,C>* newPtr);

	//Getters
	C getCharacter() const;
	S getString() const;
	BSTNode<S,C>* getLeftPtr() const;
	BSTNode<S,C>* getRightPtr() const;


private:
	C mEnglishCharacter;
	S mMorseString;
	BSTNode<S, C>* mpLeft;
	BSTNode<S, C>* mpRight;
};


// Constructors
template<typename S, typename C>
BSTNode<S, C>::BSTNode()
{
	mEnglishCharacter = '\0';
	mMorseString = '\0';
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

template<typename S, typename C>
BSTNode<S, C>::BSTNode(C& character, S& newString)
{
	this->mEnglishCharacter = character;
	this->mMorseString = newString;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

//Destructors
template<typename S, typename C>
BSTNode<S, C>::~BSTNode()
{

}


//Setters
template<typename S, typename C>
void BSTNode<S, C>::setCharacter(C& newChar)
{
	this->mEnglishCharacter = newChar;
}

template<typename S, typename C>
void BSTNode<S, C>::setString(S& newString)
{
	this->mMorseString = newString;
}

template<typename S, typename C>
void BSTNode<S, C>::setLeftPtr(BSTNode<S, C>* newPtr)
{
	this->mpLeft = newPtr;
}

template<typename S, typename C>
void BSTNode<S, C>::setRightPtr(BSTNode<S, C>* newPtr)
{
	this->mpRight = newPtr;
}

//Getters
template<typename S, typename C>
C BSTNode<S, C>::getCharacter() const
{
	return this->mEnglishCharacter;
}

template<typename S, typename C>
S BSTNode<S, C>::getString() const
{
	return this->mMorseString;
}

template<typename S, typename C>
BSTNode<S, C>* BSTNode<S, C>::getLeftPtr() const
{
	return this->mpLeft;
}

template<typename S, typename C>
BSTNode<S, C>* BSTNode<S, C>::getRightPtr() const
{
	return this->mpRight;
}
