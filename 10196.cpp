#include <iostream>
using namespace std;

//Funciona bien
bool check_in_king_by_horse(int some_x, int some_y,char piece,char table[9][9]){
	//CABALLO
	if(table[some_x+1][some_y -2] == piece && (some_x+1) <9 && (some_y-2)>0){
		return true;
	} 
	if(table[some_x+2][some_y -1] == piece && (some_x+2)<9 && (some_y-1)>0){
		return true;
	}  
	if(table[some_x+2][some_y +1] == piece && (some_x+2)<9 && (some_y+1)<9){
		return true;
	} 
	if(table[some_x+1][some_y+2] == piece && (some_x+1)<9 && (some_y+2)<9){
		return true;
	}
	if(table[some_x-1][some_y +2] == piece && (some_x-1)>0 && (some_y+2)<9){
		return true;
	}
	if(table[some_x-2][some_y +1] == piece &&( some_x-2)>0 && (some_y+1)<9){
		return true;
	}
	if(table[some_x-2][some_y -1] == piece && (some_x-2)>0 && (some_y-1)>0){
		return true;
	}
	if(table[some_x-1][some_y -2] == piece && (some_x-1)>0 && (some_y-2)>0){
		return true;
	}
	else return false;
}

//Funciona bien
bool check_in_king_by_bishop(int some_x,int some_y,char piece,char table[9][9]){
	//Alfil
	int x = some_x-1;
	int y = some_y-1;
	bool result = false;
	while(x > 0 || y > 0){
		if (table[x][y] == piece){result = true;}
		else if (table[x][y] != '.'){break;}
		x--;
		y--;
	}
	x = some_x+1;
	y = some_y-1;
	while(x < 9 || y > 0){
		if (table[x][y] == piece){result = true;}
		else if (table[x][y] != '.'){break;}
		x++;
		y--;
	}
	x = some_x+1;
	y = some_y+1;
	while(x < 9 || y < 9){
		if (table[x][y] == piece){result = true;}
		else if (table[x][y] != '.'){break;}
		x++;
		y++;
	}
	x = some_x-1;
	y = some_y+1;
	while(x > 0 || y < 9){
		if (table[x][y] == piece){result = true;}
		else if (table[x][y] != '.'){break;}
		x--;
		y++;
	}
	return result;
}

//Funciona bien
bool check_in_king_by_rook(int some_x,int some_y,char piece,char table[9][9]){
	int y;
	int x;
	bool result =false;
	for(y = some_y+1; y<=8;y++){
		if (table[some_x][y] == piece){result = true; }
		else if (table[some_x][y] != '.'){break;}
	}
	for(x = some_x+1; x<=8;x++){
		if (table[x][some_y] == piece){result = true;}
		else if (table[x][some_y] != '.'){break;}
	}
	for(y = some_y-1; y>0;y--){
		if (table[some_x][y] == piece){result = true;}
		else if (table[some_x][y] != '.'){break;}	
	}
	for(x = some_x-1; x>0;x--){
		if (table[x][some_y] == piece){result = true;}
		else if (table[x][some_y] != '.'){break;}
	}
	return result;
}

//Nos ahorramos el método check_in_king_by_queen para hacerlo en el main directamente, ya que es la fusión de la torre y el alfil

//Funciona
bool check_in_king_by_pawn(int some_x, int some_y, char piece, char table[9][9]){
	if (piece == 'p'){
		if (table[some_x-1][some_y-1] == piece || table[some_x+1][some_y-1] == piece){return true;}
	}
	else if(piece == 'P'){
		if (table[some_x-1][some_y+1] == piece || table[some_x+1][some_y+1] == piece){return true;}
	}
	return false;
}

//Funciona
bool check_in_king_by_king(int some_x, int some_y, char piece,char table[9][9]){
	if(table[some_x+1][some_y] == piece || table[some_x+1][some_y+1] == piece ||table[some_x][some_y+1] == piece ||
	   table[some_x-1][some_y+1] == piece || table[some_x-1][some_y] == piece ||table[some_x-1][some_y-1] == piece ||
	   table[some_x][some_y-1] == piece || table[some_x+1][some_y-1] == piece){
		return true;
	}
	return false;
}

bool check_in_king_by_queen(int some_x, int some_y, char piece,char table[9][9]){
	if((check_in_king_by_bishop(some_x,some_y,piece,table) || check_in_king_by_rook(some_x,some_y,piece,table)) == true){
		return true;
	}
	return false;
}

int main (void) {
	char table[9][9];
	int white_x;
	int white_y;
	int black_x;
	int black_y;
	bool forever(true);
	for (int t = 1; forever; ++t) {
		white_x = white_y = black_y = black_x = -1;

		for (int j = 1; j < 9; j++){
      		for (int i = 1; i < 9; i++){
        		table[i][j] = '.';
      		}
		}	
			
		for (int j = 1; j<9; j++){
			for (int i = 1; i<9; i++){
				cin >> table[i][j];

				if (table[i][j] == 'K'){
					white_y = j;
					white_x = i;
				}
				else if (table[i][j]== 'k'){
					black_y = j;
					black_x = i;
				}
			}
		}

		
		if ((white_x == -1 || white_y == -1) && (black_x == -1 || black_y == 1)){
			break;
		}
		cout << "Game #" << t << ": ";
		if(check_in_king_by_queen(black_x,black_y,'Q',table) ){
			cout << "black king is in check.\n";
		}
		else if(check_in_king_by_rook(black_x,black_y,'R',table)){
			cout << "black king is in check.\n";
		}
		else if(check_in_king_by_horse(black_x,black_y,'N',table)){
			cout << "black king is in check.\n";
		}
		else if(check_in_king_by_bishop(black_x,black_y,'B',table)){
			cout << "black king is in check.\n";
		}
		else if(check_in_king_by_pawn(black_x,black_y,'P',table)){
			cout << "black king is in check.\n";
		}
		else if(check_in_king_by_king(black_x,black_y,'K',table)){
			cout << "black king is in check.\n";
		}
		else if(check_in_king_by_bishop(white_x,white_y,'b',table)){
			cout << "white king is in check.\n";
		}
		else if(check_in_king_by_horse(white_x,white_y,'n',table)){
			cout << "white king is in check.\n";
		}
		else if(check_in_king_by_king(white_x,white_y,'k',table)){
			cout << "white king is in check.\n";
		}
		else if(check_in_king_by_queen(white_x,white_y,'q',table)){
			cout << "white king is in check.\n";
		}
		else if(check_in_king_by_pawn(white_x,white_y,'p',table)){
			cout << "white king is in check.\n";
		}
		else if(check_in_king_by_rook(white_x,white_y,'r',table))
		{
			cout << "white king is in check.\n";
		}
		else{
			cout << "no king is in check.\n";
		}
	}
}