--
-- @lc app=leetcode.cn id=577 lang=mysql
--
-- [577] 员工奖金
--

-- @lc code=start
# Write your MySQL query statement below
SELECT name , bonus
FROM employee a
left join bonus b
ON
	a.empId=b.empId
WHERE b.bonus<1000 or bonus is null
-- @lc code=end

