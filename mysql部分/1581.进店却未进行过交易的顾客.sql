--
-- @lc app=leetcode.cn id=1581 lang=mysql
--
-- [1581] 进店却未进行过交易的顾客
--

-- @lc code=start
# Write your MySQL query statement below
SELECT customer_id,count(customer_id) count_no_trans
from Visits a
left JOIN Transactions b
on a.visit_id=b.visit_id
where transaction_id is NULL
GROUP BY customer_id
-- @lc code=end