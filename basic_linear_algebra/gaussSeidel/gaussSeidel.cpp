#include<iostream>
#include<fstream>
#include "math.h"
#include "../matrix.h"

int main()
{
	
	int r1,c1,n;
	int i,j,k,l,iter,niter;
	double eps=1e-4;
	n=2;
	
	matrix<double, 2,2> A,R,D,DInverse;
	matrix<double,2,1> b,xold,xnew,temp1,temp2;

/*	std::cout<<"Enter elements in matrix A (row-wise)"<<n<<"x"<<n<<std::endl;
	std::cin>>A;
	
	std::cout<<"Enter elements in matrix A (row-wise)"<<n<<"x"<<1<<std::endl;
	std::cin>>b;
*/

	std::ifstream fIn1("A.txt");
	if(fIn1.is_open())
    	{
        fIn1>>A;
    	}		
	
	std::ifstream fIn2("b.txt");
	if(fIn2.is_open())
    	{
        fIn2>>b;
    	}	
	
	std::cout<<"specify maximum number of iterations"<<std::endl;
	std::cin>>niter;
/***********************A=D+R*********************************************/	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		if(i==j)
		{
		D(i,j)=A(i,j);
		}
		
		}

	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		if(i==j)
		{
		DInverse(i,j)=1/A(i,j);
		}
		
		}

	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		if(i!=j)
		{
		R(i,j)=A(i,j);
		}
		
		}

	}

		std::cout<<"A=D+R where D is"<<std::endl;
		std::cout<<D<<std::endl;
		
		std::cout<<"A=D+R where R is"<<std::endl;
		std::cout<<R<<std::endl;

		std::cout<<"A=D+R where inverse of D is"<<std::endl;
		std::cout<<DInverse<<std::endl;
		
/*********************************************************************/
		
		for(iter=0;iter<niter;iter++)
		{
				temp1= R*xold;
				temp2=b-temp1;
				xnew=DInverse*temp2;
				xold=xnew;
				std::cout<<"ans is"<<std::endl;
				std::cout<<xnew<<std::endl;

		}
		
	std::ofstream fOut("output.txt");
	if(fOut.is_open())
	{
	fOut<<"ans is"<<std::endl;
	for(i=0;i<n;i++)
		{	
			fOut<<"\t";
			fOut<<xnew(i,0);
			
			fOut<<std::endl;
		}

	fOut.close();
	}	
return 0;
}
