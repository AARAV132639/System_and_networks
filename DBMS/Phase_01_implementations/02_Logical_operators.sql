-- DBMS Experiment 2
--  Logical operators

USE CollegeDB;

-- Sample data

SELECT*FROM student;

-- AND operator

SELECT*FROM student
WHERE Age > 20 AND Department = 'IT';

-- OR operator
SELECT*FROM student
WHERE Department='CSE' OR Department ='IT';

-- NOT operator
SELECT*FROM student
WHERE NOT Department='CSE';

-- Combined Logical Operators
SELECT*FROM student
WHERE(Age>19 AND Department= 'CSE') OR Department='IT';