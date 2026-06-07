-- Performing SQL queries using Sub queries and Nested Queries

USE CollegeDB;

-- 1. Single row subquery
-- Find students whose age is greater than avg.

SELECT*FROM student
WHERE Age>(SELECT AVG(Age) FROM student);

-- 2. Sub query with MAX()

SELECT*FROM student WHERE AGE= (SELECT MAX(Age) FROM student);

-- 3. subquery with min()

SELECT*FROM student WHERE AGE= (SELECT MIN(Age) FROM student);

-- 4. Nested Query using IN [Students enrolled in a course]

SELECT*FROM student WHERE StudentID IN (SELECT StudentID FROM Course);

-- 5. Nested Query using NOT IN

SELECT*FROM student WHERE StudentID NOT IN (SELECT StudentID FROM Course);

-- 6. Exists [ Check whether a matching course exists]

SELECT*FROM student S WHERE EXISTS (SELECT*FROM Course C WHERE S.StudentID= C.StudentId);

-- 7. Not exists [ find students without a course]

SELECT*FROM student S WHERE NOT EXISTS( SELECT*FROM Course C WHERE S.StudentID= C.StudentID);

-- 8. Any operator [ finds students older than atleast one student from IT department]

SELECT*FROM student WHERE Age > ANY (SELECT Age FROM student WHERE Department= 'IT');

-- 9. ALL operator [ Finds students older than all students from the IT department]

SELECT*FROM student WHERE Age > ALL(SELECT Age FROM student WHERE Department='IT');

-- 10. Correlated query [ Find students whose age is greater than the average age of their dpeartment]
 
 SELECT*FROM student S1 where Age > ( SELECT AVG(Age) FROM student S2 WHERE S1.Department = S2.Department);

 -- This is called nested query because the other query depends on another query
