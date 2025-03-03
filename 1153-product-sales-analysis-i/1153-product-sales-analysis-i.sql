# Write your MySQL query statement below
select pr.product_name,s.year,s.price from
Sales as s
join Product as pr
on pr.product_id=s.product_id;