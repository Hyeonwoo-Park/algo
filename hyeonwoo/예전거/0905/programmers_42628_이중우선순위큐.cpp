#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    deque<int> q;

    for (auto const &op : operations)
    {
        char opcode = op[0];
        int num = stoi(op.substr(2));

        switch (opcode)
        {
        case 'I':
            q.push_back(num);
            break;
        case 'D':
            if (q.empty())
                continue;

            sort(q.begin(), q.end());

            if (num == 1)
            {
                q.pop_back();
            }
            else
            {
                q.pop_front();
            }
        }
    }

    if (q.empty())
    {
        q.push_back(0);
    }

    sort(q.begin(), q.end());

    answer.push_back(q.back());
    answer.push_back(q.front());

    return answer;
}