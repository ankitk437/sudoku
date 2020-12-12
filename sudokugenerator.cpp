#include <iostream>
#include <time.h> 
#include <stdlib.h>
#include "./helper.cpp"



using namespace std;


int arr2[N][N];
int K;

//  9X9 blocks
#define N 9
//int arr[N][N];
void copy()
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            arr2[i][j]=arr[i][j]; 
        
    }
}

void print()
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            cout << arr2[i][j] << " ";
        cout << endl;
    }
}


void suffleArray(int arr1[], int n)  
{  
    
    for (int i = n - 1; i > 0; i--)  
    {  
        
        int j = rand() % (i + 1);  
  
        swap(arr1[i], arr1[j]);  
    }  
}


int main(){
	srand (time(NULL));
	
	int auxArr[]={1,2,3,4,5,6,7,8,9};
	
	
	for (int i=0; i<3;i++){
		
		suffleArray(auxArr,9);
		int counter=0;
		
		for(int j=3*i; j<3*(i+1) ;j++){
			
			for(int k=3*i; k<3*(i+1) ;++k){
				arr[j][k]=auxArr[counter++];
				
				
				
				}
			}
		
		
		
		
		}
	solveSuduko(0,0);
	
	cout<<"enter number of elemnt you want to keep on board (MIN =17 )";
	
	
	cin>>K;
	
	
	do{  for(int i=0 ; i<N*N-K ;i++){
			  int row=rand() % 10 ;
			  int col=rand() % 10 ;
			  if(arr[row][col]==0){ 
				  i--;
				  }
			  else{ arr[row][col]=0; }
			  
			
			copy();
			
			}
			
			
			
			
		}while(!solveSuduko(0,0)); 
	print();
	
	
	
	
	}
