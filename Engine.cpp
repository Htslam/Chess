
#include "Engine.h"
#include <stdlib.h>
#include <time.h>






bool valid_square(int i, int j)
{
    return(i>=0 && i<8 && j>=0 && j<8);
}

Piece::Piece(int i, int j, bool c)
{
    using namespace sf;

    coord[0] = i;
    coord[1] = j;
    color = c;
    Texture* t1 = new Texture;
    Image img;
    img.loadFromFile("images/pieces.png");
    img.createMaskFromColor(Color(255,0,0),0);
    t1->loadFromImage(img);
    spr.setTexture(*t1);
}

int Piece::getvalue()
{
    return value;
}

King::King(int i , int j, bool c) : Piece(i, j, c)
{
    value = 1000;
    type = 'K';

    int y = (c == white) ? 0: 1;
    spr.setTextureRect( sf::IntRect(15,sizespr*y,sizespr,sizespr) );
    spr.setPosition(sizespr*j,sizespr*i);
}

Queen::Queen(int i , int j, bool c) : Piece(i, j, c)
{
    value = 9;
    type = 'Q';
    int y = (c == white) ? 0: 1;
    spr.setTextureRect( sf::IntRect(sizespr+10,sizespr*y,sizespr,sizespr) );
    spr.setPosition(sizespr*j,sizespr*i);
}

Rook::Rook(int i , int j, bool c) : Piece(i, j, c)
{
    value = 5;
    type = 'R';
    int y = (c == white) ? 0: 1;
    spr.setTextureRect( sf::IntRect(sizespr*4,sizespr*y,sizespr,sizespr) );
    spr.setPosition(sizespr*j,sizespr*i);
}

Knight::Knight(int i , int j, bool c) : Piece(i, j, c)
{
    value = 3;
    type = 'N';
    int y = (c == white) ? 0: 1;
    spr.setTextureRect( sf::IntRect(sizespr*3,sizespr*y,sizespr,sizespr) );
    spr.setPosition(sizespr*j,sizespr*i);
}

Bishop::Bishop(int i , int j, bool c) : Piece(i, j, c)
{
    value = 3;
    type = 'B';
    int y = (c == white) ? 0: 1;
    spr.setTextureRect( sf::IntRect(sizespr*2,sizespr*y,sizespr,sizespr) );
    spr.setPosition(sizespr*j,sizespr*i);
}

Pawn::Pawn(int i , int j, bool c) : Piece(i, j, c)
{
    value = 1;
    type = 'P';
    int y = (c == white) ? 0: 1;
    spr.setTextureRect( sf::IntRect(sizespr*5 - 15,sizespr*y,sizespr,sizespr) );
    spr.setPosition(sizespr*j,sizespr*i);
}

Move::Move(Piece* p, int i, int j, bool b)
{
    piece = p;
    square[0] = i;
    square[1] = j;
    capture = b;
    next = NULL;
}


Board::Board()
{
    for(int i = 0; i < 8; i++)
    position[1][i] = new Pawn(1, i, 0);
    for(int i = 0; i < 8; i++)
    position[6][i] = new Pawn(6, i, 1);

    position[0][0] = new Rook(0, 0, 0);
    position[0][1] = new Knight(0, 1, 0);
    position[0][2] = new Bishop(0, 2, 0);
    position[0][3] = new Queen(0, 3, 0);
    position[0][4] = new King(0, 4, 0);
    position[0][5] = new Bishop(0, 5, 0);
    position[0][6] = new Knight(0, 6, 0);
    position[0][7] = new Rook(0, 7, 0);

    position[7][0] = new Rook(7, 0, 1);
    position[7][1] = new Knight(7, 1, 1);
    position[7][2] = new Bishop(7, 2, 1);
    position[7][3] = new Queen(7, 3, 1);
    position[7][4] = new King(7, 4, 1);
    position[7][5] = new Bishop(7, 5, 1);
    position[7][6] = new Knight(7, 6, 1);
    position[7][7] = new Rook(7, 7, 1);

    for(int i = 2; i < 6; i++)
        for(int j = 0; j < 8; j++)
        position[i][j] = NULL;


    sf::Texture* t = new sf::Texture;
    t->loadFromFile("images/board.png");

    spr.setTexture(*t);

}



