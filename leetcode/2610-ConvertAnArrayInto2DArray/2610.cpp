class Solution
{
public:
	vector<vector<int>> findMatrix(vector<int> &nums)
	{
		std::sort(nums.begin(), nums.end());
		vector<vector<int>> result{};

		std::size_t index{};

		for (auto num : nums)
		{
			bool placed = false;
			for (auto &v : result)
			{
				if (num != v.back())
				{
					v.push_back(num);
					placed = true;
					break;
				}
			}

			if (placed == false)
			{
				result.push_back(vector<int>{num});
			}
		}

		return result;
	}
};