#include <iostream>
#include <stdlib.h>
using namespace std;

void printBoard(char *board)
{
	system("clear");
	cout<<" "<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<endl
		<<" - + - + - "<<endl
		<<" "<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<endl
		<<" - + - + - "<<endl
		<<" "<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<endl;
}

char isGameOver(char *board)
{
	if(board[0] == board[1] && board[0] == board[2]){ return board[0]; }
	if(board[3] == board[4] && board[3] == board[5]){ return board[3]; }
	if(board[6] == board[7] && board[6] == board[8]){ return board[6]; }
	if(board[0] == board[3] && board[0] == board[6]){ return board[0]; }
	if(board[1] == board[4] && board[1] == board[7]){ return board[1]; }
	if(board[2] == board[5] && board[2] == board[8]){ return board[2]; }
	if(board[0] == board[4] && board[0] == board[8]){ return board[0]; }
	if(board[2] == board[4] && board[2] == board[6]){ return board[6]; }
	return 'N';
} 

int main()
{
	int move;
	char board[9] = {'1','2','3','4','5','6','7','8','9'};
	for(int i = 0; i<9; i++)
	{
		printBoard(board);
		while(true)
		{
			cout<<"Make a move: ";
			cin>>move;
			move--;
			if(move < 0 || move > 8)
			{
				cout<<"Please make a move on the grid"<<endl;
			}
			else if(board[move] == 'X' || board[move] == 'O')
			{
				cout<<"Move already made"<<endl;
			}
			else
			{
				break;
			}
		}

		if(i%2)
		{
			board[move] = 'O';
		}
		else
		{
			board[move] = 'X';
		}
		printBoard(board);
		char winner = isGameOver(board);
		if(winner != 'N')
		{
			cout<<"Player "
				<<(winner == 'X' ? " 1" : " 2")
				<<" won"<<endl;
			return 0;
		}
	}
	cout<<"Game drawn"<<endl;
}