void Board::play (Move m)
{
    draw(m);

    if(!valid_square(m.square[0], m.square[1])) return;
    position[m.piece->coord[0]][m.piece->coord[1]] = NULL;
    position[m.square[0]][m.square[1]] = m.piece;

    m.piece->coord[0] = m.square[0];
    m.piece->coord[1] = m.square[1];

    if( m.piece->type == 'P' && (m.square[0]==0 || m.square[0]==7))
        Promotion(m.piece);

}


void Board::draw(Move m)
{
    int x = m.square[0];
    int y = m.square[1];

    m.piece->spr.setPosition(x*sizespr, y*sizespr);
    if(position[x][y] != NULL)  position[x][y]->spr.setPosition(-100, -100);
}



int Board::evaluation()
{
    int eval = 0;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            {
                if (position[i][j]==NULL) continue;
                if (position[i][j]->color == white) eval += position[i][j]->getvalue();
                if (position[i][j]->color == black) eval -= position[i][j]->getvalue();
            }
    return eval;
}


bool Board::is_in_check(bool color)
{
    bool is_in_check = false;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        {
            if(position[i][j] == NULL) continue;
            if(position[i][j]->color == color) continue;
            List v;
            position[i][j]->PossibleMoves(v, *this);
            Move* p = v.first;
            Move* q;
            while(p != NULL)
            {
                Piece* target = position[p->square[0]][p->square[1]];
                if(target != NULL && target->type =='K') is_in_check = true;
                p = p->next;
            }
        }
    return is_in_check;
}


List Board::LegalMoves(bool turn)
{
    List possible_moves, legal_moves;
    for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8 ; j++)
                {
                    if (position[i][j] != NULL && position[i][j] ->color == turn)
                        position[i][j] ->PossibleMoves(possible_moves, *this);
                }

    Move* p = possible_moves.first;
    while(p != NULL)
    {
        bool legal = true;
        Move* next = p->next;
        Move m = *p;
        int old_square_x = m.piece->coord[0], old_square_y = m.piece->coord[1];
        Piece* old_piece = position[m.square[0]][m.square[1]];

        position[m.square[0]][m.square[1]] = m.piece;
        position[old_square_x][old_square_y] = NULL;

        if (!is_in_check(turn))
            legal_moves.push_back(p);
        else
            legal = false;

        position[old_square_x][old_square_y] = m.piece;
        position[m.square[0]][m.square[1]] = old_piece;

        p = next;
    }

    return legal_moves;
}


List Board::PossibleMoves(bool turn)
{
    List possible_moves;
    for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8 ; j++)
                {
                    if (position[i][j] != NULL && position[i][j] ->color == turn)
                        position[i][j] ->PossibleMoves(possible_moves, *this);
                }


    return possible_moves;
}



void Board::Promotion(Piece* pawn)
{
    int i, j;
    char type;
    i = pawn->coord[0];
    j = pawn->coord[1];
    position[i][j] = new Queen(i, j, pawn->color);
}


Move Board::Best_Move(bool turn, int depth)
{
    Node N;
    N.moves = LegalMoves(turn);
    N.next = vector<Node*> (N.moves.size);

    N.evaluate(turn, depth, *this);

    Move* pointer = N.moves.first;


    return N.Best_Move(turn);
}



