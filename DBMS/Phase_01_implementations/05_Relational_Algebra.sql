-- Performing Relational algebra operations using sql queries

-- Creating second table

USE CollegeDB;

CREATE TABLE Course(
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(50),
    StudentID INT
);

-- Inserting DATA

INSERT INTO Course VALUES (1,'DBMS',101),(2,'CN',102),(3,'OS',104),(4,'AI',106);

-- 1. Selection.

-- σ Department='CSE' (Student). SElect students from CSE departemnt

SELECT*FROM student
WHERE Department='CSE';

-- 2. Project(pi)

-- π Name,Department (Student)
SELECT Name, Department
FROM student;


-- 3. Union

-- Create another table

CREATE  TABLE Student_new(
    StudentID INT,
    Name VARCHAR(50)
);

INSERT INTO Student_new VALUES (201,'Ravi'),(202,'Kiran');

SELECT Name FROM student
UNION
SELECT Name FROM Student_new;

-- 4. Set Difference(-)

-- Students present in student but not in student_new
-- Relational Algebra: Student- Student_new

SELECT Name FROM student
WHERE Name NOT IN (SELECT Name FROM Student_new)

-- 5. Cartesian Product
-- Relational Algebra: Student x Course

SELECT*FROM student CROSS JOIN Course;

-- 6. JOIN [MOST IMP Operation]
-- Relational Algebra: Student ⨝ Course

SELECT student.StudentID, student.Name, Course.CourseName FROM student INNER JOIN Course ON student.StudentID= Course.StudentID;

-- 7. Rename
-- Relational Algebra: ρ S(Student)
SELECT*FROM student AS S; 
