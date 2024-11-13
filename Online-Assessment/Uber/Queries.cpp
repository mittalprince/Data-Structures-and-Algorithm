/*
You are given two arrays of integers a and b, and an array queries, the elements of which are queries you are required to process. Every queries [il can have one of the following two forms:
• 10, 1, *]. In this case, you need to assign
a [i] the value of x ( a [i] = x ).
• [1, x]. In this case, you need to find the total number of pairs of indices i and j such that
a [i] + bljl = x .
main.c
]
SETTINGS
Perform the given queries in order and return an array containing the results of the queries of the type [1,
x]


For a = [3, 41, b = [1, 2, 31, and
queries = ([1, 5], lo, 0, 1], [1, 5]] ,
the output should be solution (a, b,
queries) = 12, 1] •
The arrays look like this initially:
a = [3, 4] and b = [1, 2, 3]
For the query [1, 5], there are two ways to form a sum of 5 using an element from each
array: 5 = 3 + 2 = a [0] + b[1] and 5 = 4
+ 1 = a [1] + b[0] . Scrihe result is 2 .
The query lo, o, 11 re-assigns the value of a [0] to 1, so the arrays now look like this:
a = [1, 4] and b = [1, 2, 3]
For the final [1, 5] query, there's now only one way to form a sum of 5 using an element
from each array: 5 = 4 + 1 = a [1] + b[0] .
So the result is 1 .

Since the two queries of type [1, x] gave results of 2 and 1 respectively, the answer is
[2, 11 •
The arrays look like this initially:
a = 12, 31 and b = [1, 2, 2]
E
GS
For the query [1, 41, There are three ways to form a sum of 4 using an element from each
array: 4 = 2 + 2 = a [0] + b[1]: 4 = 2 + 2
= al0] + b|21, and 4 = 3 + 1 = a [1] +
b [0] . So the result is 3 .
The query 10, 0, 31 re-assigns the value of a[0] to 3, so the arrays now look like this:
a = [3, 31 and b = [1, 2, 2]
For the query [1, 5] , there are now 4 ways to form a sum of 5 using an element from

The query 10, 0, 31 re-assigns the value of a (0] to 3, so the arrays now look like this:
a = [3, 31 and b = [1, 2, 2]
For the query [1, 51, there are now 4 ways to form a sum of 5 using an element from
each array: 5 = 3 + 2 = a[0] + b [1] , 5 =
3 + 2 = a[0] + b[21, 5 = 3 + 2 = a[11 +
b [1] , and 5 = 3 + 2 = a[1] + b[2] . So the
result is
4
Since the two queries of type (1, x] gave results of 3 and a respectively, the answer is
[3, 4]
*/

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> processQueries(vector<int>& a, vector<int>& b, vector<vector<int>>& queries) {
    vector<int> results;
    
    // Step 1: Build frequency map for array `b`
    unordered_map<int, int> bFreq;
    for (int val : b) {
        bFreq[val]++;
    }

    // Step 2: Process each query
    for (const auto& query : queries) {
        if (query[0] == 0) {
            // Update query: [0, i, x] -> Update a[i] to x
            int i = query[1];
            int x = query[2];
            a[i] = x;
        } else if (query[0] == 1) {
            // Sum query: [1, x] -> Count pairs where a[i] + b[j] == x
            int x = query[1];
            int count = 0;
            for (int valA : a) {
                int needed = x - valA;
                // Check if `needed` exists in `bFreq` map
                if (bFreq.count(needed)) {
                    count += bFreq[needed];
                }
            }
            results.push_back(count);
        }
    }
    
    return results;
}


#include <vector>
#include <unordered_map>
using namespace std;

vector<int> processQueries(vector<int>& a, vector<int>& b, vector<vector<int>>& queries) {
    vector<int> results;
    
    unordered_map<int, int> bFreq;
    for (int val : b) {
        bFreq[val]++;
    }

    // Initialize the pairCount map with sums from initial array `a`
    unordered_map<int, int> pairCount;
    for (int valA : a) {
        for (const auto& [valB, freq] : bFreq) {
            pairCount[valA + valB] += freq;
        }
    }

    // Process each query
    for (const auto& query : queries) {
        if (query[0] == 0) {
            // Update query: [0, i, x]
            int i = query[1];
            int newX = query[2];
            int oldX = a[i];
            
            // Update pairCount for the old value of a[i]
            for (const auto& [valB, freq] : bFreq) {
                pairCount[oldX + valB] -= freq;
                pairCount[newX + valB] += freq;
            }

            // Update `a[i]` to the new value
            a[i] = newX;

        } else if (query[0] == 1) {
            // Sum query: [1, x] -> Get the precomputed count from pairCount
            int x = query[1];
            results.push_back(pairCount[x]);
        }
    }
    
    return results;
}
