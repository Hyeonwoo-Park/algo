#include <algorithm>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works)
{
    priority_queue<int> pq;
    long long answer = 0;

    for (auto const &work : works)
    {
        pq.push(work);
    }

    while (n-- && !pq.empty())
    {
        int work = pq.top() - 1;
        pq.pop();

        if (work > 0)
            pq.push(work);
    }

    while (!pq.empty())
    {
        int work = pq.top();
        pq.pop();

        answer += work * work;
    }

    return answer;
}