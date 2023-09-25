#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int tabuleiro[3][3], i, j, n, x, y, vencedor, jogadas, cont1, cont2;
    bool jogo, erro1, erro2;

    n = 2;
    //////////////////////INICIANDO MATRIZ
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            tabuleiro[i][j] = n;
            n++;
        }
    }

    jogo = true;
    jogadas = 0;
    while(jogo == true)
    {
        system("cls");

        ///////////////////////////IMPRIMINDO MATRIZ
        cont2 = 0;
    ///////////////IMPRESSAO
        for(i=0; i<3; i++)
        {
            cont1=0;
            for(j=0; j<3; j++)
            {
                if(tabuleiro[i][j] == 0)
                {
                    cout << "  X  ";
                }
                else if(tabuleiro[i][j] == 1)
                {
                    cout << "  O  ";
                }
                else
                {
                    cout << "     ";
                }
                if(cont1<2)
                    {
                        cout << "|";
                        cont1++;
                    }
            }
            if(cont2<2)
            {
                cout << endl << "-----------------" << endl;
                cont2++;
            }
        }
        cout << endl;


        do
        {

            do
            {
                cout << "Jogador 1(X) digite a linha que deseja jogar." << endl;
                cin >> x;

                if(x > 3 || x < 1)
                {
                    erro1 = true;
                    cout << "Linha invalida, digite novamente" << endl;
                }
                else
                {
                    erro1= false;
                }

            }while (erro1==true);

            do
            {
                cout << "Jogador 1(X) digite a coluna que deseja jogar." << endl;
                cin >> y;

                if(y > 3 || y < 0)
                {
                    erro1 = true;
                    cout << "Coluna invalida, digite novamente" << endl;
                }
                else
                {
                    erro1= false;
                }
            }while (erro1== true);

            if(tabuleiro[x-1][y-1] == 0 || tabuleiro[x-1][y-1] == 1)
            {
                erro2 = true;
                cout << "Celula ja foi jogada, digite outra celula" << endl;
            }
            else
            {
                tabuleiro[x-1][y-1] = 0;
                erro2 = false;
                jogadas++;
            }
        }while(erro2 == true);

        ///////////////IMPRESSAO
     system("cls");

        cont2 = 0;
        for(i=0; i<3; i++)
        {
            cont1=0;
            for(j=0; j<3; j++)
            {
                if(tabuleiro[i][j] == 0)
                {
                    cout << "  X  ";
                }
                else if(tabuleiro[i][j] == 1)
                {
                    cout << "  O  ";
                }
                else
                {
                    cout << "     ";
                }
                if(cont1<2)
                    {
                        cout << "|";
                        cont1++;
                    }
            }
            if(cont2<2)
            {
                cout << endl << "-----------------" << endl;
                cont2++;
            }
        }
        cout << endl;
    cout << "-----------------" << endl;

    //condioes de vitoria

    for(i=0; i<3; i++)
    {
        if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2])
        {
            jogo = false;
            vencedor = 1;
        }

    }

    for(i=0; i<3; i++)
    {
        if(tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i])
        {
            jogo = false;
            vencedor = 1;
        }

    }

    if(tabuleiro[0][0] ==  tabuleiro [1][1] && tabuleiro[0][0] == tabuleiro[2][2])
    {
        jogo = false;
        vencedor = 1;
    }

    else if(tabuleiro[0][2] ==  tabuleiro [1][1] && tabuleiro[0][2] == tabuleiro[2][0])
    {
        jogo = false;
        vencedor = 1;
    }

    else if(jogo == true && jogadas == 9)
    {
        jogo = false;
        vencedor = 0;
    }
    //////////////////player 2
    if(jogo == true)
    {

        do
        {

            do
            {
                cout << "Jogador 2(O) digite a linha que deseja jogar." << endl;
                cin >> x;

                if(x > 3 || x < 1)
                {
                    erro1 = true;
                    cout << "Linha invalida, digite novamente" << endl;
                }
                else
                {
                    erro1= false;
                }

            }while (erro1==true);

            do
            {
                cout << "Jogador 2(O) digite a coluna que deseja jogar." << endl;
                cin >> y;

                if(y > 3 || y < 0)
                {
                    erro1 = true;
                    cout << "Coluna invalida, digite novamente" << endl;
                }
                else
                {
                    erro1= false;
                }
            }while (erro1== true);

            if(tabuleiro[x-1][y-1] == 0 || tabuleiro[x-1][y-1] == 1)
            {
                erro2 = true;
                cout << "Celula ja foi jogada, digite outra celula" << endl;
            }
            else
            {
                tabuleiro[x-1][y-1] = 1;
                erro2 = false;
                jogadas++;
            }
        }while(erro2 == true);

        ///////////////IMPRESSAO
     system("cls");

        cont2 = 0;
        for(i=0; i<3; i++)
        {
            cont1=0;
            for(j=0; j<3; j++)
            {
                if(tabuleiro[i][j] == 0)
                {
                    cout << "  X  ";
                }
                else if(tabuleiro[i][j] == 1)
                {
                    cout << "  O  ";
                }
                else
                {
                    cout << "     ";
                }
                if(cont1<2)
                    {
                        cout << "|";
                        cont1++;
                    }
            }
            if(cont2<2)
            {
                cout << endl << "-----------------" << endl;
                cont2++;
            }
        }
        cout << endl;
    cout << "-----------------" << endl;

    //condioes de vitoria

    for(i=0; i<3; i++)
    {
        if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2])
        {
            jogo = false;
            vencedor = 2;
        }

    }

    for(i=0; i<3; i++)
    {
        if(tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i])
        {
            jogo = false;
            vencedor = 2;
        }

    }

    if(tabuleiro[0][0] ==  tabuleiro [1][1] && tabuleiro[0][0] == tabuleiro[2][2])
    {
        jogo = false;
        vencedor = 2;
    }

    else if(tabuleiro[0][2] ==  tabuleiro [1][1] && tabuleiro[0][2] == tabuleiro[2][0])
    {
        jogo = false;
        vencedor = 2;
    }


    }


    }

    if(vencedor != 0)
    {
        cout << "GAME OVER" << endl << " O player " << vencedor << " ganhou o jogo" << endl;
    }
    else
    {
        cout << "GAME OVER" << endl << " Houve um empate, deu velha" << endl;
    }






    return 0;
}
