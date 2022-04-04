#include <list>
#include "Engine.h"

list<Move*> Lib;

void King::PossibleMoves(List &moves, Board& b)
{
    int i = coord[0], j = coord[1];
    if(valid_square(i, j+1) && (b.position[i][j+1] == NULL || b.position[i][j+1]->color != color))
        {
            Move* p=new Move(this, i, j+1, b.position[i][j+1] != NULL);
            moves.push_back(p);
            Lib.push_back(p);
        }
    if(valid_square(i, j-1) && (b.position[i][j-1] == NULL || b.position[i][j-1]->color != color))
       {

            Move* p=new Move(this, i, j-1, b.position[i][j-1] != NULL);
            moves.push_back(p);
            Lib.push_back(p);

       }

    if(valid_square(i+1, j+1) && (b.position[i+1][j+1] == NULL || b.position[i+1][j+1]->color != color))

       {

            Move* p=new Move(this, i+1, j+1, b.position[i+1][j+1] != NULL);
            moves.push_back(p);
            Lib.push_back(p);

       }
    if(valid_square(i+1, j) && (b.position[i+1][j] == NULL || b.position[i+1][j]->color != color))
        {
            Move* p=new Move(this, i+1, j, b.position[i+1][j] != NULL);
            moves.push_back(p);
            Lib.push_back(p);
        }
    if(valid_square(i+1, j-1) && (b.position[i+1][j-1] == NULL || b.position[i+1][j-1]->color != color))

        {
            Move* p=new Move(this, i+1, j-1, b.position[i+1][j-1] != NULL);
            moves.push_back(p);
            Lib.push_back(p);
        }
    if(valid_square(i-1, j+1) && (b.position[i-1][j+1] == NULL || b.position[i-1][j+1]->color != color))

       {
           Move* p=new Move(this, i-1, j+1, b.position[i-1][j+1] != NULL);
            moves.push_back(p);
            Lib.push_back(p);

       }
    if(valid_square(i-1, j) && (b.position[i-1][j] == NULL || b.position[i-1][j]->color != color))

       {
           Move* p=new Move(this, i-1, j, b.position[i-1][j] != NULL);
            moves.push_back(p);
            Lib.push_back(p);
       }
    if(valid_square(i-1, j-1) && (b.position[i-1][j-1] == NULL || b.position[i-1][j-1]->color != color))

       {
           Move* p=new Move(this, i-1, j-1, b.position[i-1][j-1] != NULL);
            moves.push_back(p);
            Lib.push_back(p);
       }

}

