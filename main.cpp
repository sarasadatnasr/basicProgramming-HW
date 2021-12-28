
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include <conio.h>

using namespace std;

int gSelectPoints[6][6][2];
int gXOPoints[6][6][2];
int gSelectPointsBig[2][2][2];
int marks[6][6];

int moveCount;

wstring wTable[14];
wstring wTempTable[14];
wstring wSelectSmall[3];
wstring wSelectBig[7];
wchar_t wX = L'X';
wchar_t wO = L'O';
wchar_t wMark[2]={L'X',L'O'};
int lastSelectorPosSmall[2];
int lastSelectorPosBig[2];

void initialize();
void XO_Selector();
void RL_Selector();
void XO_Marker(wstring wMarkTable[]);
void XO_RotateCW();
void XO_RotateCCW();
void game();

bool checkWin();
bool checkDraw();
bool search2D(char grid[6][6], int row, int col, string word); 
bool patternSearch(char grid[6][6], string word);


bool currentUser;
bool markFlag=false;
bool winFlag =false;
bool winFlagO=false;
bool winFlagX=false;


struct Players{
    wstring name;
    int score;
};

Players player[20];




void game(){

system("cls");

wcout << "Player 1(X) Enter your name : ";
wcin >> player[0].name;

wcout << "Player 2(O) Enter your name : ";
wcin >> player[1].name;




        initialize();

    do {
        XO_Selector();
        RL_Selector();
    }while(!checkWin() && !checkDraw());

    
}

void menu(){
    char ch;
    do {
        
        system("cls");
        wcout << "1-Start" << endl;
        wcout << "2-Ranking" << endl;
        wcout << "3-Exit" << endl;
        ch=getch();

        switch (ch)
        {
        case '1':
            game();
            break;
        case '2':
            break;
        case '3':
            exit(0);
        default :
            system("cls");
            wcout << "Wrong Choose!" << endl;
            getch();
        }
    }while(ch !='3');
}


void initialize(){
    int SelectPoints[6][6][2]={{ {0,0 },{0, 4},{0, 8},{0, 13},{0, 17},{0, 21}},
                                {{2,0 },{2, 4},{2, 8},{2, 13},{2, 17},{2, 21}},
                                {{4,0 },{4, 4},{4, 8},{4, 13},{4, 17},{4, 21}},
                                {{7,0 },{7, 4},{7, 8},{7, 13},{7, 17},{7, 21}},
                                {{9,0 },{9, 4},{9, 8},{9, 13},{9, 17},{9, 21}},
                                {{11,0},{11,4},{11,8},{11,13},{11,17},{11,21}}};



    int XOPoints[6][6][2]={{ {1, 2 },{1, 6},{1, 10},{1, 15},{1, 19},{1, 23}},
                            {{3, 2 },{3, 6},{3, 10},{3, 15},{3, 19},{3, 23}},
                            {{5, 2 },{5, 6},{5, 10},{5, 15},{5, 19},{5, 23}},
                            {{8, 2 },{8, 6},{8, 10},{8, 15},{8, 19},{8, 23}},
                            {{10,2 },{10,6},{10,10},{10,15},{10,19},{10,23}},
                            {{12,2 },{12,6},{12,10},{12,15},{12,19},{12,23}}};

    int SelectPointsBig[2][2][2]= {{{0,0},{0,13}},
                                   {{7,0},{7,13}}};
    

    

    for (int i=0;i<6; i++)
        for (int j=0; j<6; j++){
                marks[i][j]=0;
            }


    for (int i=0;i<6; i++)
        for (int j=0; j<6; j++)
            for (int k=0; k<2; k++){
                gSelectPoints[i][j][k]=SelectPoints[i][j][k];
                gXOPoints[i][j][k]=XOPoints[i][j][k];
            }

    for (int i=0;i<2; i++)
        for (int j=0; j<2; j++)
            for (int k=0; k<2; k++){
                gSelectPointsBig[i][j][k]=SelectPointsBig[i][j][k];
            }

    wTable[0]  = L"┌───┬───┬───┐┌───┬───┬───┐";
    wTable[1]  = L"│   │   │   ││   │   │   │";
    wTable[2]  = L"├───┼───┼───┤├───┼───┼───┤";
    wTable[3]  = L"│   │   │   ││   │   │   │";
    wTable[4]  = L"├───┼───┼───┤├───┼───┼───┤";
    wTable[5]  = L"│   │   │   ││   │   │   │";
    wTable[6]  = L"└───┴───┴───┘└───┴───┴───┘";
    wTable[7]  = L"┌───┬───┬───┐┌───┬───┬───┐";
    wTable[8]  = L"│   │   │   ││   │   │   │";
    wTable[9]  = L"├───┼───┼───┤├───┼───┼───┤";
    wTable[10] = L"│   │   │   ││   │   │   │";
    wTable[11] = L"├───┼───┼───┤├───┼───┼───┤";
    wTable[12] = L"│   │   │   ││   │   │   │";
    wTable[13] = L"└───┴───┴───┘└───┴───┴───┘";

    wSelectBig[0]= L"╔═══╤═══╤═══╗";
    wSelectBig[1]= L"║   │   │   ║";
    wSelectBig[2]= L"╟───┼───┼───╢";
    wSelectBig[3]= L"║   │   │   ║";
    wSelectBig[4]= L"╟───┼───┼───╢";
    wSelectBig[5]= L"║   │   │   ║";
    wSelectBig[6]= L"╚═══╧═══╧═══╝";

    wSelectSmall[0]=L"╔═══╗";
    wSelectSmall[1]=L"║   ║";
    wSelectSmall[2]=L"╚═══╝";

    currentUser = true;
    lastSelectorPosBig[0]=0;
    lastSelectorPosBig[1]=0;
    lastSelectorPosSmall[0]=0;
    lastSelectorPosSmall[1]=0;

    moveCount =0;
}

