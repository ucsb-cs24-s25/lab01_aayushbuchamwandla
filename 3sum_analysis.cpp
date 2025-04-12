#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include <chrono>



using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        bool isDup;
        vector<vector<int>> newVect = {};
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums.size(); j++){
                for (int k = 0; k < nums.size(); k++){
                    if (!((i==j)||(j==k)||(i==k))){
                        if (nums[i]+nums[j]+nums[k]==0){
                            isDup = false;
                            vector<int> current = {nums[i],nums[j],nums[k]};
                            sort(current.begin(), current.end());
                            for (int n = 0; n < newVect.size(); n++){
                                vector<int> sortedCurrent = newVect[n];
                                sort(current.begin(), current.end());
                                if (sortedCurrent == current){
                                    isDup = true;
                                    break;
                                }
                            }
                            if (!isDup){
                                newVect.push_back(current);
                            }
                        }
                    }
                }
            }
        }

        return newVect;
    }
};

vector<int> generateArray(int n){
    vector<int> vect(n);
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < n; i++){
        vect[i] = rand() % 2001 - 1000;
    }
    int a = rand() % 500 - 250;
    int b = rand() % 2001 - 100;
    vect.push_back(a);
    vect.push_back(b);
    vect.push_back(-a-b);
    return vect;
}

int main(){
    Solution solution;
    vector<int> sizes = {100, 200, 400, 800, 1600, 3200, 4000};
    for (int i = 0; i < sizes.size(); i++){
        vector<int> nums = generateArray(sizes[i]);
        auto start = chrono::high_resolution_clock::now();
        vector<vector<int>> result = solution.threeSum(nums);
        auto end = chrono::high_resolution_clock::now();
        double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
        cout << "Size: " << sizes[i] << " | Runtime:" << time_ms << "ms" << endl;
    }

    return 0;
}

