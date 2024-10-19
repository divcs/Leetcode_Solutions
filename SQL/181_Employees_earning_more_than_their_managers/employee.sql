-- 1
select
 e.name as Employee
from
 employee as e
where
 e.salary > (
  select
   salary
  from
   employee
  where
   e.managerId = id
 )
 and e.managerId is not null;

-- 2
SELECT
 e.name as Employee
FROM
 Employee e
 INNER JOIN Employee m ON e.managerId = m.id
WHERE
 e.salary > m.salary;