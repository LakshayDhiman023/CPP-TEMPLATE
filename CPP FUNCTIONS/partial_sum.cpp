#include <bits/stdc++.h>
using namespace std;
struct dice_roll{
    int low, high;
};

void output(const vector<int> &v){
    for(auto it: v) cout<<it<<" ";
    cout<<endl;
}

void output(const vector<dice_roll> &v){
    for(auto it: v){
        cout<<it.low <<" "<<it.high<<endl;
    }
    cout<<endl;
}

int multiply(const int &a, const int &b){
    return a * b;
}



dice_roll customAdd(const dice_roll &a, const dice_roll &b){
    dice_roll res;
    res.low = a.low + b.low;
    res.high = a.high + b.high;
    return res;
}

int main(){
    
    // Prefix sum 

    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> r1(5) ;
    partial_sum(v1.begin(), v1.end(), r1.begin());

    
    output(r1);


    // prefix multiplication
    vector<int> r2(5);
    partial_sum(v1.begin(), v1.end(), r2.begin(), multiply);
    output(r2);

    // custom data structure prefix sum
    vector<dice_roll> v2 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    vector<dice_roll> r3(5);
    partial_sum(v2.begin(), v2.end(), r3.begin(), customAdd);
    output(r3);
    
}