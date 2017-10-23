#ifndef VECTOR_H //Include guard
#define VECTOR_H
template<typename T, int N>
struct vect
{
	
	
	T data[100];
	
	vect()
	{
			
		int i=0;
	//	std::cout<<"Enter "<<N<<" numbers: "<<std::endl;	
	/*	for(i=0;i<N;i++)
		{
		
			std::cin>>data[i];
		}
	*/
	}

//double operator[](int j) {return data[j];};
double operator[]( int i) const {return data[i];}
double & operator[]( int i) {return data[i];}
};



template<typename T, int N>
std::ostream& operator<<  (std::ostream& os, vect<T,N> &myVect)
{	
	for(int i=0; i<N; i++)
	{
	os<<myVect.data[i];
	}
	std::cout<<'\n';	
	return os;
		 
}


template<typename T, int N>
std::istream& operator>>  (std::istream& is, vect<T,N> &myVect)
{	
	for(int i=0; i<N; i++)
	{
	is>>myVect.data[i];
	}	
	return is;
		 
}

//******************************************************************************//
template<int m>
struct metaDot 
{
	template<typename T, int N>
	static T f(vect<T,N>& a, vect<T,N>& b)
	{
	return a[m]*b[m] + metaDot<m-1>::f(a,b);
	}
};	

template<> // the end of the recursion
struct metaDot<0> 
{
	template<typename T, int N>
	static T f(vect<T,N>& a, vect<T,N>& b)
	{
	return a[0]*b[0];
	}
};


// The dot() function invokes metaDot
	template<typename T, int N>
	inline T dot(vect<T,N>& a, vect<T,N>& b)
	{
	return metaDot<N-1>::f(a,b);
	}
	
//*****************************************************************************//

	template<typename T, int N>
	vect<T,N> operator+(vect<T,N> &a, vect<T,N> &b)
	{
		vect<T,N> answer;
		int i;
		for(i=0;i<N;i++)
		{
			answer[i]=a[i]+b[i];
		}
	return answer;
	}

	template<typename T, int N>
	vect<T,N> operator-(vect<T,N> &a, vect<T,N> &b)
	{
		vect<T,N> answer;
		int i;
		for(i=0;i<N;i++)
		{
			answer[i]=a[i]-b[i];
		}
	return answer;
	}


	
#endif
