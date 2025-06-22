#include <bits/stdc++.h>
using namespace std;

/* 
 * Function: maxConsecutiveOnes
 * ----------------------------
 * Finds the maximum number of consecutive 1s in a binary array.
 */
int maxConsecutiveOnes(vector<int> a) {
    int c = 0, maxOnes = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 1) {
            c++;
        } else {
            c = 0;
        }
        maxOnes = max(maxOnes, c);
    }
    return maxOnes;
}

/*
 * Function: moveZerosToEnd
 * ------------------------
 * Moves all zeros in the array to the end while maintaining the order of other elements.
 */
vector<int> moveZerosToEnd(vector<int> a) {
    int j = -1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }
    if (j == -1) return a;

    for (int i = j + 1; i < a.size(); i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

/*
 * Function: Reverse
 * -----------------
 * Reverses the elements between indices s and e in the array.
 */
void Reverse(vector<int> &a, int s, int e) {
    while (s <= e) {
        swap(a[s], a[e]);
        s++;
        e--;
    }
}

/*
 * Function: RotateLeftToRight
 * ---------------------------
 * Rotates the array to the right by k positions.
 */
void RotateLeftToRight(vector<int> &a, int k) {
    int n = a.size();
    k = k % n; // handle cases where k > n
    Reverse(a, 0, n - k - 1);
    Reverse(a, n - k, n - 1);
    Reverse(a, 0, n - 1);
}

/*
 * Function: removeDuplicates
 * --------------------------
 * Removes duplicates from a sorted array and returns the new size.
 */
int removeDuplicates(vector<int> &a) {
    if (a.empty()) return 0;
    int i = 0;
    for (int j = 1; j < a.size(); j++) {
        if (a[i] != a[j]) {
            i++;
            a[i] = a[j];
        }
    }
    return i + 1;
}

/*
 * Function: missingNumber
 * -----------------------
 * Given N-1 numbers from 1 to N, finds the missing number using XOR.
 */
int missingNumber(vector<int> a, int n) {
    int x1 = 0, x2 = 0;
    for (int i = 0; i < a.size(); i++) {
        x1 ^= a[i];
        x2 ^= (i + 1);
    }
    x2 ^= n;
    return x1 ^ x2;
}

/*
 * Function: getSingleElement
 * --------------------------
 * Finds the element that appears only once in an array where others appear twice.
 */
int getSingleElement(vector<int> &a) {
    int x = 0;
    for (int i = 0; i < a.size(); i++) {
        x ^= a[i];
    }
    return x;
}

/*
 * Function: FindUnion
 * -------------------
 * Finds the union of two sorted arrays without duplicates.
 */
vector<int> FindUnion(int a1[], int a2[], int n, int m) {
    vector<int> resArr;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a1[i] <= a2[j]) {
            if (resArr.empty() || resArr.back() != a1[i])
                resArr.push_back(a1[i]);
            i++;
        } else {
            if (resArr.empty() || resArr.back() != a2[j])
                resArr.push_back(a2[j]);
            j++;
        }
    }

    while (i < n) {
        if (resArr.empty() || resArr.back() != a1[i])
            resArr.push_back(a1[i]);
        i++;
    }

    while (j < m) {
        if (resArr.empty() || resArr.back() != a2[j])
            resArr.push_back(a2[j]);
        j++;
    }

    return resArr;
}

/*
 * Function: twoSum
 * ----------------
 * Returns indices of the two numbers such that they add up to the target.
 */
vector<int> twoSum(int n, vector<int> &a, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int number = a[i];
        int need = target - number;
        if (mpp.find(need) != mpp.end()) {
            return {mpp[need], i};
        }
        mpp[number] = i;
    }
    return {-1, -1};
}

// Driver code
int main() {
    // 1. Test maxConsecutiveOnes
    vector<int> a = {1, 0, 1, 1, 0, 1};
    cout << "Max consecutive ones: " << maxConsecutiveOnes(a) << endl;

    // 2. Test moveZerosToEnd
    vector<int> moved = moveZerosToEnd(a);
    cout << "After moving zeros to end: ";
    for (auto &it : moved) cout << it << " ";
    cout << '\n';

    // 3. Test RotateLeftToRight
    RotateLeftToRight(a, 3);
    cout << "After rotating 3 elements to right: ";
    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;

    // 4. Test removeDuplicates
    sort(a.begin(), a.end()); // Required for removeDuplicates
    int k = removeDuplicates(a);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) cout << a[i] << " ";
    cout << endl;

    // 5. Test missingNumber
    int N = 5;
    vector<int> b = {1, 2, 4, 5}; // Missing 3
    int missing = missingNumber(b, N);
    cout << "The missing number is: " << missing << endl;

    // 6. Test getSingleElement
    vector<int> arr1 = {4, 1, 2, 1, 2};
    int single = getSingleElement(arr1);
    cout << "The single element is: " << single << endl;

    // 7. Test FindUnion
    int n1 = 10, m1 = 7;
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr3[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = FindUnion(arr2, arr3, n1, m1);
    cout << "Union of arr1 and arr2 is: ";
    for (auto &val : Union) cout << val << " ";
    cout << endl;

    // 8. Test twoSum
    int n2 = 5;
    vector<int> arr4 = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(n2, arr4, target);
    cout << "Two sum result (indices): [" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}
