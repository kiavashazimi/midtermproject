#ifndef VEC_H
#define VEC_H

#include<iostream>
#include<vector>
#include<math.h>
#include<memory>
#include <list>




class Maze
{
public:






class Node {
    public:

    size_t value{0};
    size_t Type{};
    bool visited;
    Node* parent{nullptr};
    std::vector<Node*> children;
    std::vector<size_t> moVe;
    size_t goal{0};




    private:

};



Maze(size_t _a, size_t _b);
~Maze();

size_t a;
size_t b;
size_t y{0};
size_t x{0};
std::vector<size_t> solution;
std::vector<Node*> bfsp;
std::vector<size_t> allmove;
Node**  map;
Node* root;







bool cgu (size_t i,size_t j)
{
if (i == 0  || map[i-2][j].visited==1)
return 0;

return 1;

}

bool cgr (size_t i,size_t j)
{
if (j==(2*b-2) || map[i][j+2].visited==1)
return 0;

return 1;
}

bool cgl (size_t i,size_t j)
{
if ( j==0 || map[i][j-2].visited==1)
return 0;

return 1;
}

bool cgd (size_t i,size_t j)
{
if (i==(2*a-2) || map[i+2][j].visited==1 )
return 0;

return 1;   
}


void moveno (size_t& i,size_t& j,size_t z);
bool full ();
int dfs(Node*);
int bfs(std::vector<Node*>);
void disp();
void maketree(size_t,size_t,size_t);
void erase();

private:





};





#endif