/*
https://www.naukri.com/code360/problems/check-prime_624934?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&count=25&page=1&search=&sort_entity=order&sort_order=ASC
*/

bool isPrime(int n)
{
	if (n==1) return false;

	for(int i = 2; i*i<=n; i++ ){
		if (n%i==0){
			return false;
		}
	}
  
	return true;
}
