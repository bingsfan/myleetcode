--
-- @lc app=leetcode.cn id=1757 lang=mysql
--
-- [1757] 可回收且低脂的产品
--

-- @lc code=start
# Write your MySQL query statement below
select product_id from Products
where low_fats='Y' and recyclable='Y'
-- @lc code=end

