#include <iostream>
#include <fstream>
#include <math.h>

//Plotting the phase space of a harmonic oscillator with and without operator splitting
//AUTHOR : Pratik Aghor

// in the following code, x= position, p = momentum and dt = time step

//Hamiltonian system is written as 
// (dx/dt)=p and dp/dt= -(omega)^2*x;


void normalFDM(double &guessX, double &guessP, double omega,double thetaX, double thetaP, double dt) //explicit theta=0, implicit theta=1, avg theta=0.5
{
	
	double xnew,pnew,xold,pold;

	xold=guessX;
	pold=guessP;

	std::ofstream fOut1("harmonicOscillator_phaseSpaceData.txt");

	for (int i=0;i<1000;i++)
	{
		
		
		

		xnew= xold+ dt*((1-thetaX)*pold+thetaX*pnew);
		pnew= pold- dt*((1-thetaP)*xold+thetaP*xnew);
		
		    
		//update x and p
		xold=xnew;
		pold=pnew;

		fOut1<<xnew<<"\t"<<pnew<<std::endl;
	}
    fOut1.close();
}

void withOperatorSplitting(double &guessX, double &guessP, double omega,double thetaX, double thetaP, double dt) //explicit theta=0, implicit theta=1 
{
	
	double xnew,pnew,xold,pold;
	
	xold=guessX;
	pold=guessP;

	
	std::ofstream fOut2("harmonicOscillator_phaseSpaceData_withOperatorSplitting.txt");
	for (int i=0;i<1000;i++)
	{
		
		
		
		//step1
		xnew= xold+ dt*((1-thetaX)*pold+thetaX*pnew);
		pnew= pold;

		//updating initial conditions for the second step
		xold=xnew;
		pold=pnew;
	        
		//step2
		xnew= xold;
		pnew= pold- dt*((1-thetaP)*xold+thetaP*xnew);

		//update x and p
		xold=xnew;
		pold=pnew;

		fOut2<<xnew<<"\t"<<pnew<<std::endl;
	}
    fOut2.close();
}


int main()
{

	double x0=3;
	double p0=1;
	double timeStep=0.01;
	
//normalFDM(double &x, double & p, double omega,double thetaX, double thetaP, double dt) //explicit theta=0, implicit theta=1, avg theta=0.5
	normalFDM(x0, p0, 1 , 0, 1, timeStep);

//withOperatorSplitting(double &x, double & p, double omega,double thetaX, double thetaP, double dt) 
	withOperatorSplitting(x0, p0, 1 , 0, 1, timeStep);
return 0;
}
