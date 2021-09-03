#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int ask(int i, int j, string S)
{
    int answer;
    cout << S << " " << i << " " << j << "\n";
    cout.flush();
    cin >> answer;

    return answer;
}

int main()
{
    int no_of_elements, k;
    cin >> no_of_elements >> k;

    vector <int> A(no_of_elements + 1);

    int and_12 = ask(1, 2, "and");
    int or_12 = ask(1, 2, "or");
    int sum_12 = and_12 + or_12;

    int and_23 = ask(2, 3, "and");
    int or_23 = ask(2, 3, "or");
    int sum_23 = and_23 + or_23;

    int and_31 = ask(3, 1, "and");
    int or_31 = ask(3, 1, "or");
    int sum_31 = and_31 + or_31;

    A[1] = (sum_12 - sum_23 + sum_31)/2;
    A[2] = sum_12 - A[1];
    A[3] = sum_23 - A[2]; //cout << A[1] << " " << A[2] << " " << A[3] << "\n";

    for(int i = 4; i <= no_of_elements; i++)
    {
        int and_1i = ask(1, i, "and");
        int or_1i = ask(1, i, "or");
        int sum_1i = and_1i + or_1i;

        A[i] = sum_1i - A[1];//cout << A[i] << "\n";
    }

    sort(all(A));

    cout << "finish " << A[k] << "\n";
    return 0;
}
