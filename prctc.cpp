#include <iostream>
#include <vector>
using namespace std;

void begin(vector<vector<int> > area, int x, int y);
int **moved;
  
int lets_check(vector<vector<int> > area, int x, int y){
	if(x >=0 && x < area.size() && y>=0 && y < area[0].size())
	{
		if(moved[x][y] == 0)
		{
			return area[x][y];
		}
	}
	return 0;
}

int C_Up(vector<vector<int> > area, int x, int y)
{
	int nx = x-1;
	int ny = y;
	
	return lets_check(area, nx, ny);
}

void M_Up(vector<vector<int> > area, int x, int y)
{
	int nx = x-1;
	int ny = y;
	
	//cout<<"UP "<<nx<<" "<<ny<<endl;
	begin(area, nx, ny);
}


int C_Bottom(vector<vector<int> > area, int x, int y)
{
	int nx = x+1;
	int ny = y;
	
	return lets_check(area, nx, ny);
}

void M_Bottom(vector<vector<int> > area, int x, int y)
{
	int nx = x+1;
	int ny = y;
	
	//cout<<"Bottom "<<nx<<" "<<ny<<endl;
	begin(area, nx, ny);
}


int C_Left(vector<vector<int> > area, int x, int y)
{
	int nx = x;
	int ny = y-1;
	
	return lets_check(area, nx, ny);
}

void M_Left(vector<vector<int> > area, int x, int y)
{
	int nx = x;
	int ny = y-1;
	
	//cout<<"Left "<<nx<<" "<<ny<<endl;
	begin(area, nx, ny);
}


int C_Right(vector<vector<int> > area, int x, int y)
{
	int nx = x;
	int ny = y+1;
	return lets_check(area, nx, ny);
}

void M_Right(vector<vector<int> > area, int x, int y)
{
	int nx = x;
	int ny = y+1;
	
	//cout<<"Right "<<nx<<" "<<ny<<endl;
	begin(area, nx, ny);
}

int T = 0;
bool found =false;

void begin(vector<vector<int> > area, int x, int y){
	moved[x][y] = 1;
	if(area[x][y] == 9){
		found = true;
		//cout<<"Found!!\n";
	}
	else{
		T++;
		//cout<<"Moving => "<<T<<" & "<<x<<" "<<y<<" -> ";
		if(C_Up(area, x, y) != 0)
		{
			M_Up(area, x, y);
		}
		else if(C_Bottom(area, x, y) != 0)
		{
			M_Bottom(area, x, y);
		}
		else if(C_Left(area, x, y) != 0)
		{
			M_Left(area, x, y);
		}
		else if(C_Right(area, x, y) != 0)
		{
			M_Right(area, x, y);
		}
	}
}
  
int process(vector<vector<int> > area)
{
	begin(area, 0, 0);
	if(found == true)
	{
		return T;	
	}
	return 0;
}

int main()
{
	moved = new int*[3];
	for(int i=0; i<3; i++)
	{
		moved[i] = new int[3];
		for(int j=0; j<3; j++)
		{
			moved[i][j] = 0;
		}
	}
	
	int arr[3][3] = {
		{1, 0, 9},
		{1, 0, 1},
		{1, 1, 1}
	};    
	
	vector< vector<int> > area;
	
	for(int i=0; i<3; i++)
	{
		vector<int> v;
		for(int j=0; j<3; j++)
		{
			v.push_back(arr[i][j]);
		}
		area.push_back(v);
	}
	
	cout<<process(area);
    return 0;
}
