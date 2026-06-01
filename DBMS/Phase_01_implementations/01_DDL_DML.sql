-- DDL and DML commands

-- Create database
CREATE DATABASE IF NOT EXISTS CollegeDB;

-- Use Database
USE CollegeDB;

-- -------------
-- DDL Commands
-- -------------

-- Create TABLE

CREATE TABLE student(

    StudentID INT PRIMARY KEY,
    Name VARCHAR(50),
    Age INT,
    Department VARCHAR(30) 
);

-- Add column

ALTER TABLE student
ADD Email VARCHAR(100);

-- Remove column

ALTER TABLE student
DROP COLUMN Email;

---
-- DML commands
---

-- Insert Commands

INSERT INTO student
VALUES (101,'Aarav',20,'IT'), (102,'Rahul',21,'IT'), (103, 'Priya',19,'ECE');

INSERT INTO student
VALUES (104,'Aarav',20,'IT'), (105,'Rahul',21,'IT'), (106, 'Priya',19,'ECE');


-- View Records

SELECT*FROM student;

-- Update record

UPDATE student
SET Age= 22
WHERE StudentID= 102;

-- Delete Record

DELETE FROM student
WHERE StudentID= 103;

-- View final table

SELECT*FROM student;