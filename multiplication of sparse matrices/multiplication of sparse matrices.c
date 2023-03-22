#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX_TERM 101
#define _K 4    
#define _L 4
#define _M 4  



 


//struct definition
struct data
{
 int row;
 int column;
 int value;
} ;



void transpose(struct data compact_matrix[MAX_TERM] ,int count){  //takes the transpose of a compact matrix
	
	int tempr ;
	
	//replacing the row and column values in each index with each other.
	for(int i=1 ; i<count ; i++){
	tempr = compact_matrix[i].row;   
	compact_matrix[i].row = compact_matrix[i].column;
	compact_matrix[i].column = tempr;
    }
    
}




void sortedarray(struct data compact_matrix[],int count, struct data temp){      //sorting elements in a compact matrix by row and column values
	
	//sorting
	for(int i=0;i<count;i++){
	
        for(int j = 1 ; j<count-1 ; j ++){
        	
        	// sorting by row
    	    if(compact_matrix[j].row>compact_matrix[j+1].row){ 
    		    temp = compact_matrix[j];
    		    compact_matrix[j] = compact_matrix[j+1];
    		    compact_matrix[j+1] = temp;
		    }
		    
		    // if the row values are equal, sorting elements by column
		    if(compact_matrix[j].row== compact_matrix[j+1].row){  
		    	if(compact_matrix[j].column > compact_matrix[j+1].column){
		    		temp = compact_matrix[j];
    		        compact_matrix[j] = compact_matrix[j+1];
    		        compact_matrix[j+1] = temp;
				}
			}
			
	    }
	    
    }
}



//to convert matrixes to compact form
int compact_matrix(int sparse_matrix_1[][4], int row , struct data compact_matrix_1[MAX_TERM]){   // reference of this function : homework slide
	
	int count = 1 ;
    compact_matrix_1[0].row = 4;
    compact_matrix_1[0].column = 4;
 
//in turn, each element of the array is accessed, and elements that are not equal to zero are added to the struct array as rows, columns, and values.
    for (int i = 0; i < 4; i++){
       for (int j = 0; j < 4; j++){
            if (sparse_matrix_1[i][j]!=0){
                compact_matrix_1[count].row = i;
                compact_matrix_1[count].column = j;
                compact_matrix_1[count].value = sparse_matrix_1[i][j];
                count++;
            }
        }
    }
    compact_matrix_1[0].value = count-1;
	return count;    // to determine count1,count2,count3
}





int multiply(struct data compact_matrix_1[] , struct data compact_matrix_2[] , struct data result_matrix[] , int count1 , int count2){  
	// reference : https://youtu.be/x70zNUIHR0k   There is no code in this video. I wrote the code myself using the algorithm here.
	
	int count3=1;   
	bool isthere = false;  
	
	
	
	result_matrix[0].row= _K;  //equal to the number of rows of sparse matrix 1
	result_matrix[0].column = _M; //equal to the number of columns of matrix 2.
	
	
	
	//in multiplication, we compare each element of the two matrices with each other. 
	for(int i=1 ; i<count1 ; i++){
		for(int j=1 ; j<count2 ; j++){
			
			
			
		    if(compact_matrix_1[i].column == compact_matrix_2[j].column){ // if the column values in the indices are equal
		    
		    
		    	for(int k=1; k<count3;k++){
		    		
		    		
		    		if(compact_matrix_1[i].row==result_matrix[k].row && compact_matrix_2[j].row == result_matrix[k].column){/*if there is an element in the result matrix that has the row and column values of the struct element that we will add, 
					the value of the struct element that we will add is added to the value in the result matrix.*/
		    			
		    			result_matrix[k].value = result_matrix[k].value+ compact_matrix_1[i].value * compact_matrix_2[j].value;
		    		    isthere=true;
		    		    
		    		    //the index does not increase
					}
				}
		
				
				if(isthere==false){
		    	result_matrix[count3].row = compact_matrix_1[i].row;   //	the row of the first matrix is equal to the row of the result matrix
		    	result_matrix[count3].column = compact_matrix_2[j].row;   // the row of the second matrix is equal to the column of the result matrix.
		    	result_matrix[count3].value = compact_matrix_1[i].value * compact_matrix_2[j].value;   // and the multiplication of the values of matrixes gives the value of the result matrix.
		    	count3++;  //the index increase
		        }
		    
		        isthere =false;
		        
		        
			}
			
			
			
			
		}
	}
	
	
	result_matrix[0].value = count3 -1;	  //number of elements in result matrix
	
	return count3;
	
}





void print(struct data compact_matrix[MAX_TERM],int count) //reference: homework slide
{
 
 
 //printing row , column and value values for all indexes in the struct array to the screen
 for (int i = 0; i < count; i++)
 {
   printf("%d\t %d\t %d \n",compact_matrix[i].row, compact_matrix[i].column, compact_matrix[i].value); 
 
 } 
}





int main(){
	
	
	
	struct data compact_matrix_1[MAX_TERM]; //struct array definition to convert matrix 1 to compact matrix
    struct data compact_matrix_2[MAX_TERM]; //struct array definition to convert matrix 2 to compact matrix
    struct data result_matrix[MAX_TERM];    //struct array definition for matrix 1 and matrix 2 multiplication 
    struct data temp;   
    int count1;   //number of elements of the compact_matrix_1
    int count2;   //number of elements of the compact_matrix_2
    int count3;   //number of elements of the result_matrix


    int sparse_matrix_1[_K][_L] = { {5, 10, 0, 5 }, {0 , 2 , 4 , 0 }, {0 , 3 , 0 , 3 },{0, 3, 0, 0 } };  //sparse matrix 1
    int sparse_matrix_2[_L][_M] = { {0, 3, 1, 2 }, {0 , 0, 3 , 0 }, {0 , 0 , 8 , 0 }, {5 , 0 , 0 , 0 } };   //sparse matrix 2

    count1 = compact_matrix(sparse_matrix_1, _K, compact_matrix_1);  
    count2 = compact_matrix(sparse_matrix_2, _L, compact_matrix_2);   
    
    // compact matrix 1, compact matrix 2, count1 , count2 is determined. 
    
    
    
    
    printf("MATRIX 1:\nRow\tColumn\tValue\n");
    print(compact_matrix_1,count1);   //printing compact matrix 1
    
    transpose(compact_matrix_2, count2);   //taking transpose of matrix 2
    sortedarray(compact_matrix_2 , count2 ,temp);  //sorting compact matrix 2 by row and column values
    
    
    printf("TRANSPOSE OF MATRIX 2:\nRow\tColumn\tValue\n");
    print(compact_matrix_2,count2);  //printing new compact matrix 2
    
    
    count3 = multiply(compact_matrix_1 , compact_matrix_2 , result_matrix , count1 ,count2 ) ; //multiplication of these two matrixes
    sortedarray(result_matrix , count3 , temp );  // sorting result matrix
    
    
	printf("SPARSE MATRIX MULTIPLICATION:\nRow\tColumn\tValue\n");
    print(result_matrix ,count3); //printing result matrix
    
    
    
 
   return 0;
}



