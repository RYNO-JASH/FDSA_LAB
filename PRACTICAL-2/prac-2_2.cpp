#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binaryFindBookCode(vector<int> &arr, int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] > key)
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

int recursivebinaryFindBookCode(vector<int> &arr, int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;

    else if (arr[mid] > key)
        return recursivebinaryFindBookCode(arr, low, mid - 1, key);

    else
        return recursivebinaryFindBookCode(arr, mid + 1, high, key);
}

int main()
{
    int n, key, type;

    cout << "Enter num of Book Size : ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter Book Codes : " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    cout << "Sorted Book Codes : ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "Enter type for normal binary or recursive binary (1 or 2): ";
    cin >> type;

    if (type == 1 || type == 2)
    {
        cout << "Enter the number to search: ";
        cin >> key;

        int value;

        if (type == 1)
        {
            value = binaryFindBookCode(arr, n, key);
        }
        else
        {
            value = recursivebinaryFindBookCode(arr, 0, n - 1, key);
        }

        if (value >= 0)
        {
            cout << "Found Book Code = " << arr[value] << endl;
            cout << "At position = " << value + 1 << endl;
        }
        else
        {
            cout << "Book Code not found !!!" << endl;
        }
    }
    else
    {
        cout << "Invalid input" << endl;
    }

    return 0;
}
