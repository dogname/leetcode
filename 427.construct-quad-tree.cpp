/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution
{
public:
	Node* construct(vector<vector<int>>& grid)
	{
		return build(grid, 0, 0, grid.size());
	}
	Node* build(vector<vector<int>>& grid, int x, int y, int len)
	{
		if (len == 0) return nullptr;
		for (int i = x; i < x + len; ++i)
		{
			for (int j = y; j < y + len; ++j)
			{
				if (grid[i][j] != grid[x][y])
				{
					return new Node(true, false, build(grid, x, y, len / 2), build(grid, x, y + len / 2, len / 2), build(grid, x + len / 2, y, len / 2),
					                build(grid, x + len / 2, y + len / 2, len / 2));
				}
			}
		}
		return new Node(grid[x][y] == true, true, nullptr, nullptr, nullptr, nullptr);
	}
};
