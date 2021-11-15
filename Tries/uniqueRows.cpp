// Print unique rows in a given boolean matrix

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}


class Trie {
    public:
    bool isLast;
    Trie* child[2];
    
    Trie (){
        isLast = false;
        for (int i =0; i < 2; i ++){
            this->child[i] = NULL;
        }
    }
};

bool insert(Trie* root,int Row, int Col,   int row, int col, int M[MAX][MAX]){
   if (col < Col ){
       if (root -> child[M[row][col]] == NULL)  root -> child[M[row][col]] = new Trie();
       insert(root -> child[M[row][col]],Row, Col, row, col+1, M );
   }
   else {
       if (!root -> isLast){
           root->isLast = true;
           return 0;
       }
       return 1;
   }
}


vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
  Trie* root = new Trie();
  vector<vector<int>> ans;
  
  for (int i =0; i < row ; i ++){
   
     if (! insert(root,row, col,  i, 0, M)){
         vector<int> unique_row;
          for (int j =0; j < col; j ++)
                unique_row.push_back(M[i][j]);
        ans.push_back(unique_row);
     }
  }
  
   return ans;
}