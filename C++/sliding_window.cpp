#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements that are out of the current window from the front of the deque
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove elements that are less than the current element from the back of the deque
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add the current element's index to the back of the deque
        dq.push_back(i);

        // If we have processed at least k elements, add the maximum to the result
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the size of the sliding window: ";
    cin >> k;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Maximums in sliding window of size " << k << " are: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
