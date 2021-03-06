#include<iostream>
#include<fstream>
#include "math.h"
#include "../matrix.h"

int main()
{
	
	int r1,c1,n;
	int i,j,k,l;
	
	n=2;
	
	matrix<double, 2,2> a,L;
/*	std::cout<<"Enter elements in matrix A (row-wise)"<<n<<"x"<<n<<std::endl;
	std::cin>>a;
*/

	std::ifstream fIn1("A.txt");//input
	if(fIn1.is_open())
    {
        fIn1>>a;
    }		
			
//****************************************************************//		


		if(symFlag(a)==0)
		{
		std::cout<<"Cholesky decomposition works only for symmetric positive definite matrices."<<std::endl;
		}
		
		else
		{
			L(0,0)=sqrt(a(0,0));
			for(i=0;i<n;i++)
			{
			L(i,0)=a(i,0)/L(0,0);
			}
		
			for(i=1;i<n;i++)
			{
			double sum1=0;
				for(k=0;k<i;k++)
				{
				sum1=sum1+L(i,k)*L(i,k);
				L(i,i) =sqrt(a(i, i)-sum1);		
				}
		

				for(j=i;j<n;j++)
				{
				double sum2=0;
					for(k=0;k<j;k++)
					{
					sum2=sum2+L(i,k)*L(j,k);
					}
					L(j,i)=(a(j,i)-sum2)/L(i,i);		
				}
			}


		std::cout<<"A=LL' where L is"<<std::endl;
		std::cout<<L;
		
			std::ofstream fOut("output.txt");
			if(fOut.is_open())
			{
			fOut<<"ans is"<<std::endl;
			for(i=0;i<n;i++)
			{	
				for(j=0;j<n;j++)
				{
				fOut<<"\t";
				fOut<<L(i,j);
				}
				fOut<<std::endl;
			}
			fOut.close();
			}	
		}
return 0;
}
