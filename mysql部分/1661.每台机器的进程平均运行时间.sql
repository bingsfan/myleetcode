--
-- @lc app=leetcode.cn id=1661 lang=mysql
--
-- [1661] 每台机器的进程平均运行时间
--

-- @lc code=start
# Write your MySQL query statement below
SELECT 
	a.machine_id,
	ROUND(AVG(b.`timestamp`-a.`timestamp`),3) as processing_time 
FROM activity a
CROSS JOIN activity b
on 
	a.process_id = b.process_id 
	and a.machine_id=b.machine_id 
	and a.activity_type='start' 
	and b.activity_type='end'
GROUP BY a.machine_id
-- @lc code=end

