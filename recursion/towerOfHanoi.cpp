#include <iostream>
using namespace std;

/*
Goal: move n disks from source tower to another tower, an temporary holding tower
1. Move n-1 disks from tower C recursively
2. Move the largest remaining disk to tower B
3. Move n-1 disks back to tower B recursively
*/

void moveDisks(int n, char fromTower, char toTower, char tempTower);
int main()
{

    moveDisks(3, 'a', 'b', 'c');
}

void moveDisks(int n, char fromTower, char toTower, char tempTower)
{
    // basecase
    if (n == 1)
    {
        cout << "Move disk " << n << " from " << fromTower << " to " << toTower << endl;
    }
    else
    {
        // move n-1 disks from source to temporary
        moveDisks(n - 1, fromTower, tempTower, toTower);

        cout << "Move disk " << n << " from " << fromTower << " to " << toTower << endl;

        // move n-1 disks from temp tower to toTower
        moveDisks(n - 1, tempTower, toTower, fromTower);
    }
}
