/*
https://www.naukri.com/code360/problems/first-n_4605104?count=25&page=1&search=&sort_entity=order&sort_order=ASC
*/

// Parameterized way
int sumN(int n, int sum){
    if (n==0) return sum;
    return sumN(n-1, sum+n);
}

long long int firstN(int n) {
    int sum = sumN(n, 0);
    return sum;
}

// Functional way
int func(int n){
   
   // Base Condition.
   if(n == 0){
       return 0;
   }

   // Problem broken down into 2 parts and then combined.
   return n + func(n-1);
}

// Most optimal approach is to directly use the formula
int func(int n) {
  int sum = n * (n + 1) / 2;
  return sum;
}
