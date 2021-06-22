#include <iostream>
#include <vector>;
#include <fstream>;

using namespace std;

int main()
{
    vector <int> nums;
    int temp;

    ifstream File;
    File.open("file.txt");

    try
    {
        while (File >> temp)
            nums.push_back(temp);

        throw 1;
    }
    catch (int a)
    {
        cout << "error" << endl;
    }

    File.close();

    cout << "vector\n";

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << "\t";
    cout << endl;
}
