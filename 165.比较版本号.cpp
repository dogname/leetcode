/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 *
 * https://leetcode-cn.com/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (41.48%)
 * Likes:    81
 * Dislikes: 0
 * Total Accepted:    18.2K
 * Total Submissions: 44K
 * Testcase Example:  '"0.1"\n"1.1"'
 *
 * 比较两个版本号 version1 和 version2。
 * 如果 version1 > version2 返回 1，如果 version1 < version2 返回 -1， 除此之外返回 0。
 *
 * 你可以假设版本字符串非空，并且只包含数字和 . 字符。
 *
 * . 字符不代表小数点，而是用于分隔数字序列。
 *
 * 例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。
 *
 * 你可以假设版本号的每一级的默认修订版号为 0。例如，版本号 3.4 的第一级（大版本）和第二级（小版本）修订号分别为 3 和
 * 4。其第三级和第四级修订号均为 0。
 *
 *
 * 示例 1:
 *
 * 输入: version1 = "0.1", version2 = "1.1"
 * 输出: -1
 *
 * 示例 2:
 *
 * 输入: version1 = "1.0.1", version2 = "1"
 * 输出: 1
 *
 * 示例 3:
 *
 * 输入: version1 = "7.5.2.4", version2 = "7.5.3"
 * 输出: -1
 *
 * 示例 4：
 *
 * 输入：version1 = "1.01", version2 = "1.001"
 * 输出：0
 * 解释：忽略前导零，“01” 和 “001” 表示相同的数字 “1”。
 *
 * 示例 5：
 *
 * 输入：version1 = "1.0", version2 = "1.0.0"
 * 输出：0
 * 解释：version1 没有第三级修订号，这意味着它的第三级修订号默认为 “0”。
 *
 *
 *
 * 提示：
 *
 *
 * 版本字符串由以点 （.） 分隔的数字字符串组成。这个数字字符串可能有前导零。
 * 版本字符串不以点开始或结束，并且其中不会有两个连续的点。
 *
 *
 */

// @lc code=start
#include <sstream>
#include <string>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        char c;
        int num1 = 0, num2 = 0;
        istringstream ist1(version1), ist2(version2);
        while (ist1 >> num1 && ist2 >> num2)
        {
            if (num1 > num2)
                return 1;
            else if (num1 < num2)
                return -1;
            num1 = num2 = 0;
            ist1 >> c;
            ist2 >> c;
        }
        do
        {
            if (num1) return 1;
            ist1 >> c;
        } while (ist1 >> num1);
        while (ist2 >> num2)
        {
            if (num2) return -1;
            ist2 >> c;
        }
        return 0;
    }
};
// @lc code=end
