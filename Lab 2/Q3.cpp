#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

void fillMatrix(int** &matrix, int row, int col){
    matrix=new int*[row];
    for(int i=0;i<row;i++){
     matrix[i]= new int[col];
    }
    
    for(int i=0;i<row;i++)
    {
        for(int j=0; j<col;j++){
            matrix[i][j]=rand()%100+1;
        }
    }
}

int matrixSum(int **matrix, int rows, int cols){
    int sum=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0; j<cols;j++){
          sum+=matrix[i][j];
        }
     }
     return sum;
}

void rowSum(int **matrix, int rows, int cols)
{
    cout<<"row sum: ";
      for (int i = 0; i < rows; ++i)
        {int colSum = 0;
        for (int j = 0; j < cols; ++j)
       {
            colSum += matrix[i][j];  
        }
        cout << colSum << " ";  
    }
    cout << endl;   
}

void colSum(int **matrix, int row, int col)
{
    cout<<"column sum : "<<endl;
    for(int j=0;j<col;j++){
        int colSum=0;
        for(int i=0;i<row;i++){
           
            colSum+=matrix[i][j];
        }
        cout << colSum << " "; 
    }
    cout<<endl;

}
void highestRowSum(int**matrix, int row, int col){
    int highest=0;
    int rowIndex=0;
    
    for(int i=0;i<row;i++){
        int rowSum=0;
        for(int j =0;j<col;j++){
            rowSum+=matrix[i][j];}
        if(rowSum>highest){
           rowIndex=i;
           highest=rowSum; 
           }
        
    }
    cout<<"row with highest sum is row #"<<rowIndex<<"with sum: "<<highest<<endl;

}
void highestColSum(int**matrix, int row, int col){
    int highest=0;
    int colIndex=0;
    
    for(int j=0;j<col ;j++){
        int colSum=0;
        for(int i =0;i<row;i++){
            colSum+=matrix[i][j];}
        if(colSum>highest){
           colIndex=j;
           highest=colSum; 
           }
        
    }
    cout<<"column with highest sum is column #"<<colIndex<<"with sum: "<<highest<<endl;

}

void transpose(int **matrix, int row , int col){
    cout<<" transposed matrix :"<<endl;
    
    for(int j=0;j<col ;j++) {
      for(int i =0;i<row;i++){
        cout<<matrix[i][j]<<" ";
     }
     cout<<endl;
    }
}

void freememo(int **matrix, int row){
    for(int i=0;i<row ;i++){
        delete[]matrix[i];
    }
    delete[]matrix;
}


int main() {
    srand(time(0));
    int row =3, col=3;
int **matrix= nullptr;
fillMatrix(matrix,row,col);
cout<<"original matrix"<<endl;
  for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << matrix[i][j] << " ";
        }
  cout<<endl;
  }

cout<<"sum of all elements"<< matrixSum(matrix, row, col)<<endl;
rowSum(matrix, row, col);
colSum(matrix, row, col);
highestColSum(matrix, row, col);
highestRowSum(matrix, row, col);
transpose(matrix, row, col);
freememo(matrix, row);

return 0;
}

