CREATE TABLE SAILORS(
S_ID NUMBER PRIMARY KEY,
S_NAME VARCHAR2(30),
RATING NUMBER,
AGE NUMBER);

CREATE TABLE BOATS(
B_ID NUMBER PRIMARY KEY,
B_NAME VARCHAR2(30),
COLOR VARCHAR2(30));

CREATE TABLE RESERVES(
S_ID NUMBER REFERENCES SAILORS(S_ID),
B_ID NUMBER REFERENCES BOATS(B_ID),
DAY VARCHAR2(10),
PRIMARY KEY(S_ID,B_ID));

INSERT INTO SAILORS VALUES(1,'Steven Potter',1,21);
INSERT INTO SAILORS VALUES(2,'Olivia Greer',5,30);
INSERT INTO SAILORS VALUES(3,'John Smith',5,22);
INSERT INTO SAILORS VALUES(4,'Diana Robles',3,21);
INSERT INTO SAILORS VALUES(5,'Laura Osborne',4,21);
INSERT INTO SAILORS VALUES(6,'Tyler Henson',2,19);
INSERT INTO SAILORS VALUES(7,'Michael Garza',5,22);
INSERT INTO SAILORS VALUES(8,'Ashley Goodwin',4,79);
INSERT INTO SAILORS VALUES(9,'Melissa Black',0,88);

INSERT INTO BOATS VALUES(1,'Titanic','Grey');
INSERT INTO BOATS VALUES(2,'Sudo','Red');
INSERT INTO BOATS VALUES(3,'Grep','Green');
INSERT INTO BOATS VALUES(4,'Autocat','Blue');
INSERT INTO BOATS VALUES(5,'Sea Shore','Pink');
INSERT INTO BOATS VALUES(6,'Titatic Return','Black');
INSERT INTO BOATS VALUES(7,'Down Again','Green');
INSERT INTO BOATS VALUES(8,'KK','Red');
INSERT INTO BOATS VALUES(9,'Pomnic','Yellow');

INSERT INTO RESERVES VALUES(1,1,'Monday');
INSERT INTO RESERVES VALUES(1,2,'Wednesday');
INSERT INTO RESERVES VALUES(2,1,'Saturday');
INSERT INTO RESERVES VALUES(3,8,'Monday');
INSERT INTO RESERVES VALUES(2,9,'Tuesday');
INSERT INTO RESERVES VALUES(5,3,'Tuesday');
INSERT INTO RESERVES VALUES(8,4,'Sunday');
INSERT INTO RESERVES VALUES(2,7,'Thursday');
INSERT INTO RESERVES VALUES(9,6,'Friday');
INSERT INTO RESERVES VALUES(4,7,'Friday');
INSERT INTO RESERVES VALUES(2,3,'Sunday');
INSERT INTO RESERVES VALUES(7,2,'Monday');

SELECT BOATS.COLOR FROM BOATS,SAILORS,RESERVES WHERE BOATS.B_ID=RESERVES.B_ID AND SAILORS.S_ID=RESERVES.S_ID AND 

SAILORS.S_NAME LIKE 'Tarun'; 

SELECT SAILORS.S_ID, SAILORS.S_NAME FROM SAILORS,RESERVES WHERE SAILORS.S_ID=RESERVES.S_ID AND RESERVES.DAY LIKE 'Monday';

SELECT B_ID, B_NAME FROM BOATS WHERE COLOR IN('Green','Red'); 

DELETE FROM RESERVES WHERE S_ID IN(SELECT S_ID FROM SAILORS WHERE AGE>60);
DELETE FROM SAILORS WHERE AGE>60;
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

CREATE TABLE TEACHER(
TID NUMBER PRIMARY KEY,
NAME VARCHAR2(30),
DEPT VARCHAR2(10));

CREATE TABLE SUBJECT(
SUBNO NUMBER PRIMARY KEY,
SUBTITLE VARCHAR2(20));

CREATE TABLE TAUGHTBY(
TID NUMBER REFERENCES TEACHER(TID),
SUBNO NUMBER REFERENCES SUBJECT(SUBNO),
PRIMARY KEY(TID,SUBNO));

CREATE TABLE STUDENT(
ROLLNO NUMBER PRIMARY KEY,
SNAME VARCHAR2(30),
CITY VARCHAR2(30));

INSERT INTO TEACHER VALUES(1,'Pinaki Roy','EE');
INSERT INTO TEACHER VALUES(2,'Amit Paul','CSE');
INSERT INTO TEACHER VALUES(3,'Debasis Chakroborty','CSE');
INSERT INTO TEACHER VALUES(4,'Micheal Rodgers','IT');
INSERT INTO TEACHER VALUES(5,'GY','CSE');
INSERT INTO TEACHER VALUES(6,'Holly Scott','ECE');
INSERT INTO TEACHER VALUES(7,'Sara Wilson','EE');
INSERT INTO TEACHER VALUES(8,'Charles Valdez','ECE');
INSERT INTO TEACHER VALUES(9,'Fred Garcia','Physics');
INSERT INTO TEACHER VALUES(10,'Terry Ellison','Physics');

INSERT INTO SUBJECT VALUES(1,'Thermodynamics');
INSERT INTO SUBJECT VALUES(2,'Quantum Physics');
INSERT INTO SUBJECT VALUES(3,'Automata');
INSERT INTO SUBJECT VALUES(4,'Circuit Drawing');
INSERT INTO SUBJECT VALUES(5,'DBMS');

INSERT INTO TAUGHTBY VALUES(10,2);
INSERT INTO TAUGHTBY VALUES(1,5);
INSERT INTO TAUGHTBY VALUES(3,1);
INSERT INTO TAUGHTBY VALUES(9,1);
INSERT INTO TAUGHTBY VALUES(2,4);

INSERT INTO STUDENT VALUES(1,'Ryan Campbell','Kolkata');
INSERT INTO STUDENT VALUES(22,'Denise Collins','Kolkata');
INSERT INTO STUDENT VALUES(21,'Tanya Dominguez','Behala');
INSERT INTO STUDENT VALUES(32,'Denise Reeves','Kolkata');
INSERT INTO STUDENT VALUES(73,'Sean Frazier','New Garia');
INSERT INTO STUDENT VALUES(74,'Chad Morrow','Kolkata');
INSERT INTO STUDENT VALUES(10,'Paul Campbell','Howrah');
INSERT INTO STUDENT VALUES(6,'Charles Brown','Kolkata');
INSERT INTO STUDENT VALUES(24,'Philip Hodges','Garia');
INSERT INTO STUDENT VALUES(51,'Kayla Singh','Kolkata');

SELECT TEACHER.NAME FROM TEACHER,SUBJECT,TAUGHTBY WHERE TEACHER.TID=TAUGHTBY.TID AND TAUGHTBY.SUBNO=SUBJECT.SUBNO AND  SUBJECT.SUBTITLE LIKE 'Thermodynamics' AND TEACHER.DEPT LIKE 'Physics';

UPDATE SUBJECT SET SUBTITLE='RDBMS' WHERE SUBTITLE LIKE 'DBMS';

SELECT * FROM STUDENT WHERE ROLLNO BETWEEN 20 AND 25 AND CITY LIKE 'Kolkata'; 

SELECT * FROM STUDENTS WHERE CITY LIKE 'Kolkata' ORDER BY ROLLNO DESC;