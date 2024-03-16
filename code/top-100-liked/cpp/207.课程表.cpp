/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode.cn/problems/course-schedule/description/
 *
 * algorithms
 * Medium (53.89%)
 * Likes:    1880
 * Dislikes: 0
 * Total Accepted:    372.3K
 * Total Submissions: 690.8K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
 *
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites
 * 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须
 * 先学习课程  bi 。
 *
 *
 * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 *
 *
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：true
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
 *
 * 示例 2：
 *
 *
 * 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
 * 输出：false
 * 解释：总共有 2 门课程。学习课程 1
 * 之前，你需要先完成​课程 0 ；并且学习课程 0
 * 之前，你还应先完成课程 1 。这是不可能的。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * prerequisites[i] 中的所有课程对 互不相同
 *
 *
 */

// @lc code=start
// 先修课程如果存在循环依赖则说明无法完成所有课程的学习，故问题转化为判断有向图中是否存
// 在环。BFS + 拓扑排序实现，主要步骤：
//     1. 构建图的邻接表表示，同时计算每门课程的入度（即依赖的前置课程的数量）
//     2. 将入度为零的课程加入待学习队列
//     3. 循环遍历待学习队列，直至队列为空，记录已学习的课程数量，将所有依赖已学
//        习的课程的其它课程的入度减一，将入度为零的未学习课程加入待学习队列
//     4. 显然，若最终完成的课程数量等于课程总数，则表示可以完成所有课程的学习
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> indegrees(numCourses, 0);

    for (const auto &edge : prerequisites) {
      graph.at(edge.back()).emplace_back(edge.front());
      ++indegrees.at(edge.front());
    }

    queue<int> learning_queue;
    int finished_courses_num = 0;
    for (int i = 0; i < numCourses; ++i) {
      if (indegrees.at(i) == 0) {
        learning_queue.push(i);
        ++finished_courses_num;
      }
    }

    while (!learning_queue.empty()) {
      int course = learning_queue.front();
      learning_queue.pop();

      for (const int neighbor : graph.at(course)) {
        --indegrees.at(neighbor);
        if (indegrees.at(neighbor) == 0) {
          learning_queue.push(neighbor);
          ++finished_courses_num;
        }
      }
    }

    return finished_courses_num == numCourses ? true : false;
  }
};
// @lc code=end
