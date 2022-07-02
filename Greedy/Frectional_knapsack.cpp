// Greedy method Fractional knapsack problem
#include<bits/stdc++.h>
using namespace std;

class input{
public:
    int weight;
    int profit;
    float p_by_w;
    input(int w,int p){
        weight = w;
        profit = p;
        p_by_w = (float)p/(float)w;
    }


};

bool sortByWeight(const input a,const input b){
    return a.weight < b.weight;
}

bool sortByProfit(const input a,const input b){
    return a.profit > b.profit;
}
bool sortByFraction(const input a,const input b){
    return a.p_by_w > b.p_by_w;
}

int main(){
    int n,size;
    float sum =0;
    cout << "Enter number of objects : ";
    cin >> n;
    cout <<  "Enter size of Knapsack : ";
    cin >> size;
    input *arr = (input *) malloc(sizeof(input) * n);
    for(int i =0;i<n;i++){
        cout << "Object "<<i+1<<"\n";
        int w,p;
        cout << "Enter weight : ";cin >> w;
        cout << "Enter profit : ";cin >> p;
        arr[i] = input(w,p);
        cout<<"\n";
    }
    
    // Method 1: minimum weight first.
    sort(arr,arr+n,sortByWeight);
    int temp = size;
    for(int i=0;i<n;i++){
        if(arr[i].weight <= temp){
            temp -= arr[i].weight;
            sum += arr[i].profit;
        }
        else{
            if (temp == 0) break;
            float frac = (float)temp/(float)arr[i].weight;
            sum += ((float)arr[i].profit)*frac;
            break;
        }
    }
    cout << "Sum (Minimun weight first) : " << sum <<"\n";

    
    // Method 2: maximum profit first.
    sum = 0;
    sort(arr,arr+n,sortByProfit);
    temp = size;
    for(int i=0;i<n;i++){
        if(arr[i].weight <= temp){
            temp -= arr[i].weight;
            sum += arr[i].profit;
        }
        else{
            if (temp == 0) break;
            float frac = (float)temp/(float)arr[i].weight;
            sum += ((float)arr[i].profit)*frac;
            break;
        }
    }
    cout << "Sum (Maximum profit first) : " << sum <<"\n";

    // Method 3: Greedy Approch.
    sum = 0;
    sort(arr,arr+n,sortByFraction);
    temp = size;
    for(int i=0;i<n;i++){
        if(arr[i].weight <= temp){
            temp -= arr[i].weight;
            sum += arr[i].profit;
        }
        else{
            if (temp == 0) break;
            float frac = (float)temp/(float)arr[i].weight;
            sum += ((float)arr[i].profit)*frac;
            break;
        }
    }
    cout << "Sum (Greedy Approch) : " << sum <<"\n";


}