class Solution
{
public:
	int findContentChildren(vector<int> &g, vector<int> &s)
	{
		// g = greedy children
		// s = cookie size

		// descending sort
		std::ranges::sort(g, std::ranges::greater());
		std::ranges::sort(s, std::ranges::greater());

		int numContentKids = 0;

		// check that each cookie satisfies a child, and if not, skip that child
		for (auto sIt = s.begin(), gIt = g.begin(); sIt != s.end() && gIt != g.end();)
		{
			if (*sIt >= *gIt)
			{
				++numContentKids;
				++sIt;
			}

			++gIt;
		}

		return numContentKids;
	}
};