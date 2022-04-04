#include <SFML/Graphics.hpp>
#include <time.h>
//#include <windows.h>


#include <iostream>
#include <stdlib.h>
#include <vector>

#define white true
#define black false
#define sizespr 125

using namespace std;


class Move;
class Board;
class List;


class Piece
{
public:
    sf::Sprite spr;
    char type;
    bool color;
    int coord[2];
    Piece(int, int, bool);
    int getvalue();
    virtual void PossibleMoves(List &moves, Board& b)=0;
    int value;
};

class King : public Piece
{

public:
    King(int, int, bool);
    void PossibleMoves(List &moves, Board& b);
};


class Queen : public Piece
{
    public:
    Queen(int, int, bool);
    void PossibleMoves(List &moves, Board& b);
};


class Rook : public Piece
{
    public:
    Rook(int, int, bool);
    void PossibleMoves(List &moves, Board& b);
};


class Knight : public Piece
{
    public:
    Knight(int, int, bool);
    void PossibleMoves(List &moves, Board& b);
};


class Bishop : public Piece
{
    public:
    Bishop(int, int, bool);
    void PossibleMoves(List &moves, Board& b);
};


class Pawn : public Piece
{
    public:
    Pawn(int, int, bool);
    void PossibleMoves(List &moves, Board& b);
};



class Board
{
public:
    Piece* position[8][8];
    sf::Sprite spr;
    Board();
    void play (Move);
    List LegalMoves(bool);
    Move Best_Move(bool, int);
    int evaluation();
    List PossibleMoves(bool);
    bool is_in_check(bool);
private:
    void draw(Move);
    void Promotion(Piece*);
};


class Move
{
public:
    Piece* piece;
    int square[2];
    int evaluation;
    Move* next;
    Move(){}
    Move(Piece* p, int, int, bool);
    bool operator== (Move&);
    bool is_Legal(Board&, bool);
private:
    bool capture;
};


class List
{
public:
    Move* first;
    Move* last;
    int size;
    void push_back(Move *);
    List();
};


class Node
{
public:
    List moves;
    vector<Node*> next;
    Move Best_Move(bool);
    void evaluate(bool, int, Board&);
};


bool valid_square(int i, int j);
void Liberer();
