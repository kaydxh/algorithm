/*
 * 递归-backtrace 回溯，不断试错，知错就改
 * 1 递归终止条件
 * 2 递归关系 =》 大问题转化为小问题
 */

/**
 * backtrace 模板.
 * @param[in] input 输入数据数组
 * @param[in] gap
 *当前位置距离目标位置的距离（判断是否满足搜索条件，若满足，则把path加入到result中）
 * @param[in] begin 本轮搜索的起点
 * @param[out] path 当前路径，也是中间结果
 * @param[out] result 存放最终结果
 * @param[inout] cur or gap 标记当前位置或距离目标的距离
 **/

void backtraceHelp(std::vector<int> &input, int gap, int begin,
                   std::vector<int> &path,
                   std::vector<std::vector<int>> &result) {
    if (gap == 0) {
        result.push_back(path);
        return;
    }

    for (int i = begin; i < input.size(); ++i) {
        //枝剪
        if (gap - input[i] < 0) {
            break;
        }

        path.push_back(input[i]);
        backtraceHelp(input, gap - input[i], i, path, result);
        path.pop_back();
    }
}

std::vector<std::vector<int>> backtrace(std::vector<int> &input, int gap) {
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    backtraceHelp(input, gap, 0, path, result);

    return result;
}
