#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

#define ll long long

// calculation of factorial by iteration
ll factIteration (ll number){
    ll a = number;
    while (number--){
        if (number == 0) break;
        a *= number;
    } 
    return a;
}

ll factRecursion(ll number){
    if (number < 1) return 1;
    return number * factRecursion(number - 1);
}

int main(){
    ll choice = 1;
       
    do {
        cout << "Enter your choice  \n1 for Iterative \n2 for recursive : ";
        cin >> choice;

        if(choice == 1 || choice == 2){
            ll number;
            cout << "Enter number : ";
            cin >> number;

            switch (choice) {
                case 1:
                {
                    auto start = high_resolution_clock::now(); 
                    ll ans1 = factIteration(number);
                    cout << "Factorial by Iteration : " << ans1 << "\n";
                    auto stop1 = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop1 - start);
                    cout << "Time taken : " << duration.count() << " microseconds.\n\n\n";
                    break;
                }
                case 2:
                {
                    auto start = high_resolution_clock::now(); 
                    ll ans2 = factRecursion(number);
                    cout << "Factorial by Recursion : " << ans2 << "\n";
                    auto stop1 = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop1 - start);
                    cout << "Time taken : " << duration.count() << " microseconds.\n\n\n";
                    break;
                }
            }
        }
        else break;
    }while(true);

    cout << "Wrong choice programme terminated.\n";
    return 0;

}
