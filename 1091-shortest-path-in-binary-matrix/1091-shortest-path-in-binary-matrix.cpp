class Solution {
public:

	int dirx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
	int diry[8] = {1, -1, 0, 0, -1, 1, -1, 1};

	int shortestPathBinaryMatrix(vector<vector<int>>& a) {
		int n = a.size();
		if (a[0][0] != 0 || a[n - 1][n - 1] != 0)
		{
			return -1;
		}
		queue<pair<int, int>>q;
		q.push({0, 0});
		int step = 0;
		int size = 0;
		int x , y, newx, newy;
		while (!q.empty())
		{
			step++;
			size = q.size();
			while (size--)
			{
				x = q.front().first;
				y = q.front().second;
				q.pop();
				if (x == n - 1 && y == n - 1)
				{
					return step;
				}
				for (int i = 0; i < 8; i++)
				{
					newx = x + dirx[i];
					newy = y + diry[i];
					if (newx >= 0 && newx < n && newy >= 0 && newy < n && a[newx][newy] == 0)
					{
						a[newx][newy] = 1;
						q.push({newx, newy});
					}
				}
			}
		}

		return -1;
	}
};