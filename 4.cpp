#include <iostream>
#include <map>

using namespace std;


int len_number(int n) {
    int len[] = { 4, 3 , 3, 6, 5, 5, 3, 5, 7, 6, 10, 10, 10, 12, 11, 11, 10, 13, 13, 8 };
    int len_des[] = { 0, 0, 8, 8, 5, 9, 9, 8, 10, 10 };
    int len_sot[] = { 3, 6, 6, 9, 7, 7, 6, 8, 8 };
    long int len_num = 0;
    if (n == 0) { len_num = 4; }
    int des = 0, count = 0, count1 = 0;
    while (true) {
        count++;
        int k = n % 10;
        if (count == 1) {
            if (n <= 20) {
                len_num += len[n - 1];
                break;
            }
            des = k;
            len_num += len[k - 1];
        }
        if (count == 2 && k != 0) {
            des = k * 10 + des;

            if (des > 20 && des < 99) {
                if (des == 30 || des == 40 || des == 50 || des == 60 || des == 70 || des == 80 || des == 90) {
                    len_num += len_des[des / 10];
                    des = 0;
                }
                else {
                    len_num += len[des % 10 - 1];
                    len_num += len_des[des / 10];
                    des = 0;
                }
            }
        }
        if (count == 3 && k != 0) {
            len_num += len_sot[k - 1];
        }
        if (count == 4 && k != 0) {
            len_num += 6;
            count1++;
            int e = n % 10;
            if (count1 == 1) {
                des = e;
                len_num += len[des - 1];
            }
            if (count1 == 2) {
                des = e * 10 + des;
                if (des <= 20) {
                    len_num += len[des - 1];
                }
                if (des > 20 && des < 99) {
                    if (des == 30 || des == 40 || des == 50 || des == 60 || des == 70 || des == 80 || des == 90) {
                        len_num += len_des[des / 10];
                    }
                    else {
                        len_num += len[des % 10 - 1];
                        len_num += len_des[des / 10];
                    }
                }
            }
        }
        n = (n - k) / 10;

        if (n == 0) {
            break;
        }
    }
    return len_num;
}

int main() {
    map <int, int> num_letters;
    int n;
    cout << "Input n:";
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        num_letters[i] = len_number(i);
    }
    map<int, int>::const_iterator it = num_letters.begin();
    for (it; it != num_letters.end(); ++it) {
        if (it->first == it->second) {
            cout << "f(" << it->first << ")=" << it->second << endl;
        }
    }
}