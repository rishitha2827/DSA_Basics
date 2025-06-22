#include <bits/stdc++.h>
using namespace std;

/*
 * Function: largeEle
 * ------------------
 * Finds and returns the largest element in the array.
 */
int largeEle(vector<int> a) {
    int m = INT_MIN;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > m) m = a[i]; 
    }
    return m;
}

/*
 * Function: isSorted
 * ------------------
 * Checks if the array is sorted in non-decreasing order.
 * Returns true if sorted, false otherwise.
 */
bool isSorted(vector<int> a) {
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < a[i - 1]) return false;
    }
    return true;
}

/*
 * Function: secLargeEle
 * ---------------------
 * Finds and returns the second largest element in the array.
 */
int secLargeEle(vector<int> a) {
    int m = INT_MIN, sl = INT_MIN;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > m) {
            sl = m;
            m = a[i];
        } 
        if (a[i] > sl && a[i] != m) sl = a[i];
    }
    return sl;
}

/*
 * Function: linearSearch
 * ----------------------
 * Performs a linear search for value 'k' in the array.
 * Returns the value if found, otherwise -1.
 */
int linearSearch(vector<int> a, int k) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == k) return k;
    }
    return -1;
}

/*
 * Function: LeftRotateArrayByOnePlace
 * -----------------------------------
 * Rotates the array to the left by one position.
 * Modifies the array in-place.
 */
void LeftRotateArrayByOnePlace(vector<int> &a) {
    int m = a[0];
    for (int i = 1; i < a.size(); i++) {
        a[i - 1] = a[i];
    }
    a[a.size() - 1] = m;
}

/*
 * Function: print
 * ---------------
 * Prints all elements of the array on a single line.
 */
void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

/*
 * Function: main
 * --------------
 * Entry point of the program.
 * Accepts array input, then demonstrates:
 *  - finding largest element
 *  - checking if sorted
 *  - finding second largest element
 *  - performing linear search
 *  - left rotating the array by one place
 */
int main() {
    vector<int> a;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    a.resize(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Original array: ";
    print(a);

    cout << "Large Element: " << largeEle(a) << endl;
    cout << "Is sorted: " << isSorted(a) << endl;
    cout << "Second largest element: " << secLargeEle(a) << endl;
    cout << "Linear search (43): " << linearSearch(a, 43) << endl;

    LeftRotateArrayByOnePlace(a);
    cout << "Array after left rotation: ";
    print(a);

    return 0;
}
