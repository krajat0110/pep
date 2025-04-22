#include<iostream>
#include<vector>
using namespace std;

//34
vector<int> searchRange(vector<int> &nums, int target)
{
    int start = 0, end = nums.size(), mid, left, right;

    while (start < end)
    {
        mid = (start + end) / 2;
        if (nums[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }

    left = end;

    start = 0, end = nums.size();
    while (start < end)
    {
        mid = (start + end) / 2;
        if (nums[mid] > target)
            end = mid;
        else
            start = mid + 1;
    }

    right = start;

    return left == right ? vector<int>{-1, -1} : vector<int>{left, right - 1};
}

// 35. Search Insert Position
int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size(), si = 0, ei = n - 1;

    while (si <= ei)
    {
        int mid = si + (ei - si) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] > target)
        {
            ei = mid - 1;
        }
        else
        {
            si = mid + 1;
        }
    }
    return si;
}

int nearestElement(vector<int> &arr, int target)
{
   int n = arr.size();
   if(n == 0 ) return -1;

   if(n == 1) return arr[0];

   if(target <= arr[0]  || target >= arr[n-1]){
       return target <= arr[0] ? arr[0] : arr[n-1];
   }

   int si = 0 , ei = n - 1;
   while(si <= ei){
     int mid = (ei + si)/2;

     if(arr[mid] == target) return arr[mid];

     if(arr[mid] > target){
        mid = ei - 1;
     }else{
        si = mid + 1;
     }
   }
   return target - arr[ei] <= target - arr[si] ? arr[ei] : arr[si];
}

// 74. Search a 2D Matrix
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int si = 0, ei = n * m - 1;
    while (si <= ei)
    {
        int mid = (ei + si) / 2;
        int r = mid / m, c = mid % m;
        if (matrix[r][c] == target)
            return true;
        if (matrix[r][c] > target)
        {
            ei = mid - 1;
        }
        else
        {
            si = mid + 1;
        }
    }
    return false;
}

bool searchMatrix_02(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size(), si = n - 1, ei = 0;
    while (si >= 0 && ei < m)
    {
        int ele = matrix[si][ei];
        if (ele == target)
            return true;
        ele > target ? si-- : ei++;
    }
    return false;
}

// https://leetcode.com/problems/search-a-2d-matrix-ii/

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size(), si = n - 1, ei = 0;
    while (si >= 0 && ei < m)
    {
        int ele = matrix[si][ei];
        if (ele == target)
            return true;
        ele > target ? si-- : ei++;
    }
    return false;
}

// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/

long long inversionAcrossArray(vector<long long> &arr, int l, int r, int mid, vector<long long> &sortedArray)
{
    int lsi = l, lei = mid;
    int rsi = mid + 1, rei = r;
    // cout<<lsi<<" "<<lei<<"->"<<rsi<<" "<<rei<<endl;
    int k = 0;
    long cnt = 0;
    while (lsi <= lei && rsi <= rei)
    {
        if (arr[lsi] > arr[rsi])
        {
            cnt += (lei - lsi + 1);
            sortedArray[k++] = arr[rsi++];
        }
        else
            sortedArray[k++] = arr[lsi++];
    }
    while (lsi <= lei)
        sortedArray[k++] = arr[lsi++];

    while (rsi <= rei)
        sortedArray[k++] = arr[rsi++];
    k = 0;
    for (int i = l; i <= r; i++)
        arr[i] = sortedArray[k++];
    return cnt;
}

long long inversionCount01(vector<long long> &arr, int si, int ei, vector<long long> &sortedArray)
{
    if (si >= ei) return 0;

    int mid = (si + ei) / 2;

    long ICL = inversionCount01(arr, si, mid, sortedArray);
    long ICR = inversionCount01(arr, mid + 1, ei, sortedArray);

    return (ICR + ICL + inversionAcrossArray(arr, si, ei, mid, sortedArray));
}

long long inversionCount(long long ar[], long long N)
{
    if (N <= 1) return 0;
    vector<long long> arr;
    for (int i = 0; i < N; i++)
        arr.push_back(ar[i]);

    vector<long long> sortedArray(N, 0);
    return inversionCount01(arr, 0, (int)N - 1, sortedArray);
}

int main(){

}