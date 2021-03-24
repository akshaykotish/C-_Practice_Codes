class Solution {
public:
    
    vector<vector<int>> temp;
    bool rot = false;
    int count = 0;
    int ones = 0;
    
    bool flag = false;
    
    bool Check(int i, int j){
        flag = false;
        
        if(temp[i][j] == 1)
        {
            if(0<=i-1 && i-1<temp.size() && temp[i-1][j] == 2)
            {
                 flag = true;
            }
            if(0<=i+1 && i+1<temp.size() && temp[i+1][j] == 2)
            {
                 flag = true;
            }
            if(0<=j+1 && j+1<temp[0].size() && temp[i][j+1] == 2)
            {
                 flag = true;
            }
            if(0<=j-1 && j-1<temp[0].size() && temp[i][j-1] == 2)
            {
                 flag = true;
            }
            ones++;
        }
        
        return flag;
    }
    
    void Rotting(int i, int j){
         rot = false;
        if(temp[i][j] == 2)
        {
            if(0<=i-1 && i-1<temp.size() && temp[i-1][j] == 1)
            {
                temp[i-1][j] = 2;
                 rot = true;
            }
            if(0<=i+1 && i+1<temp.size() && temp[i+1][j] == 1)
            {
                temp[i+1][j] = 2;
                 rot = true;
            }
            if(0<=j+1 && j+1<temp[0].size() && temp[i][j+1] == 1)
            {
                temp[i][j+1] = 2;
                 rot = true;
            }
            if(0<=j-1 && j-1<temp[0].size() && temp[i][j-1] == 1)
            {
                temp[i][j-1] = 2;
                 rot = true;
            }
            
            if(rot == true)
            {
                count = 0;
                ones = 0;
            }
        }
        
        
    }
    
    void Display(vector<vector<int>>& grid)
    {
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
             cout<<grid[i][j]<<" ";   
            }
            cout<<endl;
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
            
        int minute = 0;
        int n = grid.size() * grid[0].size();
        
        
        int i = 0;
        int j = 0;
        
        temp = grid;
        
        count = 0;
        cout<<n<<endl;
        while(count<n)
        {
            
            if(!Check(i, j))
            {
                count++;
            }
            
            if(grid[i][j]==2)
            {
                Rotting(i, j);
            }
            
            if(j == grid[0].size()-1)
            {
                i++;
                j=-1;
            }
            
            if(i==grid.size())
            {
                i=0;
                j=-1;
                
                if(count != n)
                {
                    minute++;
                    grid = temp;
                    //cout<<"Grid at minute: "<<minute<<" and count: "<<count<<endl;
                    //Display(grid);
                    count = 0;
                }
            }
            j++;
        }
        
        if(ones != 0)
        {
            minute = -1;
        }
        
        return minute;
    }
};
