# Hashing | Maps | Time Complexity | Collisions | Division Rule of Hashing

## Hashing:

`Purpose`: Efficiently store and fetch information.  
`Example`: Counting frequency of elements in an array using hashing instead of brute force.

## Brute Force Approach:

`Method`: Loop through the array for each query.  
`Time Complexity`: O(Q * N), where Q is the number of queries, and N is the array size.  
`Drawback`: Inefficient for large inputs.  

## Optimized Approach Using Hashing:
`Pre-storing`: Create a hash array to store the frequency of elements.  
`Fetching`: Retrieve values directly from the hash array.  
`Limitation`: Hash array size depends on the maximum value in the array.

## Character Hashing:
`Mapping`: Use ASCII values or subtract character 'a' or 'A' for mapping characters to integers.  
`Hash Array Size`: Depends on the type of characters (lowercase, uppercase, or both).

## Handling Large Numbers:
`Maps/Unordered Maps`: Used to handle large numbers beyond array size limits.  
`Key-Value Pairs`: Elements are keys, and their frequency is the value.

## Map vs. Unordered Map:
`Map`: O(logN) time complexity for insertion and retrieval.  
`Unordered Map`: O(1) time complexity in the best and average cases; O(N) in the worst case.

## Collision:
`Cause`: Multiple elements hashing to the same index.  
`Handling`: Linear chaining using linked lists.  
`Division Method`: Common hashing technique using modulo operation.  
`Worst Case`: All elements hash to the same index, leading to O(N) complexity.  

## Division Rule of Hashing:
`Example`: Hashing elements by their modulo value.  
`Collision Scenario`: When many elements result in the same modulo value, requiring chaining.

## Collision and Hashing in Maps:
`Concept`: Maps handle collisions internally.  
`Limitation in Unordered Maps`: Key data types are restricted compared to Maps.