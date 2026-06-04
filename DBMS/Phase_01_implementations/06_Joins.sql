USE CollegeDB;

-- EquiJoin
SELECT student.StudentID, student.Name, Course.CourseName FROM student INNER JOIN Course ON student.StudentID=Course.StudentID

-- Non equi Join
CREATE TABLE Grade(
    MinMarks INT,
    MaxMarks INT,
    Grade CHAR(1)
);

INSERT INTO Grade VALUES (0,39,'F'),(40,59,'C'),(60,79,'B'),(80,100,'A');

CREATE TABLE Marks(
    StudentID INT,
    Marks INT
);

INSERT INTO Marks VALUES (101,85),(102,65),(103,55),(104,30);

-- Non Equi join query
SELECT Marks.StudentID, Marks.Marks, Grade.Grade FROM Marks JOIN Grade ON Marks.Marks BETWEEN Grade.MinMarks AND Grade.MaxMarks;

-- Left Out Join
-- Show all students even if they dont have a course

SELECT student.studentID, student.Name, Course.CourseName FROM student LEFT JOIN Course ON student.StudentID= Course.StudentID;

--Right outer join
-- shwo all courses even if no mathcing student exists

SELECT student.studentID, student.Name, Course.CourseName FROM student RIGHT JOIN Course ON student.StudentID= Course.CourseID;

-- FULL outer join
-- MYSQL doesnt support full outer join directly

SELECT student.studentID, student.Name, Course.CourseName FROM student LEFT JOIN Course ON student.StudentID= Course.CourseID
UNION
SELECT student.studentID, student.Name, Course.CourseName FROM student RIGHT JOIN Course ON student.StudentID= Course.CourseID;



-- Concept not clear of left join, right join and full outer join
-- Inner Join (equi join) is by far the most commonly used in production systems because it connects related datas stored across normalized tables