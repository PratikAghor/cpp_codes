#include <iostream>
#include <fstream>
#include <math.h>
//fdm scheme for (dx/dt)=-(lambda)*x;
//AUTHOR : Pratik Aghor

void normalFDM(double x0, double lambda,double thetaX, double dt) //explicit theta=0, implicit theta=1, avg theta=0.5
{
		
	double xnew,xold;

	xold=x0;	//x0=x(t=0) that is, x0=initial condition

	std::ofstream fOut1("linearDE.txt");
	
	for (int i=0;i<1000;i++)
	{
		xnew= xold-lambda* dt*((1-thetaX)*xold+thetaX*xnew);
			
		//update 
		xold=xnew;
		fOut1<<xnew<<"\t"<<i<<std::endl;
		
	}
	fOut1.close();

}

//***************************************************************************//

int main()
{

	double x0=3;
	double timeStep=0.01;
	
//normalFDM(double &x, double & p, double omega,double thetaX, double thetaP, double dt) //explicit theta=0, implicit theta=1, avg theta=0.5
	normalFDM(x0, 1 , 0.5, timeStep);

return 0;
}
