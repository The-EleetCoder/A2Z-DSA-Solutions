/*
https://www.naukri.com/code360/problems/check-armstrong_589?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&count=25&search=&sort_entity=order&sort_order=ASC&page=1&leftPanelTabValue=PROBLEM
*/

bool checkArmstrong(int n) {

  int input = n, sum = 0;  
  // Calculate the number of digits in the number
  int input_length = to_string(n).length();

  // Loop through each digit in the number
  while (input > 0) {
      int digit = input % 10;
      sum += pow(digit, input_length);
      input /= 10;
  }
  return (n == sum);
}

/*
Time Complexity: O(log10 N + 1) 
where N is the input number. The time complexity is determined by the number of digits in the input integer N.
*/