int main()
{

    _setmode(_fileno(stdout), _O_U16TEXT);
    SetConsoleOutputCP(CP_UTF8);
    menu();


}

void XO_Marker(wstring wMarkTable[])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (marks[i][j] == 1)
            {
                int x, y;
                x = gXOPoints[i][j][0];
                y = gXOPoints[i][j][1];
                wMarkTable[x][y] = wX;
            }
            else if (marks[i][j] == 2)
            {
                int x, y;
                x = gXOPoints[i][j][0];
                y = gXOPoints[i][j][1];
                wMarkTable[x][y] = wO;
            }
        }
    }
}

void XO_Selector()
{
    char ch;
    int x, y;
    markFlag = false;

    while(!markFlag){

    do
    {
        system("cls");
        wcout << player[!currentUser].name <<"'s turn as " << wMark[!currentUser] << " : "<<endl;
        for (int i = 0; i < 14; i++)
        {
            wTempTable[i] = wTable[i];
        }

        x = gSelectPoints[lastSelectorPosSmall[0]][lastSelectorPosSmall[1]][0];
        y = gSelectPoints[lastSelectorPosSmall[0]][lastSelectorPosSmall[1]][1];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++)
            {
                wTempTable[x + i][y + j] = wSelectSmall[i][j];
            }

        XO_Marker(wTempTable);

        for (int i = 0; i < 14; i++)
        {
            wcout << wTempTable[i] << endl;
        }

        ch = getch();

        switch (ch)
        {
        case 'A':
        case 'a':
            if (lastSelectorPosSmall[1] > 0)
                lastSelectorPosSmall[1]--;
            break;
        case 'D':
        case 'd':
            if (lastSelectorPosSmall[1] < 5)
                lastSelectorPosSmall[1]++;
            break;
        case 'W':
        case 'w':
            if (lastSelectorPosSmall[0] > 0)
                lastSelectorPosSmall[0]--;
            break;
        case 'S':
        case 's':
            if (lastSelectorPosSmall[0] < 5)
                lastSelectorPosSmall[0]++;
            break;
        }

    } while (ch != 13);

    if (currentUser)
    { // if X user
        if (!marks[lastSelectorPosSmall[0]][lastSelectorPosSmall[1]]){
            marks[lastSelectorPosSmall[0]][lastSelectorPosSmall[1]] = 1;
            // currentUser = false;
            markFlag=true;
        } 
    }
    else
    { // if O user
        if (!marks[lastSelectorPosSmall[0]][lastSelectorPosSmall[1]]){
            marks[lastSelectorPosSmall[0]][lastSelectorPosSmall[1]] = 2;
            // currentUser = true;
            markFlag=true;
        }
    }

    }

}


