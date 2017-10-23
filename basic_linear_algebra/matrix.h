#ifndef matrix_H //Include guard
#define matrix_H
#include<iostream>
#include<stdlib.h>
//#include "vector.h"

using namespace std;

//matrix class
/******************************************************************************************************************/
/******************************************************************************************************************/
template <typename T, int row, int column>   //row by column
class matrix
{
	public:
  

	
	T operator()(const int i, const int j) const {return mat2[i*column + j];}//{return mat2[i*column+j];}
	T& operator()(const int i,const int j) {return mat2[i*column + j];}//{return mat2[i*column+j];}	

	void clear(); //clear function
	void copyOther(const matrix &other);//copy function	
		
	matrix(); //CONSTRUCTOR	
	~matrix(); //DESTRUCTOR	

	matrix(const matrix &other) // Copy constructor
	{
	copyOther(other);
//      	cout<<"matrix copy constructor invoked "<<endl;			
	}
	
	matrix & operator =(const matrix & other) // Assn. operator
	{	if(this != &other)
		{
			clear();
			copyOther(other);
//      			cout<<"matrix assignment operator invoked "<<endl;								
		}
	return (*this);
	}

	
private:
	T *mat2 ;


	

};


	template<typename T, int row, int column>  
	void matrix<T,row,column>::clear() //clear function
	{
        free(mat2);
//  	delete [] mat2;
	    mat2 = NULL;
	}
	
	template<typename T, int row, int column>  
	void matrix<T,row,column>::copyOther(const matrix &other)//copy function
	{
			mat2 = new T [row*column]; 
			for(int i=0;i<row*column;i++)
			{
				mat2[i]=other.mat2[i];
			}
	}
	
	template<typename T, int row, int column> 
	matrix<T,row,column>::matrix() //CONSTRUCTOR
	{
//        cout << "matrix Constructor invoked: " << endl;
		mat2 = new T[row*column];
		for(int i=0;i<row*column;i++)
		{mat2[i]= 0;}
	}

	template<typename T, int row, int column> 
	matrix<T,row,column>::~matrix()//DESTRUCTOR
	{
//		clean up allocated memory
		clear();
//		delete [] mat2;
//		mat2 = NULL;
//	cout << "matrix Destructor invoked: " << endl;
	}


	template<typename T, int row, int column> //overloading output operator 
	std::ostream & operator<<  (std::ostream& os, matrix<T,row,column> &mymatrix)
	{	
		int i,j;
		for(i=0;i<row;i++)
		{	
			for(j=0;j<column;j++)
			{
			//std::cout<<'\t';
			os<<mymatrix(i,j);
			std::cout<<'\t';
			}
			std::cout<<'\n';
		}
	
	return os;
	}

	template<typename T, int row, int column>  //overloading input operator 
	std::istream & operator>>  (std::istream& is, matrix<T,row,column> &mymatrix)
	{	
		int i,j;
		for(i=0;i<row;i++)
		{	
			
			for(j=0;j<column;j++)
			{	
			is>>mymatrix(i,j);
			}
		std::cout<<'\n';	
		}
	return is;
	}

	
	template<typename T, int row, int column> //overloading + operator 
	matrix<T,row,column> operator+  ( matrix<T,row,column> &a, matrix<T,row,column> &b)
	{
	int i,j;
	matrix<T,row,column> answer;
		for(i=0;i<row;i++)
		{	
			for(j=0;j<column;j++)
			{
			answer(i,j)=a(i,j)+b(i,j);
			}	
		
		}
	return answer;
	}

	
	template<typename T, int row, int column> //overloading - operator 
	matrix<T,row,column> operator-  ( matrix<T,row,column> &a, matrix<T,row,column> &b)
	{
	int i,j;
	matrix<T,row,column> answer;
		for(i=0;i<row;i++)
		{	
			for(j=0;j<column;j++)
			{
			answer(i,j)=a(i,j)-b(i,j);
			}	
		
		}
	return answer;
	}


	
	template<typename T, int row1, int column1, int row2, int column2> //overloading * operator 
	matrix<T,row1,column2> operator*  ( matrix<T,row1,column1> &a, matrix<T,row2,column2> &b)
	{
	int i,j,k,c1,c2,r1,r2;
	matrix<T,row1,column2> answer;

		if(column1!=row2)
        	{std::cout<<"matrix multiplication invalid. number of columns of A must be equal to number of rows of B"<<std::endl;}
	
		else
		{
			for(i=0;i<row1;i++)
			{
				for(k=0;k<column2;k++)
				{
					answer(i,k)=0;
					for(j=0;j<column1;j++)
					{
					answer(i,k)=answer(i,k)+a(i,j)*b(j,k);
					}
				}
			
			}
		}
	return answer;
	}

/*
//matrix-VECTOR MULTIPLICATION

	template<typename T, int row1, int column1, int row2> //overloading * operator 
	vect<T,row2> operator*  ( matrix<T,row1,column1> &a, vect<T,row2> &b)
	{
	int i,j,k,c1,c2,r1,r2;
	vect<T,row2> answer;

		if(column1!=row2)
        	{std::cout<<"matrix-vector multiplication invalid. number of columns of A must be equal to number of rows of B"<<std::endl;}
	
		else
		{
			for(i=0;i<row1;i++)
			{
				
					answer[i]=0;
					for(j=0;j<column1;j++)
					{
					answer[i]=answer[i]+a(i,j)*b[j];
					}
				
			
			}
		}
	return answer;
	}

*/
//SYMMETRIC matrix FLAG 
	template<typename T, int row, int column>
	bool symFlag  ( matrix<T,row,column> &a)
	{
		bool flag=1;	
		int i,j;
		for(i=0;i<row;i++)
		{	
			for(j=0;j<column;j++)
			{
				if(a(i,j)==a(j,i))
				{
				flag=flag*1;
				}	
				else
				{
				flag=flag*0;
				}
			}
		}
	return flag;
	}

	
//TRANSPOSE OF A MATRIX
	template<typename T, int row, int column>
	matrix<T,row,column> Transpose (matrix<T,row,column> &a)
	{
	int i,j;
	matrix<T,row,column> answer;
		for(i=0;i<row;i++)
		{	
			for(j=0;j<column;j++)
			{
			answer(i,j)=a(j,i);
			}	
		
		}
	return answer;
	}
/******************************************************************************************************************/
/******************************************************************************************************************/
#endif
