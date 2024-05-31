#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> &nums, int k) {
    int n = nums.size();
    for (int i = 0; i < n; i++)
        if (nums[i] == k)
            return i;
    return -1;
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << "Enter the element to find: ";
    cin >> k;
    int index = linearSearch(nums, k);
    if (index == -1)
        cout << "Element not found." << endl;
    else
        cout << "Element found at index " << index << " ." << endl;
    return 0;
}
