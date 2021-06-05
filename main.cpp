#include<iostream>
#include<vector>
#include<math.h>
#include <list>
#include "maze.h"


int main()
{

  Maze maze1{8,8};
  maze1.dfs(maze1.root);

  
  maze1.disp();


  std::cout<<std::endl; 
  std::cout<< std::endl;
  maze1.erase();
  std::vector<Maze::Node*> le{&(maze1.map[0][0])};
  maze1.bfs(le);

  maze1.disp();


  std::cout<<std::endl; 
  std::cout<< std::endl;
  return 0;
}