void Queen::PossibleMoves(List &moves, Board& b)
{
    int i = coord[0], j = coord[1], k = 1;
    while(valid_square(i+k,j) && ( b.position[i+k][j] == NULL || b.position[i+k][j]->color != color))
    {
        if (b.position[i+k][j] == NULL)
        {
            Move* p =new Move(this, i+k, j, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i+k, j, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
    k = 1;
    while(valid_square(i-k,j) && ( b.position[i-k][j] == NULL || b.position[i-k][j]->color != color))
    {
        if (b.position[i-k][j] == NULL)
        {
            Move* p =new Move(this, i-k, j, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i-k, j, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
    k = 1;
    while(valid_square(i,j+k) && ( b.position[i][j+k] == NULL || b.position[i][j+k]->color != color))
    {
        if (b.position[i][j+k] == NULL)
        {
            Move* p =new Move(this, i, j+k, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i, j+k, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
    k = 1;
    while(valid_square(i,j-k) && ( b.position[i][j-k] == NULL || b.position[i][j-k]->color != color))
    {
        if (b.position[i][j-k] == NULL)
        {
            Move* p =new Move(this, i, j-k, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i, j-k, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
    k=1;
     while(valid_square(i+k,j+k) && ( b.position[i+k][j+k] == NULL || b.position[i+k][j+k]->color != color))
    {
        if (b.position[i+k][j+k] == NULL)
        {
            Move* p =new Move(this, i+k, j+k, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i+k, j+k, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
    k = 1;
    while(valid_square(i-k,j-k) && ( b.position[i-k][j-k] == NULL || b.position[i-k][j-k]->color != color))
    {
        if (b.position[i-k][j-k] == NULL)
        {
            Move* p =new Move(this, i-k, j-k, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i-k, j-k, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
    k = 1;
    while(valid_square(i+k,j-k) && ( b.position[i+k][j-k] == NULL || b.position[i+k][j-k]->color != color))
    {
        if (b.position[i+k][j-k] == NULL)
        {
            Move* p =new Move(this, i+k, j-k, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i+k, j-k, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
    k = 1;
    while(valid_square(i-k,j+k) && ( b.position[i-k][j+k] == NULL || b.position[i-k][j+k]->color != color))
    {
        if (b.position[i-k][j+k] == NULL)
        {
            Move* p =new Move(this, i-k, j+k, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i-k, j+k, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
}

void Rook::PossibleMoves(List &moves, Board& b)
{
    int i = coord[0], j = coord[1], k = 1;
    while(valid_square(i+k,j) && ( b.position[i+k][j] == NULL || b.position[i+k][j]->color != color))
    {
        if (b.position[i+k][j] == NULL)
        {
            Move* p =new Move(this, i+k, j, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i+k, j, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
    k = 1;
    while(valid_square(i-k,j) && ( b.position[i-k][j] == NULL || b.position[i-k][j]->color != color))
    {
        if (b.position[i-k][j] == NULL)
        {
            Move* p =new Move(this, i-k, j, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i-k, j, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
    k = 1;
    while(valid_square(i,j+k) && ( b.position[i][j+k] == NULL || b.position[i][j+k]->color != color))
    {
        if (b.position[i][j+k] == NULL)
        {
            Move* p =new Move(this, i, j+k, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i, j+k, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
    k = 1;
    while(valid_square(i,j-k) && ( b.position[i][j-k] == NULL || b.position[i][j-k]->color != color))
    {
        if (b.position[i][j-k] == NULL)
        {
            Move* p =new Move(this, i, j-k, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i, j-k, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
}

void Knight::PossibleMoves(List &moves, Board& b)
{
    int t1[2] = {-1, 1};
    int t2[2] = {-2, 2} ;

    for (int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            {
                int i1 = coord[0] + t1[i], j1 = coord[1] + t2[j];
                if (valid_square(i1, j1))
                    {
                        if (b.position[i1][j1] == NULL)
                        {
                            Move* p = new Move(this,i1,j1,0);
                            moves.push_back(p);
                            Lib.push_back(p);
                        }
                        else if(b.position[i1][j1]->color != color)
                            {
                            Move* p = new Move(this,i1,j1,1);
                            moves.push_back(p);
                            Lib.push_back(p);
                        }
                    }

                i1 = coord[0] + t2[j];
                j1 = coord[1] + t1[i];

                    if (valid_square(i1, j1))
                    {
                        if (b.position[i1][j1] == NULL)
                            moves.push_back(new Move(this,i1,j1,0));
                        else if(b.position[i1][j1]->color != color)
                            moves.push_back(new Move(this,i1,j1,1));
                    }
            }
}

void Bishop::PossibleMoves(List &moves, Board& b)
{
    int i = coord[0], j = coord[1], k = 1;
    while(valid_square(i+k,j+k) && ( b.position[i+k][j+k] == NULL || b.position[i+k][j+k]->color != color))
    {
        if (b.position[i+k][j+k] == NULL)
        {
            Move* p =new Move(this, i+k, j+k, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i+k, j+k, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
    k = 1;
    while(valid_square(i-k,j-k) && ( b.position[i-k][j-k] == NULL || b.position[i-k][j-k]->color != color))
    {
        if (b.position[i-k][j-k] == NULL)
        {
            Move* p =new Move(this, i-k, j-k, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i-k, j-k, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
    k = 1;
    while(valid_square(i+k,j-k) && ( b.position[i+k][j-k] == NULL || b.position[i+k][j-k]->color != color))
    {
        if (b.position[i+k][j-k] == NULL)
        {
            Move* p =new Move(this, i+k, j-k, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i+k, j-k, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
    k = 1;
    while(valid_square(i-k,j+k) && ( b.position[i-k][j+k] == NULL || b.position[i-k][j+k]->color != color))
    {
        if (b.position[i-k][j+k] == NULL)
        {
            Move* p =new Move(this, i-k, j+k, 0);
            moves.push_back(p);
            Lib.push_back(p);
        }
        else
        {
            Move* p =new Move(this, i-k, j+k, 1);
            moves.push_back(p);
            Lib.push_back(p);
            break;
        }
        k++;
    }
}





void Pawn::PossibleMoves(List &moves, Board& b)
{
    int i = coord[0], j = coord[1];


    if(color == black)
    {
        if(valid_square(i+1,j) && b.position[i+1][j] == NULL)
                {
                    Move* p =new Move(this, i+1, j, 0);
                    moves.push_back(p);
                    Lib.push_back(p);
                }


        if(i==1 && b.position[i+2][j] == NULL && b.position[i+1][j] == NULL)
                {
                    Move* p =new Move(this, i+2, j, 0);
                    moves.push_back(p);
                    Lib.push_back(p);
                }

        if(valid_square(i+1,j+1) && b.position[i+1][j+1] != NULL && b.position[i+1][j+1]->color != color)
                {
                    Move* p =new Move(this, i+1, j+1, 1);
                    moves.push_back(p);
                    Lib.push_back(p);
                }


        if(valid_square(i+1,j-1) && b.position[i+1][j-1] != NULL && b.position[i+1][j-1]->color != color)
                {
                    Move* p =new Move(this, i+1, j-1, 1);
                    moves.push_back(p);
                    Lib.push_back(p);
                }
    }

    if(color == white)
    {
        if(valid_square(i-1,j) && b.position[i-1][j] == NULL)
                {
                    Move* p =new Move(this, i-1, j, 0);
                    moves.push_back(p);
                    Lib.push_back(p);
                }

    if( i==6 && b.position[i-2][j] == NULL && b.position[i-1][j] == NULL)
                {
                    Move* p =new Move(this, i-2, j, 0);
                    moves.push_back(p);
                    Lib.push_back(p);
                }
    if(valid_square(i-1,j+1) && b.position[i-1][j+1] != NULL && b.position[i-1][j+1]->color != color)
                {
                    Move* p =new Move(this, i-1, j+1, 1);
                    moves.push_back(p);
                    Lib.push_back(p);
                }

    if(valid_square(i-1,j-1) && b.position[i-1][j-1] != NULL && b.position[i-1][j-1]->color != color)
                {
                    Move* p =new Move(this, i-1, j-1, 1);
                    moves.push_back(p);
                    Lib.push_back(p);
                }
    }
}

void Liberer()
{
    while(!Lib.empty())
    {
        delete(Lib.front());
        Lib.pop_front();
    }
}
