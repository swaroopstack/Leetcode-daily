# Write your MySQL query statement below

# using not in

/*SELECT name as Customers
FROM Customers
WHERE id NOT IN (SELECT customerId FROM Orders);
*/

# using join
select c.name as Customers from customers c left join orders o 
on c.id=o.customerId
where o.customerId is null;