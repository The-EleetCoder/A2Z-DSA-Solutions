/*
https://www.naukri.com/code360/problems/allocate-books_1090540
*/

/*
The problem you're solving is similar to the Book Allocation Problem, where the goal is to minimize the maximum number of pages allocated to a student. Given n books, each with a certain number of pages, and m students, you need to allocate books to students such that each student gets a contiguous block of books, and the maximum number of pages assigned to a student is minimized.

The idea is to use binary search on the possible values of the maximum pages a student can be assigned, and the helper function validPageCount helps verify if a given page limit (mid) can be used to distribute books among m students.
*/

// Helper function to check if it's possible to allocate books such that
// no student gets more than 'mid' pages.
bool validPageCount(vector<int> &arr, int m, int mid) {
    int pageCount = arr[0]; // Initialize the current student's page count with the first book
    int studentCount = 1;   // Start by allocating books to the first student
    
    // Traverse through the books
    for (int i = 1; i < arr.size(); i++) {
        // If adding the current book exceeds 'mid', assign this book to the next student
        if (pageCount + arr[i] > mid) {
            pageCount = arr[i]; // Start new allocation for the next student
            studentCount++;     // Increment the student count
        } else {
            // Otherwise, add the current book to the current student's allocation
            pageCount += arr[i];
        }
    }
    
    // Return true if the number of students needed is less than or equal to 'm'
    return studentCount <= m;
}

// Function to find the minimum possible value of the maximum number of pages
// that can be assigned to a student.
int findPages(vector<int> &arr, int n, int m) {
    // Edge case: If there are more students than books, it's not possible to allocate
    if (m > n)
        return -1;

    // The lower bound of the binary search is the largest single book (because
    // each student must be assigned at least one book).
    int low = *max_element(arr.begin(), arr.end());

    // The upper bound of the binary search is the total sum of pages in all books,
    // where one student could theoretically be assigned all books.
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int high = sum;

    // Perform binary search to find the optimal solution
    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate mid value (potential maximum page count)

        // Check if it is possible to allocate books such that the maximum pages
        // a student gets is less than or equal to 'mid'.
        bool isValidPageCount = validPageCount(arr, m, mid);

        if (isValidPageCount) {
            // If it's possible, try to find a smaller maximum by lowering the upper bound
            high = mid - 1;
        } else {
            // If it's not possible, we need to increase the minimum allowed maximum
            low = mid + 1;
        }
    }

    // 'low' now contains the minimum possible value for the maximum pages a student gets
    return low;
}

/*
Intuition Behind the Code:

Binary Search for Optimization:
The key idea is to use binary search on the value of the maximum number of pages a student can be assigned (mid). The range of this value goes from low (the largest single book, since no student can be assigned less than the largest book) to high (the total sum of all pages, meaning one student would get all the books).

Valid Configuration Check (validPageCount):
For a given value of mid, we use the validPageCount function to check if we can allocate books such that no student gets more than mid pages. This function iterates over the books, trying to allocate them greedily to students. If the page count for a student exceeds mid, we move on to the next student.

Adjusting the Search Range:
If it's possible to allocate books such that no student gets more than mid pages, it means we can try for an even smaller maximum page limit, so we reduce high.
If it's not possible, we increase low to find a higher value that works.

Time Complexity: O(nlog(sum−max)).
*/