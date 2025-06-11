--
-- @lc app=leetcode.cn id=570 lang=mysql
--
-- [570] 至少有5名直接下属的经理
--

-- @lc code=start
# Write your MySQL query statement below
select name 
from employee
where id in (SELECT managerid
    FROM Employee
    GROUP BY managerId
		HAVING count(id)>=5)
-- @lc code=end

