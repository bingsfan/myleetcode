--
-- @lc app=leetcode.cn id=197 lang=mysql
--
-- [197] 上升的温度
--

-- @lc code=start
# Write your MySQL query statement below
select a.id
from weather as a 
cross join weather as b 
on datediff(a.recordDate,b.recordDate) = 1
WHERE a.temperature>b.temperature
-- @lc code=end

