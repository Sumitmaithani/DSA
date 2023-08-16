Kars is tired and resentful of the narrow mindset of his village since they are content with staying where they are and are not trying to become the perfect life form. Being a top-notch inventor, Kars wishes to enhance his body and become the perfect life form. Unfortunately, n
 of the villagers have become suspicious of his ideas. The i
-th villager has a suspicion of ai
 on him. Individually each villager is scared of Kars, so they form into groups to be more powerful.

The power of the group of villagers from l
 to r
 be defined as f(l,r)
 where

f(l,r)=|al−al+1|+|al+1−al+2|+…+|ar−1−ar|.
Here |x−y|
 is the absolute value of x−y
. A group with only one villager has a power of 0
.

Kars wants to break the villagers into exactly k
 contiguous subgroups so that the sum of their power is minimized. Formally, he must find k−1
 positive integers 1≤r1<r2<…<rk−1<n
 such that f(1,r1)+f(r1+1,r2)+…+f(rk−1+1,n)
 is minimised. Help Kars in finding the minimum value of f(1,r1)+f(r1+1,r2)+…+f(rk−1+1,n)
.

Input
The first line contains a single integer t
 (1≤t≤100)
 — the number of test cases. The description of test cases follows.

The first line of each test case contains two integers n,k
 (1≤k≤n≤100)
 — the number of villagers and the number of groups they must be split into.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤500)
 — the suspicion of each of the villagers.

Output
For each test case, output a single integer — the minimum possible value of sum of power of all the groups i. e. the minimum possible value of f(1,r1)+f(r1+1,r2)+…+f(rk−1+1,n)
.

Example
inputCopy
3
4 2
1 3 5 2
6 3
1 9 12 4 7 2
12 8
1 9 8 2 3 3 1 8 7 7 9 2
outputCopy
4
11
2
Note
In the first test case, we will group the villagers with suspicion (1,3,5,2)
 into (1,3,5)
 and (2)
. So, f(1,3)+f(4,4)=(|1−3|+|3−5|)+0=4+0=4
.

In the second test case, we will group the villagers with suspicion (1,9,12,4,7,2)
 into (1),(9,12),(4,7,2)
. So, f(1,1)+f(2,3)+f(4,6)=0+3+8=11
.