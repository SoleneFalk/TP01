#include <iostream> 
using namespace std;

// Définir les variables globales

char table[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

int row;
int column;
int digit;
char player='X';
bool tie = false;
string p1;
string p2;


void DisplayTable()

// Définir un tableau qui sera montré dans la console 

	{
		cout << "   |   |   " << endl;
		cout << " " << table[0][0] << " | " << table[0][1] << " | " << table[0][2] << "" << endl;
		cout << "___|___|___" << endl;
		cout << "   |   |   " << endl;
		cout << " " << table[1][0] << " | " << table[1][1] << " | " << table[1][2] << " " << endl;
		cout << "___|___|___" << endl;
		cout << "   |   |   " << endl;
		cout << " " << table[2][0] << " | " << table[2][1] << " | " << table[2][2] << " " << endl;
		cout << "___|___|___" << endl;
	}

void InputPlayer()
	{

	// Définir le tour de joueur p1 ou p2 

if(player=='X')
{
	cout << p1 << "please enter your move (1-9):" << endl;
	cin >> digit;
}

else if (player == '0')
{
	cout<<p2<<"please enter your move (1-9):"<<endl;
	cin >> digit;
}

void CheckCorrectInput() {

	// Vérifier que le digit que le joueur a entré dans la console est correct vis-à-vis des limites du tableau 

	if (digit == 1) { row = 0; column = 0; }
	if (digit == 2) { row = 0; column = 1; }
	if (digit == 3) { row = 0; column = 2; }
	if (digit == 4) { row = 1; column = 0; }
	if (digit == 5) { row = 1; column = 1; }
	if (digit == 6) { row = 1; column = 2; }
	if (digit == 7) { row = 2; column = 0; }
	if (digit == 8) { row = 2; column = 1; }
	if (digit == 9) { row = 2; column = 2; }

	else if (digit < 1 || digit>9) {
		cout << "Invalid input! Please try again." << endl;
	}
}


// Vérifier que la case demandée n'est pas déjà occupée par un autre X ou 0 et remplir le tableau en fonction 

if(input=='X' && table[row][column] != 'X' && table[row][column] != '0')
{
	table[row][column] = 'X';
	input = '0';
}

else if (input == '0' && table[row][column] != 'X' && table[row][column] != '0')
{
	table[row][column] = '0';
	input = 'X';
}

else { 
	cout << "Occupied cell! Please try again." << endl; 
InputPlayer();
}

DisplayTable();

	}

bool WinDraw()

// Conditions de victoire, défaite ou tie 

{
	for (int i = 0; i < 3; i++) {
		if (table[i][0] == table[i][1] && table[i][1] == table[i][2] || table[0][i] == table[1][i] && table[1][i] == table[2][i])
			return true;
	}
	if (table[0][0] == table[1][1] && table[1][1] == table[2][2] || table[0][2] == table[1][1] && table[1][1] == table[2][0])
		return true;

	for (int i=0; i<3; i++) 
	{
		for (int j=0;j<3;j++) 
		{
			if (table[i][j] != 'X' && table[i][j] != '0')
			{ return false;
			}
				
		}
	}

	tie = true;
	return false;
}

int main() {

	// Fonction principale, permet d'abord d'entrer le nom du premier et deuxième joueur 

	cout << "Enter the name of the first player:" << endl;
	cin >> p1;
	cout << "Enter the name of the second player:" << endl;
	cin >> p2;


	/*Tant que la condition de victoire / défaite / tie n'est pas remplie, le code continuera de 
	1) afficher le tableau 
	2) demander l'input du joueur et remplir le tableau 
	3) vérifier les conditions de défaites et victoire */ 
	while (!WinDraw())
	{
		DisplayTable();
		InputPlayer();
		WinDraw();
	}

	// Message de victoire ou de tie 

	if (player == 'X' && tie == false) {
		cout << p2 << "wins!" << endl;
	}

	else if (player == '0' && tie = false) {
		cout << p1 << " wins!" << endl;

	else {
		cout << "It's a draw..." << endl;
	}
}
