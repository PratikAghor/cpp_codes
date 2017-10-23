#include<iostream>
#include "matrix.h"
#include "vector.h"

int main()
{
	int r1,c1;
	int i,j,k,l,iter,niter;
	
	const int n=2;
	
	matrix<double, n,n> A, ATranspose;
	vect<double,n> b, bTranspose, x, xold, xnew,xGuess;

	std::cout<<"Enter elements of matrix A (lhs of Ax=b)(row-wise)"<<n<<"x"<<n<<std::endl;
	std::cin>>A;
	
	std::cout<<"Enter elements of vector b (rhs of Ax=b) (row-wise)"<<n<<"x"<<1<<std::endl;
	std::cin>>b;

	std::cout<<"Enter elements of the guess vector (row-wise)"<<n<<"x"<<1<<std::endl;
	std::cin>>xGuess;
	x=xGuess;
	
/************************************************************************************************************/	

	double alpha, beta;

	vect<double,n> residue, d, error;

	double errorMax;
	
	vect<double,n> temp1,temp2,temp6, temp7, temp9;
	
	matrix<double,n,n> temp5, temp8;
	double deltaOld, deltaNew, delta0,temp3, temp4 ;
	
	double epsilon= 1e-4;
	double eps = epsilon*epsilon;
	niter=300; //max no. of iterations
	iter=0;
	

//*********************calculate residue with guess vector******************************//	
	temp1=A*x;
	residue=b-temp1;
//***initialize the search direction d with the residue d0=r0=b-A*x0****// 
	d = residue;
	
	//calculate alpha -> alpha_(i)= r_(i)^T* r(i)/ d_(i)^T*A*d_(i)
	deltaNew=dot(residue,residue);  // this is r_(i)^T* r_(i)-> numerator
	
	delta0=deltaNew;

	while(iter<niter && deltaNew>eps*delta0)
	{
	/********************calculating alpha************************/
		temp2= A*d;			//temp2 = q in the given algorithm
		//std::cout<<"temp2="<<temp2<<std::endl;
	
		temp4=dot(d,temp2); 		//this calculates the denominator of expression for alpha
		//std::cout<<"temp4="<<temp4<<std::endl;
		
		alpha =deltaNew/temp4;
		//std::cout<<"alpha="<<alpha<<std::endl;
	/*************************************************************/

		for(i=0;i<n;i++)
		{
			temp5(i,i)=alpha;
		}

		temp6=temp5*d;
	//	std::cout<<"temp6="<<temp6<<std::endl;
	//update x-> xnew =xold+alpha*d//
		x = x + temp6;
	//	std::cout<<"x="<<x<<std::endl;
	//************************************************************/

		//if(iter%50==0)
		{
		//	residue= b-temp2;
		}
		
		//else
		{
			temp7=temp5*temp2; // temp7=(alpha*I)*(A*d)
	//		std::cout<<"temp7="<<temp7<<std::endl;
			residue=residue-temp7;
		}
		
	//	std::cout<<"residue="<<residue<<std::endl;
	//********************calculating beta************************/

		deltaOld=deltaNew;
		deltaNew=dot(residue,residue);
		beta= deltaNew/deltaOld;
	//	std::cout<<"beta="<<beta<<std::endl;
	//************************************************************/

		for(i=0;i<n;i++)
		{
			temp8(i,i)=beta;
		}
		
		temp9= temp8*d; 		//temp9=(beta*I)*d;
	//std::cout<<"temp9="<<temp9<<std::endl;
	//***************update d (search direction)*****************/
		d= residue+temp9;
	//	std::cout<<"d="<<d<<std::endl;
	//************************************************************/
	//	std::cout<<"iter="<<iter<<std::endl;
		
	//	if(iter<niter && deltaNew>epsilon*epsilon*delta0)
		{
		iter =iter+1;
		}
	//	else
	//	{break;}
	std::cout<<"deltaNew="<<deltaNew<<std::endl;
	std::cout<<"delta0="<<delta0<<std::endl;
	double ratio = deltaNew/delta0;
	std::cout<<"deltaNew/delta0"<<ratio<<std::endl;
	}
std::cout<<"no. of iterations="<<iter<<std::endl;
std::cout<<"ans ="<<x<<std::endl;
return 0;
}
