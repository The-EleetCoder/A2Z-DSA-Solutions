/*
https://www.naukri.com/code360/problems/check-armstrong_589?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&count=25&search=&sort_entity=order&sort_order=ASC&page=1&leftPanelTabValue=PROBLEM
*/

bool checkArmstrong(int n) {
  int input = n, sum = 0;
  int input_length = to_string(n).length();

  while (input > 0) {
	  int digit = input % 10;
	  sum += pow(digit,input_length);
	  input /= 10;
  }

  return (n == sum);
}

/*
Precompute Digit Powers:
Instead of calculating pow(digit, input_length) repeatedly, you can precompute powers of digits from 0 to 9 once before the loop starts and store them in an array.

Avoid 'to_string' Conversion:
You can compute the number of digits directly by iterating over the number, which avoids the conversion overhead.
*/

// Optimised code
bool checkArmstrong(int n) {
    int original = n;
    int sum = 0;

    // Calculate the number of digits in the number
    int input_length = 0;
    int temp = n;
    while (temp > 0) {
        input_length++;
        temp /= 10;
    }

    // Precompute the powers of digits from 0 to 9
    int powers[10];
    for (int i = 0; i < 10; i++) {
        powers[i] = pow(i, input_length);
    }

    // Calculate the Armstrong sum
    while (n > 0) {
        int digit = n % 10;
        sum += powers[digit];
        n /= 10;
    }

    return (original == sum);
}

/*
Time Complexity:
Original Code: O(d * log n) where d is the number of digits in n (due to the pow function being called d times).
Optimized Code: O(d), since the power calculation is done in constant time for each digit using the precomputed array.
*/