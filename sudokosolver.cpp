
#include <iostream>
 
using namespace std;
 
// 9X9 sudoku
#define N 9
int arr[N][N];

void input(){
    for (int i = 0; i < N; i++) 
    {  
        for (int j = 0; j < N; j++){
            cin>> arr[i][j];   
               
                   }
        
    }

    
}

void print()
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
 

bool isValid( int row, int col, int num)
{
     
    //case 1 column hit 
    for (int x = 0; x <= 8; x++)
        if (arr[row][x] == num)
            return false;
 
    // case2 row hit
    for (int x = 0; x <= 8; x++)
        if (arr[x][col] == num)
            return false;
 
    // case 3 hit by same 3*3 block 
    int startRow = row - row % 3, startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (arr[i + startRow][j + startCol] == num)
                return false;
 
    return true;
}
 

bool solveSuduko(int row, int col)
{
    //terminate case
    if (row == N - 1 && col == N)
        return true;
 
    //shifting to new row
    if (col == N) {
        row++;
        col = 0;
    }
   
    // for already filled element
    if (arr[row][col] > 0)
        return solveSuduko( row, col + 1);
 
    for (int num = 1; num <= N; num++) 
    {
         
        // Check if it is valid
        if(isValid( row, col, num)) 
        {
             
           
            arr[row][col] = num;
           
            
            if(solveSuduko( row, col + 1))
                return true;
        }
       
       
        arr[row][col] = 0;
    }
    return false;
}
 
// Driver Code
int main()
{
    cout<<"please provide space b/w to element and 0 incase if block is empty"<<endl;
   input();
   cout<<"your answer is..."
 
    if (solveSuduko( 0, 0))
        print();
    else
        cout << "invalid problem" << endl;
 
    return 0;
    
}


