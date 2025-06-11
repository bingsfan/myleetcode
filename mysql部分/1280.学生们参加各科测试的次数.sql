--
-- @lc app=leetcode.cn id=1280 lang=mysql
--
-- [1280] 学生们参加各科测试的次数
--

-- @lc code=start
# Write your MySQL query statement below
SELECT a.student_id,a.student_name,b.subject_name,COUNT(c.subject_name) as attended_exams 
from students a
CROSS JOIN subjects b
LEFT JOIN examinations c
on a.student_id = c.student_id and b.subject_name=c.subject_name
GROUP BY 
  a.student_id, a.student_name, b.subject_name
ORDER BY a.student_id,b.subject_name 
-- @lc code=end

