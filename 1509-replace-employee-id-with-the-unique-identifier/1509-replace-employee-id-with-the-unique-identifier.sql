# Write your MySQL query statement below
SELECT e.name, u.unique_id 
FROM Employees AS e
LEFT JOIN EmployeeUNI as u
ON e.id = u.id;