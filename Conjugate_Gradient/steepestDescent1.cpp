#include<iostream>
#include "matrix.h"
#include "vector.h"

int main()
{
	int r1,c1;
	int i,j,k,l,iter,niter;
	double eps=1e-4;
	const int n=2;
	
	matrix<double, n,n> A, ATranspose;
	vect<double,n> b, bTranspose, xold, xnew,xGuess;

	std::cout<<"Enter elements of matrix A (lhs of Ax=b)(row-wise)"<<n<<"x"<<n<<std::endl;
	std::cin>>A;
	
	std::cout<<"Enter elements of vector b (rhs of Ax=b) (row-wise)"<<n<<"x"<<1<<std::endl;
	std::cin>>b;

	std::cout<<"Enter elements of the guess vector (row-wise)"<<n<<"x"<<1<<std::endl;
	std::cin>>xGuess;
	xold=xGuess;
	
/************************************************************************************************************/	

	double alpha;
	vect<double,50> Alpha;
	
	vect<double,n> residue, residueTranspose, error;
	double errorMax;
	
	vect<double,n> temp1,temp2,temp6;
	//double temp3,temp4;
	matrix<double,n,n> temp5;
	

	double temp3,temp4;

	while (1)
	{
		
		temp1=A*xold;
//		std::cout<<"temp1="<<temp1<<std::endl;
	
		residue=b-temp1;
//		std::cout<<"residue="<<residue<<std::endl;
			
		temp3=dot(residue,residue);
//		std::cout<<"temp3="<<temp3<<std::endl;
		
		temp2= A*residue;
//		std::cout<<"temp2="<<temp2<<std::endl;
		
		temp4=dot(residue,temp2);
//		std::cout<<"temp4="<<temp4<<std::endl;

		alpha =temp3/temp4;
//		std::cout<<"alpha="<<alpha<<std::endl;
	
		//Alpha[iter]=alpha; 

			for(i=0;i<n;i++)
			{
				temp5(i,i)=alpha;
			}
//		std::cout<<"temp5="<<temp5<<std::endl;
		temp6=temp5*residue;
//		std::cout<<"temp6="<<temp6<<std::endl;

		xnew= xold+temp6;
	
		error =xnew-xold;

		/*************************condition to stop the loop******************************/
				int m;			
				errorMax=error[0];
				if(errorMax<0)
				{
				errorMax=-errorMax;
				}

					for(m=0;m<n;m++)
					{
						if(error[m]<0)
						{
						error[m]=-error[m];
						}
		
						if(errorMax<error[m])
						{
						errorMax=error[m];
						}
	
					}	
			
			if(errorMax<eps)
			{
				break;
			}	
	
			else
			{
			iter=iter+1;
			xold=xnew;
			}
			std::cout<<xnew<<std::endl;
	}
	
	//std::cout<<"the answer is"<<std::endl;
	//std::cout<<xnew<<std::endl;	


return 0;
}
