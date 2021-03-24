#include<iostream>
#include<vector>

class Solution {
public:
    int count =0;
    
    void Move(vector<vector<int>>& grid, int i, int j){
        if(i>=0 && i<grid.size()  && j>=0 && j<grid[0].size())
        {
            if(grid[i][j] == 2)
            {
                Move(grid, i-1, j);
                Move(grid, i+1, j);
                Move(grid, i, j-1);
                Move(grid, i, j+1);
                count++;
            }
            
            if(grid[i][j] == 1)
            {
                grid[i][j] = 2;
            }
        }
    }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
           for(int i=0; i<grid.size(); i++)
           {
               for(int j=0; j<grid[0].size(); j++)
               {
                   if(grid[i][j] == 2)
                   {
                       Move(grid, i, j);
                       break;
                   }
               }
           }
        
        bool allclear = true;
        
        for(int i=0; i<grid.size(); i++)
           {
               for(int j=0; j<grid[0].size(); j++)
               {
                   if(grid[i][j] == 1)
                   {
                       allclear= false;
                   }
               }
           }
        if(allclear == false)
        {
            count = -1;
        }
        return count;
    }
};

int main()
{
	Solution s1;
	vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};
	int c = s1.orangesRotting();
	cout<<c;
}
