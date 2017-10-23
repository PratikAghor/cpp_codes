#include<iostream>
#include<fstream>
#include "math.h"
#include "matrix.h"

//1d transient heat equation 
//AUTHOR : Pratik Aghor


/*

template<typename T,int N>
double err(matrix<double,64,1> &unew, matrix<double,64,1> &uold)
{
double errorMax;
int m;
matrix<double,64,1> error;

error=unew-uold;

errorMax=error(0,0);
	if(errorMax<0)
	{
	errorMax=-errorMax;
	}

		for(m=0;m<N;m++)
		{
			if(error(m,0)<0)
			{
			error(m,0)=-error(m,0);
			}
		
			if(errorMax<error(m,0))
			{
			errorMax=error(m,0);
			}
	
		}	
return errorMax;
}
*/

int main()
{
	int i,j,k;
	int n=64;
	matrix<double,64,64> A,coeff;	
	matrix<double,64,1> uold,unew,temp1,temp2;
	double t=0,dt,tmax=2,L,d=1;

	std::cout<<"length of the rod="<<std::endl;
	std::cin>>L;
	std::cout<<"time step="<<std::endl;
	std::cin>>dt;
	
	double dx=(double)L/(double)(n-1);
	double pi=3.14157;
	//********************************************************//
	//CONSTRUCTING COEFF MATRIX (WITH d*dt/(dx*dx) as DIAGONAL ENTRIES)
	for(i=0;i<n;i++)
	{
		if(d*dt/(dx*dx)>0.5)
		{
		std::cout<<"Scheme unstable: d*dt/(dx*dx) should be < 0.5"<<std::endl;
		break;
		}
		
		else
		{
		coeff(i,i)=d*dt/(dx*dx);
		}		
	}
	//std::cout<<coeff;

	//*********************************************************//
	//INITIAL CONDITION

	for(i=0;i<n;i++)
	{
	uold(i,0)=(1.0/3.0)*(sin(pi*(i*dx))+sin(6*pi*(i*dx))+sin(32*pi*(i*dx)));
	}
	uold(n-1,0)=0;
	//std::cout<<uold;
	
	//*********************************************************//
	//CONSTRUCTING STIFFNESS MATRIX A
	

	A(0,0)=1.0;  //to satisfy bc
	A(n-1,n-1)=1.0;  //to satisfy bc

	/*tridiagonal form*/	
	for(i=1;i<n-1;i++)
	{
		A(i,i-1)=1.0;
		A(i,i)=-2.0;
		A(i,i+1)=1.0;
	}
	A=coeff*A;
	//std::cout<<A;
	
	

	//********************************************************//
	double eps=1e-6;double errorMax;
	std::ofstream fOut1("errmax64.txt");
	std::ofstream fOut2("u64.txt");
	for(t=0;t<tmax;t=t+dt)
	
	{
				
		
		temp1 = A*uold;

		//std::cout<<temp1<<std::endl;
		
		unew=uold+temp1;
//**************************************************************************************//		
		//condition to stop the loop
		
		int m;
		matrix<double,64,1> error;

		error=unew-uold;

		errorMax=error(0,0);
			if(errorMax<0)
			{
			errorMax=-errorMax;
			}

				for(m=0;m<n;m++)
				{
					if(error(m,0)<0)
					{
					error(m,0)=-error(m,0);
					}
		
					if(errorMax<error(m,0))
					{
					errorMax=error(m,0);
					}
	
				}	

		
		if(fOut1.is_open())
    		{	
			fOut1<<t<<'\t'<<errorMax<<std::endl;
       			
		}
		
		
		if(fOut1.is_open())
    		{	
			fOut2<<t<<'\t'<<unew(40,0)<<std::endl;
       			
		}
//*******************************************************************************//
		if(errorMax<eps)
		{
		break;
		}
		
		else
		{
		//update u
		uold=unew;
		}
		
		
		
	}
	
	fOut1.close();	

	std::cout<<unew<<std::endl;	
	return 0;
}
