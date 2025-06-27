#include<bits/stdc++.h>
using namespace std;

void linearPrint(vector<int> &v) {
	cout << "Linear printing: " << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << "Array[" << i << "] = " << v[i] << endl;
	}
}

void reversePrint(vector<int> &v) {
	cout << "Reverse printing: " << endl;
	for (int i = static_cast<int>(v.size()) - 1; i >= 0; i--) {
		cout << "Array[" << i << "] = " << v[i] << endl;
	}
}

void insertPos(vector<int> &v, int num, int pos) {
	if (pos < 0 || pos > v.size()) {
		cout << "Invalid position for insertion!" << endl;
		return;
	}
	cout << "After Insertion: " << endl;
	v.push_back(0);
	for (int i = v.size() - 1; i > pos; i--) {
		v[i] = v[i - 1];
	}
	v[pos] = num;
}

void deleteAtSpecific(vector<int> &v, int pos) {
	if (pos < 0 || pos >= v.size()) {
		cout << "Invalid position for deletion!" << endl;
		return;
	}
	cout << "After deletion: " << endl;
	for (int i = pos; i < v.size() - 1; i++) {
		v[i] = v[i + 1];
	}
	v.pop_back();
}

int linearSearch(vector<int> &v, int num) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == num) {
			return i;
		}

	}
	return -1;
}

int main() {

	vector<int> v = {1, 43, 6, 3, 89, 65, 90, 2};
	linearPrint(v);
	reversePrint(v);
	insertPos(v, 25, 8);
	linearPrint(v);
	deleteAtSpecific(v, 7);
	linearPrint(v);
	cout << "Element is at the position: " << linearSearch(v, 25);
	return 0;
}
