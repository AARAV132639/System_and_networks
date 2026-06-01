-- SQL operators

USE CollegeDB;

-- View table
SELECT*FROM student;

-- ##############
-- Arithmetic Operators
-- ------------------

-- Add 5 to age
SELECT Name, Age, Age+5 AS FutureAge
FROM student;

-- ## Comparision Operators

-- Equal to
SELECT*FROM student 
Where Department='CSE';

-- Not equal to
SELECT*FROM student
WHERE Department <> 'IT';

-- Greater than
SELECT*FROM student
WHERE Age > 20;

-- Less than
SELECT*FROM student
WHERE Age<21;

-- Greater than or equal to
SELECT*FROM student
WHERE Age>=21;

-- Less than or equal to
SELECT*FROM student
WHERE Age<=20;

-- ## Speical Operators ##

-- Between
SELECT*FROM student
WHERE Age BETWEEN 20 and 22;

-- IN
SELECT*FROM student
WHERE Department IN ('CSE','IT');

-- Like
SELECT*FROM student
WHERE Name Like 'A%';

-- IS NULL
SELECT*FROM student
WHERE Department IS NULL;

-- IS NOT NULL
SELECT*FROM student
WHERE Department IS NOT NULL;

