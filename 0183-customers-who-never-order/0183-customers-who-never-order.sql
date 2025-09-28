# Write your MySQL query statement below
select C.name as Customers from Customers C
Left join Orders O on C.id=O.customerId 
where O.customerId is null;