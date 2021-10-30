/*   Title: PA 6 Morse Code
*    Author: Clara Brown
*    Date Created: 10/25/21
*    Last Modified: 10/29/21
*    
*    Description: Uses a BST to look up Morse Code characters.
*    Orion Green helped me with search
*/

#include "BST.h"

int main(void)
{

	// Create Object of LookUp Table
	BST<string, char> table;

	// Print the Table
	table.print();

	// Print Message in Morse
	table.convert();



	return 0;
}