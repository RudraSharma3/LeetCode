# Write your MySQL query statement below
SELECT name , population , area
FROM World
WHERE World.population >= 25000000 OR World.area >= 3000000;