void RL_Selector()
{
    char ch;
    int x, y;

    do
    {

        system("cls");

        for (int i = 0; i < 14; i++)
        {
            wTempTable[i] = wTable[i];
        }
        wcout << player[!currentUser].name <<"'s turn as " << wMark[!currentUser] << " : "<<endl;
        x = gSelectPointsBig[lastSelectorPosBig[0]][lastSelectorPosBig[1]][0];
        y = gSelectPointsBig[lastSelectorPosBig[0]][lastSelectorPosBig[1]][1];

        for (int i = 0; i < 7; i++)
            for (int j = 0; j < 13; j++)
            {
                wTempTable[x + i][y + j] = wSelectBig[i][j];
            }

        XO_Marker(wTempTable);

        for (int i = 0; i < 14; i++)
        {
            wcout << wTempTable[i] << endl;
        }

        ch = getch();

        switch (ch)
        {
        case 'A':
        case 'a':
            if (lastSelectorPosBig[1] > 0)
                lastSelectorPosBig[1] --;
            break;
        case 'D':
        case 'd':
            if (lastSelectorPosBig[1] < 1)
                lastSelectorPosBig[1] ++;
            break;
        case 'W':
        case 'w':
            if (lastSelectorPosBig[0] > 0)
                lastSelectorPosBig[0] --;
            break;
        case 'S':
        case 's':
            if (lastSelectorPosBig[0] < 1)
                lastSelectorPosBig[0] ++;
            break;
        }

    } while (ch != 'l' && ch != 'r');

    if (ch == 'r')
    {
        XO_RotateCW();
    }
    else if (ch == 'l')
    {
        XO_RotateCCW();
    }

    currentUser = !currentUser;
}

void XO_RotateCW()
{
    int N = 3;
    int rotateXO[3][3];

    int xStart;
    int yStart;

    if (lastSelectorPosBig[0] == 0) yStart = 0;
        else yStart = 3;
    if (lastSelectorPosBig[1] == 0) xStart = 0;
        else xStart = 3;
    wcout << yStart << ";" << xStart << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            rotateXO[i][j] = marks[i+yStart][j+xStart];
        }
    }

    for (int i = 0; i < N / 2; i++)
    {
        for (int j = i; j < N - i - 1; j++)
        {

            int temp = rotateXO[i][j];
            rotateXO[i][j] = rotateXO[N - 1 - j][i];
            rotateXO[N - 1 - j][i] = rotateXO[N - 1 - i][N - 1 - j];
            rotateXO[N - 1 - i][N - 1 - j] = rotateXO[j][N - 1 - i];
            rotateXO[j][N - 1 - i] = temp;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            marks[i+yStart][j+xStart] = rotateXO[i][j];
        }
    }
}

void XO_RotateCCW()
{
    int N=3;
    int rotateXO[3][3];

    int xStart;
    int yStart;

    if (lastSelectorPosBig[0] == 0) yStart = 0;
        else yStart = 3;
    if (lastSelectorPosBig[1] == 0) xStart = 0;
        else xStart = 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            rotateXO[i][j] = marks[i+yStart][j+xStart];
        }
    }

    for (int i = 0; i < N / 2; i++) { 
        for (int j = i; j < N - i - 1; j++) { 

            int temp = rotateXO[i][j]; 
            rotateXO[i][j] = rotateXO[j][N - 1 - i]; 
            rotateXO[j][N - 1 - i] = rotateXO[N - 1 - i][N - 1 - j]; 
            rotateXO[N - 1 - i][N - 1 - j] = rotateXO[N - 1 - j][i]; 
            rotateXO[N - 1 - j][i] = temp; 
        } 
    } 

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            marks[i+yStart][j+xStart] = rotateXO[i][j];
        }
    }
} 

bool checkDraw(){
    int flagCount =0 ;
    for (int i=0; i<6; i++){
        for (int j=0; j<6; j++){
            if (marks[i][j]) flagCount++;
        }
    }
    if (flagCount == 36) return true;
    else return false;
}

bool checkWin(){

    char marksGrid[6][6];
    
    for (int i=0; i<6; i++)
        for (int j=0; j<6; j++)
                marksGrid[i][j] = marks[i][j] + 48;
    
    string winO = "22222";
    string winX = "11111";

    winFlagO = patternSearch(marksGrid, winO);
    winFlagX = patternSearch(marksGrid, winX);


    if ( winFlagX || winFlagO){
        winFlag = true;
        return true;
    }

    return false;
}


bool search2D(char grid[6][6], int row, int col, string word) 
{ 
    int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
	
	if (grid[row][col] != word[0]) 
		return false; 

	int len = word.length(); 

	for (int dir = 0; dir < 8; dir++) { 
		
		int k, rd = row + x[dir], cd = col + y[dir]; 

		for (k = 1; k < len; k++) { 
			if (rd >= 6 || rd < 0 || cd >= 6 || cd < 0) 
				break; 

			if (grid[rd][cd] != word[k]) 
				break; 

			rd += x[dir], cd += y[dir]; 
		} 

		if (k == len) 
			return true; 
	} 
	return false; 
} 

bool patternSearch(char grid[6][6], string word) 
{ 
	for (int row = 0; row < 6; row++) 
		for (int col = 0; col < 6; col++) 
			if (search2D(grid, row, col, word)) 
                return true;
    
    return false;
} 