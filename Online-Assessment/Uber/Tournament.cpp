#include <iostream>
#include <vector>
using namespace std;
#include <jsoncpp/json/json.h>

// Question
// You are hosting a tennis tournament with many players participating. All your players are pre-ranked based on their historical performance. In an elimination tournament, the loser of each match-up is immediately eliminated from the tournament. Each winner will play another in the next round, until the final match-up, whose winner becomes the tournament champion.

// Part 1/2
// Can you write a program to predict the players in each round? Your program should naively assume that a higher ranked player always wins against a lower ranked player.

// Input
//  [1, 2, 3, 4, 5, 6, 7, 8]  //ranks of each player and the match ups. The smaller the number, the higher the rank.

// Output:
//  1, 2, 3, 4, 5, 6, 7, 8 //round 1
//  1, 3, 5, 7  //round 2
//  1, 5  //round 3:
//  1   //round 4

// n(n-1)
// 1,2,3,4,5,6
// 1,3,5
// 1,5
// 1

// n + n/2 +  n/4

// 2^n
// nlogn

// n^()

// n + n/2 + n/4 + n/8 + ----- + 1 = 2n

// 1,2,3,4,5,6,7
// n=7
// k=0;

// i=0 ->(0,1) 1,2 -> 1 -> [1,2,3,4,5,6,7], k=1
// i=2 ->(2,3) 3,4 -> 3 -> [1,3,3,4,5,6,7], k=2;
// i=4 ->(4,5) 5,6 -> 5 -> [1,3,5,4,5,6,7], k=3;
// i=6 -> 7 -> 7 -> [1,3,5,7,5,6,7], k=4;

// rank = [1,3,5,7], n=4, k=0;

// i=0 -> (0,1) -> 1,3 -> 1 -> [1,3,5,7], k=1;
// i=2 -> (2,3) > 5,7 -> 5 > [1,5,5,7], k=2;

// rank=[1,5], n=2,k=0;
// i=0 -> (0,1) 1,5 -> 1 -> [1,5], k=1;
// rank=[1], n=1, k=0;

// rank=[1,2,3,4,5,6], n=4, k=0;
// i=0 -> 1,2 -> [1,2,3,4] k=1;
// i=2 -> 3,,4 -> [1,3,3,4],k=2;
// i=4 > 5,66 -> [1,3,5], k=3;

// rank=[1,3,5], n=3, k=0;
// i=0 > 1,3 -> [1,3,5],k=1;
// i=2 -> [1,5],k=2;

// [1,5], n=1, k=0;

// 2^n, 2^n-1

int findWinner(vector<int> rank)
{
    int n = rank.size();
    int k = 0;
    while (n > 1)
    {
        for (int i = 0; i < n; i += 2)
        {
            if (i + 1 < n)
            {
                int a = rank[i];
                int b = rank[i + 1];
                rank[k++] = min(a, b);
            }
            else
            {
                rank[k++] = rank[i];
            }
        }
        rank.resize(k);
        n = k;
        k = 0;
    }
    return rank[0];
}

int main()
{
    std::cout << "Hello world" << std::endl;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    cout << findWinner(a) << endl;
    return 0;
}

// Part 2
// Can you create a draw generator that makes sure the better players do not meet in the earlier rounds? To be more specific, a higher-ranked player should never be eliminated in an earlier round than someone ranked lower according to your prediction in part 1.

// The input is a total number of players, output a possible draw

// Input : 8
// Output: [1, 5, 3, 6, 2, 7, 4, 8]

{1, 2, 3, 4} =.2 has been eliminated while 3 has been promoted.
{
    1, 3
}

1, 8->1 2, 7 > 2 3, 6 > 3 4, 5 > 4

                                 1,
    8, 2, 7, 3, 6, 4, 5 1, 4, 2, 3 1, 2

    1,
    8, 4, 5, 2, 7, 3, 6 1, 4, 2, 3 1, 2

                                      start = 1,
                                      end = n;

int low = 0, high = n - 1;
booll front = true;
if (front)
    > arr push in start{low = start++, low + 1 = end--}, !front;
low += 2;
else > arr push in end{{high = start++, high - 1end --}}, !front;
high -= 2;

1, 8,
    2, 7

    left[]

    1,
    2, 3, 4 1, 4->1 2, 3->2

                       1,
    2

    1,
    9 2, 8 3, 7 4, 6 5

    1,
    2, 3, 4, 5

    1,
    5 2, 4 3

    1,
    2, 3

    1,
    3 2

    1,
    2

    1,
    4 2, 3

         start = 1;
end = n;

{
    start++, end--
}