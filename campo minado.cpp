#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void revela(int x, int y, int mascara[12][12], int tabuleiro[12][12]);




int main()
{
    int tabuleiro[12][12], mascara[12][12], i, j, x, y;
    bool jogo, erro1, erro2;

    srand(time(NULL));


    //ZERANDO MATRIZ
    for(i=0; i<12; i++)
    {
        for(j=0; j<12; j++)
        {
            tabuleiro[i][j] = 0;
            mascara[i][j] = 0;
        }
    }

    for(i=0; i<12; i++)
    {
        tabuleiro[0][i] = 1;
        tabuleiro[11][i] = 1;
        tabuleiro[i][0] = 1;
        tabuleiro[i][11] = 1;
        mascara[0][i] = 1;
        mascara[11][i] = 1;
        mascara[i][0] = 1;
        mascara[i][11] = 1;
    }


    //GERANDO BOMBAS
    for(i=0; i<15; i++)
    {
        x = rand()%10;
        y = rand()%10;
        tabuleiro[x+1][y+1] = 9;
    }



    for(i=1; i<11; i++)
    {
        for(j=1; j<11; j++)
        {
            if(tabuleiro[i][j] != 9)
            {
                if(tabuleiro[i+1][j] == 9)
                    tabuleiro[i][j]++;
                if(tabuleiro[i+1][j+1] == 9)
                    tabuleiro[i][j]++;
                if(tabuleiro[i][j+1] == 9)
                    tabuleiro[i][j]++;
                if(tabuleiro[i-1][j+1] == 9)
                    tabuleiro[i][j]++;
                if(tabuleiro[i-1][j] == 9)
                    tabuleiro[i][j]++;
                if(tabuleiro[i-1][j-1] == 9)
                    tabuleiro[i][j]++;
                if(tabuleiro[i][j-1] == 9)
                    tabuleiro[i][j]++;
                if(tabuleiro[i+1][j-1] == 9)
                    tabuleiro[i][j]++;
            }
        }
    }


    jogo == true;
    erro1 = erro2 = false;

    while(jogo == true)
    {
        system("cls");


        for(i=0; i<12; i++)
            {
                for(j=0; j<12; j++)
                {
                    cout << "  " << tabuleiro[i][j];
                }
                cout << endl;
            }


        for(i=1; i<11; i++)
        {
            cout << "-----------------------------------------" << endl;
            cout << "|";
            for(j=1; j<11; j++)
                {
                if(mascara[i][j] == 0)
                {
                    cout << "   ";
                }
                else
                {
                    cout << " " << tabuleiro[i][j] << " ";
                }
                cout << "|";

            }
            cout << endl;
        }
        cout << "-----------------------------------------" << endl;


        do
        {

            do
            {
                cout << "Digite a linha que deseja verificar a bomba." << endl;
                cin >> x;
                if(x<1 || x>10)
                {
                    erro1=true;
                    cout << "Linha inválida, digite novamente";
                }
                else
                {
                    erro1 = false;
                }
            }while(erro1 == true);

            do
            {
                cout << "Digite a coluna que deseja verificar a bomba." << endl;
                cin >> y;
                if(y<1 || y>10)
                {
                    erro1=true;
                    cout << "Coluna inválida, digite novamente";
                }
                else
                {
                    erro1 = false;
                }
            }while(erro1 == true);

            if(mascara[x][y] == 1)
            {
                erro2 = true;
                cout << "Posicao ja testada, digite outra posicao" << endl;
            }
            else
            {
                erro2 = false;
            }

        }while(erro2 == true);

        if(tabuleiro[x][y] == 9)
        {
            cout << "GAME OVER" << endl << "Voce detonou uma bomba" << endl;
            return 0;
        }
        else
        {
            revela(x, y, mascara, tabuleiro);
        }


    }

    return 0;
}

void revela(int x, int y, int mascara[12][12], int tabuleiro[12][12])
{
    mascara[x][y] = 1;
    if(tabuleiro[x][y] == 0)
    {
        if(tabuleiro[x+1][y] == 0 && mascara[x+1][y] == 0)
            revela(x+1, y, mascara, tabuleiro);
        else if(tabuleiro[x+1][y] !=9)
            mascara[x+1][y] = 1;
        if(tabuleiro[x+1][y+1] == 0 && mascara[x+1][y+1] == 0)
            revela(x+1, y+1, mascara, tabuleiro);
        else if(tabuleiro[x+1][y+1] !=9)
            mascara[x+1][y+1] = 1;
        if(tabuleiro[x][y+1] == 0 && mascara[x][y+1] == 0)
            revela(x, y+1, mascara, tabuleiro);
        else if(tabuleiro[x][y+1] !=9)
            mascara[x][y+1] = 1;
        if(tabuleiro[x-1][y+1] == 0 && mascara[x-1][y+1] == 0)
            revela(x-1, y+1, mascara, tabuleiro);
        else if(tabuleiro[x-1][y+1] !=9)
            mascara[x-1][y+1] = 1;
        if(tabuleiro[x-1][y] == 0 && mascara[x-1][y] == 0)
            revela(x-1, y, mascara, tabuleiro);
        else if(tabuleiro[x-1][y] !=9)
            mascara[x-1][y] = 1;
        if(tabuleiro[x-1][y-1] == 0 && mascara[x-1][y-1] == 0)
            revela(x-1, y-1, mascara, tabuleiro);
        else if(tabuleiro[x-1][y-1] !=9)
            mascara[x-1][y-1] = 1;
        if(tabuleiro[x][y-1] == 0 && mascara[x][y-1] == 0)
            revela(x, y-1, mascara, tabuleiro);
        else if(tabuleiro[x][y-1] !=9)
            mascara[x][y-1] = 1;
        if(tabuleiro[x+1][y-1] == 0 && mascara[x+1][y-1] == 0)
            revela(x+1, y-1, mascara, tabuleiro);
        else if(tabuleiro[x+1][y-1] !=9)
            mascara[x+1][y-1] = 1;
    }


}
