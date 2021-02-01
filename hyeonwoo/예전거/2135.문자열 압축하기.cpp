#include <bits/stdc++.h>

using namespace std;

int dealer = 0;
int dealerA = 0;
int dealerOpened = 0;

int player = 0;
int playerA = 0;

int gameInd = 0;
int turn = 0;

void reset()
{
	dealer = 0;
	dealerA = 0;
	dealerOpened = 0;

	player = 0;
	playerA = 0;

	gameInd = -1;
	turn = 0;
}

int calcA(int n, int a)
{
	int maximum = n + a;

	for (int i = 0; i <= a; ++i)
	{
		int x = n + (11 * i) + a - i;

		if (x > 21)
			continue;

		maximum = max(x, maximum);
	}

	return maximum;
}

int solution(vector<int> cards)
{
	int answer = 0;

	for (int i = 0; i < cards.size(); ++i)
	{
		int card = cards[i] > 10 ? 10 : cards[i];

		if (gameInd == 0 || gameInd == 2)
		{
			if (card == 1)
			{
				playerA++;
			}
			else
			{
				player += card;
			}
		}
		else if (gameInd == 1)
		{
			if (card == 1)
			{
				dealerA++;
			}
			else
			{
				dealer += card;
			}
		}
		else if (gameInd == 3)
		{
			dealerOpened += card;

			if (card == 1)
			{
				dealerA++;
			}
			else
			{
				dealer += card;
			}
		}
		else if (turn == 0)
		{
			if (card == 1)
			{
				playerA++;
			}
			else
			{
				player += card;
			}
		}
		else
		{
			if (card == 1)
			{
				dealerA++;
			}
			else
			{
				dealer += card;
			}
		}

		if (gameInd >= 3)
		{
			if (turn == 0)
			{
				int playerScore = calcA(player, playerA);

				if (playerScore > 21)
				{
					answer -= 2;
					reset();
					continue;
				}
				else if (playerScore == 21)
				{
					int dealerScore = calcA(dealer, dealerA);

					if (dealerScore != 21)
					{
						answer += 3;
					}

					reset();
				}

				if (dealerOpened >= 4 && dealerOpened <= 6)
				{
					turn = 1;
				}
				else if (dealerOpened == 1 || dealerOpened >= 7)
				{
					if (calcA(player, playerA) >= 17)
					{
						turn = 1;
					}
				}
				else
				{
					if (calcA(player, playerA) >= 12)
					{
						turn = 1;
					}
				}
			}
			if (turn == 1)
			{
				int dealerScore = calcA(dealer, dealerA);
				int playerScore = calcA(player, playerA);

				if (dealerScore >= 22)
				{
					answer += 2;
					reset();
				}
				else if (dealerScore >= 17)
				{
					if (dealerScore > playerScore)
					{
						answer -= 2;
					}
					else if (dealerScore < playerScore)
					{
						answer += 2;
					}
					reset();
				}
			}
		}
		gameInd++;
	}

	return answer;
}

int main()
{
	vector<int> a = {12, 7, 11, 6, 2, 12};
	vector<int> b = {1, 4, 10, 6, 9, 1, 8, 13};
	vector<int> c = {10, 13, 10, 1, 2, 3, 4, 5, 6, 2};
	vector<int> d = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

	// cout << solution(a) << endl;
	// cout << solution(b) << endl;
	// cout << solution(c) << endl;
	cout << solution(d) << endl;
}