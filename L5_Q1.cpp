/*!
@file L5_Q1.cpp
@brief this file is used to provide the data structure and algorithm for problem statement 1 of assignment 5

@author Diya Mourya
@date 28/09/2019
*/


#include <iostream>
using namespace std;

/*
*function to find maximum of dgree of two polynomials
*/

int max(int m, int n)
{
    return (m>n) ? m:n ;
}

/* 
*Function to find addition of polynomials
*/

void add(int A[], int B[], int m, int n)
{
    int size = max(m,n);
    int *sum = new int[size];
    for(int i=0;i<m;i++)
    {
        sum[i]= A[i];
    }
    
    for(int i=0;i<n;i++)
    {
        sum[i]=sum[i]+B[i];
    }
    
    for(int i=(size-1); i>=0;i--)
    {
        cout<<sum[i]<<" "<<i<<endl;
    }
}

/*
*Void function two find multiplication of two polynomials
*/

void multiply(int A[], int B[], int m, int n)
{
    int *prod = new int[m+n-1];
    for(int i=0; i<m+n-1; i++)
    {
        prod[i]=0;
    }
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++){
            prod[i+j] += A[i]*B[j];
        }
    }
    
    for(int i=(m+n-2); i>=0; i--)
    {
        cout<<prod[i]<<" "<<i<<endl;
    }
}

/* 
*main function
*/

int main ()
{
  
  clock_t cstart = clock();
  int m;			// number of terms in first polynomial
  cout << "No.of terms in the expression: ";
  cin >> m;

  cout << "Coefficient  Power" << endl;
  int *A = new int[m - 1];
  int *a = new int[m - 1];

  for (int i = (m - 1); i >= 0; i--)
    {
      cin >> A[i];
      cin >> a[i];
    }

  cout << endl;

  int n;			// number of terms in second polynomial
  cout << "No.of terms in the expression: ";
  cin >> n;

  cout << "Coefficient  Power" << endl;
  int *B = new int[n - 1];
  int *b = new int[n - 1];

  for (int i = (n - 1); i >= 0; i--)
    {
      cin >> B[i];
      cin >> b[i];
    }
    
    int num;
    while(1)
    {
        cout<<"Enter 1 to add or 2 for multiply";
        cin>>num;
        switch(num)
        {
            case 1:
            cout<<"Addition:"<<endl;
            add(A,B,m,n);
            break;
            
            case 2:
            cout<<"Multiplication:"<<endl;
            multiply(A,B,m,n);
            break;
            
            case 3:
            exit(1);
            default:
            cout<<"Wrong Num"<<endl;
        }
    }

      clock_t cend = clock();

    double time_elapsed_ms = 1000.0 * (cend-cstart) / CLOCKS_PER_SEC;
    
   cout << "CPU time used: " << time_elapsed_ms << " ms\n"<<endl;
  return 0;
}
