-- SQL queries character number and group functions

-- Character functions

USE CollegeDB;

SELECT Upper(Name) AS UpperCaseName
FROM student;

-- LOWER()

SELECT LOWER(Name) AS LowerCaseName
FROM student;

-- Length()
SELECT Name, LENGTH(Name) AS NameLength
FROM student;

-- concat()
SELECT Concat(Name,'-',Department) AS StudentInfo
FROM student;

--- Numeric Functions

-- abs()
SELECT ABS(-25) AS AbsoluteValue;

-- round()
SELECT ROUND(25.6789,2) AS RoundedValue;

-- Mod()
SELECT MOD(25,4) AS Remainder;

--Power()
SELECT POWER(2,5) AS Result;

---DATE Functions

SELECT CURDATE(); 
SELECT CURTIME();
 
 -- Current date and time
 SELECT NOW();

 -- Extract Year
 SELECT YEAR(NOW()) AS CurentYear; 

 -- Extract Month
 SELECT MONTH(NOW()) AS CurrentMonth;

 -- Extract Day
 SELECT DAY(NOW()) AS CurrentDay;

 --- Group (aggregate ) Functions

 SELECT COUNT(*) AS Totalstudents
 FROM student;

SELECT MAX(Age) AS MaximumAge
FROM student;

-- Min()
SELECT MIN(Age) AS MinimumAge
FROM student;

-- Avg()
SELECT AVG(Age) AS AverageAge
FROM student;

-- SUM()
SELECT SUM(Age) AS TotalAge
FROM student;

--- Group by
-- Count students department wise

SELECT Department, COUNT(*) AS TotalStudents
FROM student
GROUP BY Department

-- Having
-- Show deparments having more than 2 students

SELECT Department, COUNT(*) AS TotalStudents
FROM student
GROUP BY Department
HAVING COUNT(*)>2;
