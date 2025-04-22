#include <iostream>
#include <vector>
#include <string>

using namespace std;

int equalset(vector<int> &arr, int idx, int sum1, int sum2, string set1, string set2)
{
    if (idx == arr.size())
    {
        if (sum1 == sum2)
        {
            // cout<<"k";
            for (auto ele1 : set1)
                cout << ele1;
            cout << "=";
            for (auto ele2 : set2)
                cout << ele2;
            cout << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    count += equalset(arr, idx + 1, sum1 + arr[idx], sum2, set1 + to_string(arr[idx]) + " ", set2);
    count += equalset(arr, idx + 1, sum1, sum2 + arr[idx], set1, set2 + to_string(arr[idx]) + " ");

    return count;
}

int permutation(string str,string ans){

    if(str.length()==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<str.length();i++){
    char ch = str[i];
    string ros=str.substr(0,i)+str.substr(i+1);
    count+=permutation(ros,ans+ch);
    }
    return count;
}


int permutation1(string str,string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return 1;
    }

     vector<bool> vis(26,false);
    int count=0;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(!vis[ch-'a']){
        //ros=rest of string
        vis[ch-'a']= true;
        string ros = str.substr(0,i)+str.substr(i+1);
        count+=permutation1(ros,ch+ans);
        }
    }
    return count;
}

int permutation2(string str,string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return 1;
    }
 // this code will give only unique output but inout should be sorted
    int count=0;
    char prev='$';
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(prev!=ch){
            string ros= str.substr(0,i)+str.substr(i+1);
            count+=permutation2(ros,ch+ans);
        }
        prev=ch;
    }
    return count;
}

int printincreasaingorder(int a , int b){
    if(a == b){
        cout<<a<<endl;
        return a;
    }
        cout<<a<<" ";
        printincreasaingorder(a + 1, b);
}

int printdecreasaingorder(int a, int b){
    if (a == b){
        cout << b << endl;
        return b;
    }
    cout << b << "-";
    printdecreasaingorder(a, b - 1);
}


void printincreasaingDecreasingorder(int a, int b){
    if (a >  b){
        // cout << b << endl;
        return ;
    }
    cout << a << " ";
    printincreasaingDecreasingorder(a + 1, b);
    cout << a << " ";
}

// void printodd(int a , int b){
//     if(a == b){
//         if(a %2 != 0)
//         cout<<a<<" ";
//         return;
//     }
//     if (a % 2 != 0)
//         cout << a <<" ";
//     printodd(a+1,b);    
// }

// void printeven(int a , int b){
//     if (a == b)
//     {
//         if (a % 2 == 0)
//             cout << b <<" ";
//         return;
//     }
//     if (b % 2 == 0)
//         cout << b<<" ";
//     printeven(a, b - 1);
// }


void printoddeven(int a, int b){
    if(a > b)
    return;

    if(a % 2 != 0) 
    cout<<a<<" ";   

    printoddeven(a + 1 , b);
    if(a % 2 == 0)
    cout << a << " ";
}


int findmaximun(vector<int>&arr , int idx){
    if(idx == arr.size())
        return -(int)1e9;

    int maxSF = findmaximun(arr , idx + 1);
    return max(maxSF , arr[idx]);    
}

int findminimum(vector<int> &arr, int idx)
{
    if(idx == arr.size())
        return (int)1e9;

    int minSF = findminimum(arr , idx + 1);
    return min(minSF , arr[idx]);    
}

bool findidx(vector<int> &arr, int idx , int data)
{
    if(idx == arr.size())
        return false;

    if(arr[idx] == data)
        return true;

    findidx(arr, idx + 1 , data);        
}

int findFirstIdx(vector<int> &arr, int idx,int data )
{
      if (arr[idx] == data)
        return idx;
        
      if (idx == arr.size())
        return -(1e9);

    findFirstIdx(arr, idx + 1, data);
}

int findLastIdx(vector<int> &arr, int idx , int data )
{
    if(idx == arr.size())
        return -1;

    int tempval = findLastIdx(arr, idx + 1 , data);
    if(tempval != -1)
        return tempval;

    return (arr[idx] == data) ? idx : -1;        
}

vector<int> allIndex(vector<int> arr, int idx, int csize, int data)
{
    if (idx == arr.size())
    {
        vector<int>res(csize , 0);
        return res;
    }

    if (arr[idx] == data)
    {
        csize++;
    }
    vector<int> ans = allIndex(arr, idx + 1, csize, data);
    if (arr[idx] == data)
    {
        ans[csize - 1] = idx;
    }
    return ans;
}

void setsol()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80};

    int ans = equalset(arr, 1, arr[0], 0, to_string(arr[0]) + " ", " ");
    cout << ans;
}

void permutation_sol(){
 
    string str="aaab";
    
    //int ans1 = permutation(str,"");
    //int ans1 = permutation1(str, "");
    cout<<permutation2(str, "");
}

int main()
{
   // setsol();
   // permutation_sol();
      vector<int> arr = {10, 20, 30, 40, 20, 60, 20, 80, 40};
  //  bool ans = findidx(arr, 0, 40);
      vector<int> res = allIndex(arr, 0, 0 , 20);
      cout<<res.size()<<endl;
      for(auto ele : res){
        cout<<ele<<endl;
      }
      return 0;
}