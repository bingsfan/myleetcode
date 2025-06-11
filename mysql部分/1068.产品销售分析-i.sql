--
-- @lc app=leetcode.cn id=1068 lang=mysql
--
-- [1068] 产品销售分析 I
--

-- @lc code=start
# Write your MySQL query statement below
select b.product_name,a.year,a.price
from Sales a
inner join Product b
on a.product_id=b.product_id
-- @lc code=end

