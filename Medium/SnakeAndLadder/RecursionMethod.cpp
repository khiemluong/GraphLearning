#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int t[31];

// recursive function
int sol(int i, unordered_map<int, int>& h)
{
    // base condition
    if (i >= 30)
        return 0;

    // checking if block is already visited or
    // not(memoization).
    else if (t[i] != -1)
        return t[i];

    // initialising min as max int value
    int min_value = INT_MAX;

    // for loop for every dice value from 1 to 6
    for (int j = 1; j <= 6; j++) {
        // incrementing value of i with dice value i.e j
        // taking new variable k
        //->taking new variable so that we dont change i
        // as we will need it again in another iteration
        int k = i + j;
        if (h.count(k) > 0) {
            // checking if this is a snake or ladder
            // if a snake then we continue as we dont
            // need a snake
            if (h[k] < k)
                continue;
            // updating if it's a ladder to ladder end value
            k = h[k];
        }
        // updating min in every iteration for getting
        // minimum throws from this particular block
        min_value = min(min_value, sol(k, h) + 1);
    }
    // updating value of t[i] to min
    // memoization
    t[i] = min_value;
    return t[i];
}

int min_throw(int n, vector<int> arr)
{
    // Initialise an array t of length 31, we will use from
    // index to 1 to 30
    for (int i = 0; i < 31; i++) {
        // initialising every index of t with -1
        t[i] = -1;
    }

    // create a dictionary to store snakes and ladders start
    // and end for better efficiency
    unordered_map<int, int> h;
    for (int i = 0; i < 2 * n; i += 2) {
        // store start as key and end as value
        h[arr[i]] = arr[i + 1];
    }

    // final ans
    return sol(1, h);
}

int main()
{
    // Given a 5x6 snakes and ladders board
    // You are given an integer N denoting the total
    // number of snakes and ladders and a list arr[]
    // of 2*N size where 2*i and (2*i + 1)th values
    // denote the starting and ending point respectively
    // of ith snake or ladder
    int N = 8;
    vector<int> arr{ 3,  22, 5,  8, 11, 26, 20, 29,
                     17, 4,  19, 7, 27, 1,  29, 9 };

    cout << "Min Dice throws required is "
         << min_throw(N, arr) << endl;

    return 0;
}
// This code is contributed by sanjanasikarwar24