void Node::evaluate(bool turn, int depth, Board& b)
{
    Move* pointer = moves.first;

    if (depth == 1)
    {
        while(pointer != NULL)
        {
            Move& m = *pointer;
            int x = m.piece->coord[0];
            int y = m.piece->coord[1];
            Piece* p = b.position[m.square[0]][m.square[1]];

            m.piece->coord[0] = m.square[0];
            m.piece->coord[1] = m.square[1];
            b.position[x][y] = NULL;
            b.position[m.square[0]][m.square[1]] = m.piece;
            m.evaluation = b.evaluation();


            m.piece->coord[0] = x;
            m.piece->coord[1] = y;
            b.position[x][y] = m.piece;
            b.position[m.square[0]][m.square[1]] = p;

            pointer = pointer->next;
        }

    }
    else
    {
    int i = 0;
    while(pointer != NULL)
    {

        Move& m = *pointer;
        int x = m.piece->coord[0];
        int y = m.piece->coord[1];
        Piece* p = b.position[m.square[0]][m.square[1]];

        m.piece->coord[0] = m.square[0];
        m.piece->coord[1] = m.square[1];
        b.position[x][y] = NULL;
        b.position[m.square[0]][m.square[1]] = m.piece;

        next[i] = new Node();
        next[i]->moves = b.PossibleMoves(!turn);
        next[i]->next = vector<Node*> (next[i]->moves.size);
        next[i]->evaluate(!turn, depth-1, b);

        m.piece->coord[0] = x;
        m.piece->coord[1] = y;
        b.position[x][y] = m.piece;
        b.position[m.square[0]][m.square[1]] = p;


        int best_eval = next[i]->moves.first->evaluation;
        Move* pointer_next = next[i]->moves.first;
        while(pointer_next != NULL)
        {
            Move &m_next = *pointer_next;
            if (turn == black && m_next.evaluation > best_eval  ||   turn == white && m_next.evaluation < best_eval)
                best_eval = m_next.evaluation;

            pointer_next = pointer_next->next;
        }
        m.evaluation = best_eval;


        pointer = pointer->next;
        delete(next[i]);
        i++;
    }
    }
}


Move Node::Best_Move(bool turn)
{
    srand(time(0));
    vector<Move> candidate;


    Move* p = moves.first;
    if(p==NULL)
    {
        return Move(NULL, 0, 0, 0);
    }

    int best_eval = p->evaluation;
    candidate.push_back(*p);


    while(p != NULL)
    {
        if(p->evaluation == best_eval) candidate.push_back(*p);
        if (turn == white && p->evaluation > best_eval  ||   turn == black && p->evaluation < best_eval)
        {
            best_eval = p->evaluation;
            candidate.clear();
            candidate.push_back(*p);
        }
        p = p->next;
    }

    int random = rand() % candidate.size();


    return candidate[random];
}


bool Move::operator== (Move& m)//surcharge de ==
{
    return (square[0]==m.square[0] && square[1]==m.square[1] && piece==m.piece);
}

//verifier est si un coup est autoris�
bool Move::is_Legal(Board& b, bool turn)
{
    if (turn != piece->color) return false;
    List l;
    piece->PossibleMoves(l, b);
    Move* p = l.first;
    while(p != NULL)
    {
        if(*this == *p)
        {
        bool isLegal = false;
        int old_square_x = p->piece->coord[0], old_square_y = p->piece->coord[1];
        Piece* old_piece = b.position[p->square[0]][p->square[1]];

        b.position[p->square[0]][p->square[1]] = p->piece;
        b.position[old_square_x][old_square_y] = NULL;

        if (!b.is_in_check(turn))
            isLegal = true;

        b.position[old_square_x][old_square_y] = p->piece;
        b.position[p->square[0]][p->square[1]] = old_piece;

        return isLegal;
        }

        Move* q = p;
        p = p->next;
        //delete(q);
    }
    return false;
}



List::List()
{
    first = NULL;
    last = NULL;
    size = 0;
}


void List::push_back(Move* p)
{
    size ++;
    if(first == NULL)
    {
        first = p;
        last = p;
        first->next = NULL;
        return;
    }
    last->next = p;
    last = p;
    last->next = NULL;
}
