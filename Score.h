#pragma once
class Score
{

private:

	int score;

public:

	Score();
	Score(int s);

	void SetScore(int s) { score = s; };
	int GetScore(void) { return score; };

};

