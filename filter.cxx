#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

void reading(double* a, int N, const string fname)
{
    ifstream in(fname.c_str());
    for (int i = 0; i < N; i++) 
    {
        in >> a[i];
    }
    in.close();
}

void printing(double* a, int N) 
{
    for (int i = 0; i < N; i++) 
    {
        cout << a[i] << endl;
    }
}

void saving(double* a, int N, string output)
{
    ofstream out(output.c_str());
    for (int i = 0; i < N; i++) 
    {
        out << a[i] << endl;
    }
    out.close();
}
    
    
void arrayfilter(double* a, const int N) 
{
    double temp2, temp1 = a[0];
    a[0] = (a[0]+a[1])/3;
    for (int i = 1; i < N-1; i++) 
    {
        temp2 = a[i];
        a[i] = (temp1+a[i]+a[i+1])/3;
        temp1 = temp2;
    }
    a[N-1] = a[0];
   
}

int main() 
{
  int N = 237;
  double* a = new double[N];
  const string fname = "noisy.txt";
  const string output = "filterdata.txt";
  
  reading(a, N, fname);
  printing(a, N);
  arrayfilter(a, N);
  arrayfilter(a, N);
  arrayfilter(a, N);
  arrayfilter(a, N);
  arrayfilter(a, N);
  printing(a, N);
  saving(a, N, output);
  delete[] a;
}
  
  
  

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    