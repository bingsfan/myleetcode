--
-- @lc app=leetcode.cn id=1378 lang=mysql
--
-- [1378] 使用唯一标识码替换员工ID
--

-- @lc code=start
# Write your MySQL query statement below
select b.unique_id,a.name
from Employees a 
left join EmployeeUNI b
on a.id = b.id

-- @lc code=end

