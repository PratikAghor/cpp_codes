#include<iostream>
#include<fstream>
#include "../matrix.h"
#include "math.h"


int main()
{
	
	int r1,c1,n;
	int i,j,k,l;
	
	n=2;
	r1=2;
	c1=2;

	matrix<double,2,2> A;
	matrix<double,2,1> b;
	
/*		std::cout<<"Enter elements in matrix A (row-wise)"<<r1<<"x"<<c1<<std::endl;
		std::cin>>A;
		
		std::cout<<"Enter elements of the rhs column vector (row-wise)"<<r1<<"x"<<1<<std::endl;
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
		
		// -------------- FORWARD SWEEP --------------
		for (j=0;j<n;j++)  // column number
		{
			for (i=j+1;i<n;i++) // Row number
			{
			double mIJ;
				//pivoting
				double pivot = A(i,i);
				int index = i;
				for(k = j+1; k < n; k++)
				{
					if(pivot < A(i,k))
					{
						index = k;
						pivot = A(i,k);
					}
				}
			
				std::cout<<"index=\t"<<index+1<<"pivot=\t"<<pivot<<std::endl;

				//Row exchange
				for(k = 0; k < n; k++)
				{
				double temp = A(i,k);
				A(i,k) = A(index,k);
				A(index,k) = temp;
				}
			
			
			mIJ= - A(i,j)/ A(j,j);
			b(i,0)= b(i,0)+ mIJ * b(j,0);
			A(i,j) =0;
				for (k=j+1;k<n;k++)
				{
				A(i,k) = A(i,k) + mIJ * A(j,k);
				}			
			}
		}

/*		std::cout<<"lhs is"<<std::endl;
		std::cout<<A<<std::endl;

		std::cout<<"rhs is"<<std::endl;
		std::cout<<b<<std::endl;
*/

		
	std::ofstream fOut1("output.txt");
	if(fOut1.is_open())
    {
       		fOut1<<"lhs is"<<std::endl;
		for(i=0;i<r1;i++)
		{	
			for(j=0;j<c1;j++)
			{
			fOut1<<"\t";
			fOut1<<A(i,j);
			}
			fOut1<<std::endl;
		}

		fOut1<<"rhs is"<<std::endl;
		for(i=0;i<r1;i++)
		{	
			fOut1<<"\t";
			fOut1<<b(i,0);
			
			fOut1<<std::endl;
		}


		fOut1.close();
    }		
					
return 0;
}
