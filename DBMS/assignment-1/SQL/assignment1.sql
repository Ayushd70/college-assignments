CREATE TABLE DEPT(
DEPT_NO NUMBER (2) PRIMARY KEY,
DNAME VARCHAR2(25),
LOC VARCHAR2(20));

CREATE TABLE EMP(
EMPNO NUMBER(4) PRIMARY KEY,
ENAME VARCHAR2(20),
JOB CHAR(20),
MGR NUMBER(4),
HIREDATE DATE,
SAL NUMBER(5),
COMM NUMBER(5),
DEPT_NO NUMBER(2) REFERENCES DEPT(DEPT_NO));

ALTER TABLE EMP ADD(PHONE NUMBER(10));

ALTER TABLE EMP MODIFY(JOB VARCHAR2(20));

ALTER TABLE EMP DROP COLUMN PHONE;

DESC EMP;

DESC DEPT;

INSERT INTO DEPT VALUES(10,'Accounting','New York');
insert into DEPT values(20,'Research','Dallas');
insert into DEPT values(30,'Sales','Chicago');
insert into DEPT values(40,'Operations','Boston');

insert into EMP values(7369,'Smith','Clerk',7902,'17-DEC-80',800,NULL,20);
insert into EMP values(7499,'Allen','Salesman',7698,'20-FEB-81',1600,300,30);
insert into EMP values(7521,'Ward','Salesman',7698,'22-FEB-81',1250,500,30);
insert into EMP values(7566,'Jones','Manager',7839,'02-APR-81',2975,NULL,20);
insert into EMP values(7654,'Martin','Salesman',7698,'28-SEP-81',1250,1400,30);
insert into EMP values(7698,'Blake','Manager',7839,'01-MAY-81',2850,NULL,30);
insert into EMP values(7782,'Clark','Manager',7839,'09-JUN-81',2450,NULL,10);
insert into EMP values(7788,'Scott','Analyst',7566,'09-DEC-82',3000,NULL,20);
insert into EMP values(7839,'King','President',NULL,'17-NOV-81',5000,NULL,10);
insert into EMP values(7844,'Turner','Salesman',7698,'08-SEP-81',1500,500,30);
insert into EMP values(7876,'Adams','Clerk',7788,'12-JAN-83',1100,NULL,20);
insert into EMP values(7900,'James','Clerk',7698,'03-DEC-81',950,NULL,30);
insert into EMP values(7902,'Ford','Analyst',7566,'04-DEC-81',3000,NULL,20);
insert into EMP values(7934,'Miller','Clerk',7782,'23-JAN-82',1300,NULL,10);