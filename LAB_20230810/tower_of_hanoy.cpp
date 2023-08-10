#include <bits/stdc++.h>
using namespace std;

void tower_of_hanoy(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
        return;
    }

    tower_of_hanoy(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    tower_of_hanoy(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    tower_of_hanoy(n, 'A', 'C', 'B');

    return 0;
}

 /*
 Tower of Hanoi
 ==============
 Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
    1. Only one disk can be moved at a time.
    2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
    3. No disk may be placed on top of a smaller disk.
    4. The puzzle has a recursive solution.
    5. The minimum number of moves required to solve a Tower of Hanoi puzzle is 2n - 1, where n is the number of disks.

    Psudo-Code:
    1. Move n-1 disks from source to aux.
    2. Move nth disk from source to dest.
    3. Move n-1 disks from aux to dest.
    
    Algorithm:
    tower_of_hanoy(n, from_rod, to_rod, aux_rod)
    {
        if (n == 1)
        {
            cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
            return;
        }

        tower_of_hanoy(n - 1, from_rod, aux_rod, to_rod);
        cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
        tower_of_hanoy(n - 1, aux_rod, to_rod, from_rod);
    }

    Time Complexity: O(2^n)
    Space Complexity: O(n)


 */