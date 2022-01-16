/*

	1 0 0
	1 0 0
	1 9 0


*/


#include <iostream>
#include <stack>

using namespace std;

class Cell{
	public:
	int x;
	int y;
	int d;
};

class Robot{
	public:
		
		int M;
		int N;
		int **MAZE;
		int **Passed;
		
		bool solved;
		stack<Cell> cells;
			
		Cell curr;
		
		Robot(){
			
			M = 5;
			N = 5;
			
			MAZE = new int*[M];
			Passed = new int*[M];
			
			for(int i=0; i<M; i++)
			{
				MAZE[i] = new int[N];
				Passed[i] = new int[N];
				
				for(int j=0; j<N; j++)
				{
					Passed[i][j] = 0;
				}
			}
			
			MAZE[0][0] = 1; MAZE[0][1] = 1; MAZE[0][2] = 1; MAZE[0][3] = 1; MAZE[0][4] = 0;
			MAZE[1][0] = 0; MAZE[1][1] = 1; MAZE[1][2] = 1; MAZE[0][3] = 1; MAZE[0][4] = 0;
			MAZE[2][0] = 0; MAZE[2][1] = 1; MAZE[2][2] = 1; MAZE[0][3] = 1; MAZE[0][4] = 0;
			MAZE[3][0] = 0; MAZE[3][1] = 1; MAZE[3][2] = 1; MAZE[3][3] = 1; MAZE[3][4] = 0;
			MAZE[4][0] = 0; MAZE[4][1] = 1; MAZE[4][2] = 9; MAZE[4][3] = 1; MAZE[4][4] = 0;
			
			solved = false;
			
			
		}
		
		bool Target_Found(){
			if(curr.x - 1 > -1 && MAZE[curr.x - 1][curr.y] == 9)
			{
				curr.d++;
				return true;
			}
			else if(curr.y - 1 > -1 && MAZE[curr.x][curr.y - 1] == 9)
			{
				curr.d++;
				return true;
			}
			else if(curr.x + 1 < M && MAZE[curr.x + 1][curr.y] == 9)
			{
				curr.d++;
				return true;
			}
			else if(curr.y + 1 < N && MAZE[curr.x][curr.y + 1] == 9)
			{
				curr.d++;
				return true;
			}
			
			return false;
		}
		
		
		void Solve(){
			
			
			Cell cell0;
			cell0.d = 0;
			cell0.x = 0;
			cell0.y = 0;
			curr = cell0;
			
			cells.push(cell0);
			
			//cout<<("Solving...\n");
			
			while(!cells.empty())
			{
				cout<<curr.x<<" "<<curr.y<<" "<<curr.d<<endl;
				if(MAZE[curr.x][curr.y] == 9 || Target_Found() == true)
				{
					cout<<endl<<"9 found and score is "<<curr.d<<endl;	
					 break;
				}
				else if(Passed[curr.x][curr.y] != 1 && MAZE[curr.x][curr.y] == 1)
				{
					Passed[curr.x][curr.y] = 1;	
					curr.d = cells.top().d + 1;
					
					cells.push(curr);	
					
					cout<<curr.d<<endl;
				}
				
				
				
				if(curr.x + 1 < M && Passed[curr.x+1][curr.y] != 1 && (MAZE[curr.x+1][curr.y] == 1 || MAZE[curr.x+1][curr.y] == 9))
				{
					Cell cell;
					cell.x = curr.x + 1;
					cell.y = curr.y;	
					cell.d = curr.d;
					curr = cell;
				}
				else if(curr.y + 1 < N && Passed[curr.x][curr.y + 1] != 1 && (MAZE[curr.x][curr.y + 1] == 1 || MAZE[curr.x][curr.y + 1] == 9))
				{
					Cell cell;
					cell.x = curr.x;
					cell.y = curr.y + 1;	
					cell.d = curr.d;
					curr = cell;
					
				}
				else if(curr.x - 1 > -1 && Passed[curr.x - 1][curr.y] != 1 && (MAZE[curr.x - 1][curr.y] == 1 || MAZE[curr.x - 1][curr.y] == 9))
				{
					Cell cell;
					cell.x = curr.x-1;
					cell.y = curr.y;	
					cell.d = curr.d;
					curr = cell;
					
				}
				else if(curr.y - 1 > -1 && Passed[curr.x][curr.y - 1] != 1 && (MAZE[curr.x][curr.y - 1] == 1 || MAZE[curr.x][curr.y - 1] == 9))
				{
					Cell cell;
					cell.x = curr.x;
					cell.y = curr.y - 1;	
					cell.d = curr.d;
					curr = cell;
					
				}
				else{
					cells.pop();
				}
		
			}
			
		}
		
		
};


int main(){
	
	Robot robot;
	robot.Solve();
	return 0;
}
