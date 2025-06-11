--
-- @lc app=leetcode.cn id=1934 lang=mysql
--
-- [1934] 确认率
--

-- @lc code=start
# Write your MySQL query statement below
SELECT a.user_id,
ROUND(
	IFNULL(SUM(IF(b.action='confirmed',1,0))/COUNT(b.action),0),2
)
 as confirmation_rate
from signups a
left join confirmations b
on a.user_id=b.user_id
GROUP BY a.user_id
-- @lc code=end

