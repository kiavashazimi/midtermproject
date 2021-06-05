#include "maze.h"




Maze::Maze(size_t _a, size_t _b): a{_a},b{_b}
{
    map=new Node*[2*a-1];

    for (size_t i=0 ; i < (2*a-1);i++)
    {
        map[i]=new Node[2*b-1];
        for (size_t j=0 ; j<(2*b-1);j++)
        {
        

            if (j%2==1 || i%2==1)
            {
            map[i][j].Type=1;
            map[i][j].visited=1;
            
            }
            else
            {
            map[i][j].Type=0;
            map[i][j].visited=0;
            
            }
            
            
        }
        
        std::cout<<std::endl;
    }

    map[2*a-2][2*b-2].goal=1;

    std::vector<size_t> movement{};
    std::vector<size_t> Move{};
    size_t x=0;
    size_t y=0;
    size_t k=0;
    size_t z{0};
    size_t q{0};
    map[0][0].visited=1;
    srand((unsigned) time(0));

    while (full())
    {
    if(cgu(y,x))
    movement.push_back(0);

    if(cgr(y,x))
    movement.push_back(1);

    if(cgl(y,x))
    movement.push_back(2);

    if(cgd(y,x))
    movement.push_back(3);

    if (movement.size()>0)
    {

    z=rand()%movement.size();
    maketree(y,x,movement[z]);
    Move.push_back(movement[z]);
    moveno(y,x,movement[z]);
    }
    else
    {
    Move.pop_back();
    q=*(Move.end());

    moveno(y,x,3-q);
    }


    movement.erase( movement.begin(), movement.end() );
    k++;
    }






    std::cout<<std::endl;
    std::cout<<std::endl;
    root=&(map[0][0]);
}










    void Maze::disp()
    {
    size_t x1{0};
    size_t x2{0};
    map[x1][x2].Type=3;
    for (size_t o=0;o<(solution.size());o++)
    {
    moveno(x1,x2,solution[solution.size()-1-o]);
    map[x1][x2].Type=3;
    }

    for (size_t i=0 ; i < 2*a-1;i++)
    {
        for (size_t j=0 ; j<2*b-1;j++)
        {
        if (map[i][j].Type==0)
        std::cout<< "( )";
        if (map[i][j].Type==1)
        {
        //std::cout<< "||   ";
        if (i%2==1 && j%2==1)
        std::cout<< "-:-";
        if(i%2==0 && j%2==1)
        std::cout<< " | ";
        if(i%2==1 && j%2==0)
        std::cout<< "---";
        
        



        }

        if (map[i][j].Type==2)
        std::cout<< "   ";


        if (map[i][j].Type==3)
        std::cout<< "(+)";


        if (map[i][j].Type==5)
        std::cout<< "(0)";
        
        
        }
        std::cout<<std::endl;
    }

}





void Maze::moveno (size_t& i,size_t& j,size_t z)
{
if (z==3)
{
map[i+1][j].Type=2;
map[i+2][j].visited=1;
i+=2;
  
}

else if (z==0)
{
map[i-1][j].Type=2;
map[i-2][j].visited=1;
i-=2;
  
}

else if (z==1)
{
map[i][j+1].Type=2;
map[i][j+2].visited=1;
j=j+2;

  
}

else
{
map[i][j-1].Type=2;
map[i][j-2].visited=1;
j=j-2;
} 

}


bool Maze::full ()
{
for (size_t i=0 ; i < (2*a-1) ;i++)
{
        for (size_t j=0 ; j<(2*b-1);j++)
        {
        

            if (!(j%2==1 || i%2==1))
            {
            
            if (map[i][j].visited==0)
            return 1;
            }
            
        }


}
return 0;
}


Maze::~Maze()
{
    for (size_t i=0;i<(2*a-1);i++)
    delete[] map[i];

    delete[] map;
}


int Maze::dfs(Node* now)
{

size_t q{0};
if (now->children.size())
{
for (size_t u=0;u<now->children.size();u++)
{
now->children[u]->Type=5;
if (now->children[u]->goal==1)
{
solution.push_back(now->moVe[u]);
allmove.push_back(now->moVe[u]);
return 1;
}
if(dfs(now->children[u])==1)
{
solution.push_back(now->moVe[u]);
allmove.push_back(now->moVe[u]);
return 1;
}
else
{
    q++;
}
}
}
else
{
    return 0;
}
if(now->children.size()==q)
{
return 0;
}
std::cout<<std::endl;
return 0;
}


int Maze::bfs(std::vector<Node*> level)
{
    std::vector<Node*> nextlevel;
    for (size_t i=0;i<level.size();i++)
    {
        
        if (level[i]->goal==1)
        {
        bfsp.push_back(level[i]);
        solution.push_back(level[i]->value);
        
        //return level[i];
        return 1;
        }
        else
        {
          level[i]->Type=5;
        }
        if (level[i]->children.size()>0)
        {
            for(size_t j=0;j<level[i]->children.size();j++)
            nextlevel.push_back(level[i]->children[j]);
        }
    }
    bfs(nextlevel);
    if(level[0]!=root)
    {
    solution.push_back(bfsp[bfsp.size()-1]->parent->value);
    bfsp.push_back(bfsp[bfsp.size()-1]->parent);
    }

    return 0;
}


void Maze::maketree(size_t i,size_t j,size_t z)
{
if (z==0)
{
map[i][j].children.push_back(&(map[i-2][j]));
map[i-2][j].parent=&(map[i][j]);
map[i-1][j].Type=2;
map[i][j].visited=1;
map[i][j].moVe.push_back(0);
map[i-2][j].value=0;
}
else if(z==1)
{
map[i][j].children.push_back(&(map[i][j+2]));
map[i][j+2].parent=&(map[i][j]);
map[i][j].moVe.push_back(1);
map[i][j+2].value=1;
map[i][j+1].Type=2;
map[i][j].visited=1;
}
else if(z==2)
{
map[i][j].children.push_back(&(map[i][j-2]));
map[i][j-2] .parent=&(map[i][j]);
map[i][j].moVe.push_back(2);
map[i][j-2] .value=2;
map[i][j-1].Type=2;
map[i][j].visited=1;
}
else
{
map[i][j].children.push_back(&(map[i+2][j]));
map[i+2][j].parent=&(map[i][j]);
map[i][j].moVe.push_back(3);
map[i+2][j].value=3;
map[i+1][j].Type=2;
map[i][j].visited=1;
}

}




void Maze::erase()
{

solution.erase( solution.begin(), solution.end());
bfsp.erase(bfsp.begin(),bfsp.end());
allmove.erase(allmove.begin(),allmove.end());
for (size_t i=0 ; i < (2*a-1);i++)
{

    for (size_t j=0 ; j<(2*b-1);j++)
    {
    

        if (map[i][j].Type==5||map[i][j].Type==3)
        {
            
            map[i][j].Type=0;
        }
        
        
        
    }
    
    std::cout<<std::endl;
}


}