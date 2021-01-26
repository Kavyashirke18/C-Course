#include <iostream>
using namespace std;

double * read_poly(int &n){
  cout << "il grado: ";
  cin >> n;
  double * c=new double[n+1];
  for(int i=0;i<=n;i++){
    cout << "coefficient of degree " << i << ": ";
    cin >> c[i];
  }
  return c;
}

void print_poly(double *c, int n){
  int i;
  cout << c[0];
  if(n>0)
    cout << " + ";
  for(i=1;i<n;i++)
    cout << c[i] << "*x^" << i << " + ";
  if(n>0)
    cout << c[n] << "*x^" << i;
  cout << endl;
}

int main()
{
    double *final_ans;
    final_ans = poli_sum(p1, d1, p2, d2, dr);
    final_ans = poli_mul(p1, d1, p2, d2, dr);
    double res = val(p1, d1, x);
    delete [] final_ans;
    return 0;
}
double *poli_sum(double *p1, int d1, double *p2, int d2, int &dr)
{
    size = (d1>d2)?d1:d2;
    double *ans = new double[size];
    int i=0;
    while(i<=d1 && i<=d2)
    {
        ans[i] = p1[i]+p2[i];
        i++;
    }
    while(i<=d1)
    {
        ans[i]+=p1[i];
        i++;
    }
    while(i<=d2)
    {
        ans[i]+=p1[i]; 
        i++;
    }
    return ans;
}
double *poli_mul(double *p1, int d1, double *p2, int d2, int &dr)
{
    double *ans = new double[d1+d2-1];
    for(int i=0;i<d1+d2-1;i++)
    {
        ans[i] = 0;
    }
    for(int i=0;i<d1;i++)
    {
        for(int j=0;j<d2;j++)
        {
            ans[i+j] += p1[i]*p2[j]; 
        }
    }
    return ans;
}
double val(double *p1, int d1, int x)
{
    double res = p1[0];
    for(int i=1;i<d1;i++)
    {
        res = res*x+p1[i];
    }
    return res;
}