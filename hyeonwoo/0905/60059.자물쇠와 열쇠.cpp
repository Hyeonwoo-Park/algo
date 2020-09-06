#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>> &key)
{
    for (int i = 0; i < key.size() / 2; ++i)
    {
        int j = key.size() - 1 - i;

        for (int x = 0; i + x < j; ++x)
        {
            int tmp = key[i][i + x];

            key[i][i + x] = key[i + x][j];
            key[i + x][j] = key[j][j - x];
            key[j][j - x] = key[j - x][i];
            key[j - x][i] = tmp;
        }
    }
}

bool chk(vector<vector<int>> &lock)
{
    for (auto const &l1 : lock)
    {
        for (auto const &l2 : l1)
        {
            if (l2 != 1)
                return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    int ks = key.size();
    int ls = lock.size();
    bool answer = false;
    int cnt = 0;

    for (int r = 0; r < 4; ++r)
    {
        int lxst = 0;
        int lxed = 0;
        int kxst = ks - 1;
        int kxed = ks - 1;

        for (int i = 1 - ks; i < (int)ls; i++)
        {
            int lyst = 0;
            int lyed = 0;
            int kyst = ks - 1;
            int kyed = ks - 1;

            for (int j = 1 - ks; j < (int)ls; ++j)
            {
                int kx = kxst;
                int lx = lxst;

                vector<vector<int>> ktmp = key;
                vector<vector<int>> ltmp = lock;

                while (kx <= kxed && lx <= lxed)
                {
                    int ky = kyst;
                    int ly = lyst;

                    while (ky <= kyed && ly <= lyed)
                    {
                        ltmp[lx][ly] += ktmp[kx][ky];
                        ky++;
                        ly++;
                    }
                    kx++;
                    lx++;
                }
                answer = chk(ltmp);

                if (j >= 0)
                    lyst++;
                if (lyed < ls - 1)
                    lyed++;
                if (kyst > 0)
                    kyst--;
                if (j >= ls - ks)
                    kyed--;

                if (answer)
                    break;
            }

            if (i >= 0)
                lxst++;
            if (lxed < ls - 1)
                lxed++;
            if (kxst > 0)
                kxst--;
            if (i >= ls - ks)
                kxed--;

            if (answer)
                break;
        }

        if (answer)
            break;

        rotate(key);
    }

    return answer;
}

int main()
{
    vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    cout << solution(key, lock);
}