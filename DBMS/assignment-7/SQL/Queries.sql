1.
select ename from emp where sal=(select max(sal) from emp);

2.
select ename from emp where sal=(select max(sal) from emp where job='Salesman');

3.
select ename from emp where sal=(select min(sal) from emp where job='Clerk');

4.
select dname from dept where dept_no=(select dept_no from emp group by dept_no having avg(sal)=(select max(avg(sal)) from emp group by dept_no));

5.
select ename from emp where sal>(select sal from emp where ename like 'Turner');

6.
select ename from emp where hiredate>(select hiredate from emp where ename like 'Allen');

7.
select dname from dept where dept_no=(select dept_no from emp where ename like 'Ford');

8.
select dname from dept where dept_no=(select dept_no from emp where sal=(select max(sal) from emp));

9.
select loc from dept where dept_no=(select dept_no from emp where ename like 'Smith');

10.
select loc from dept where dept_no in (select dept_no from emp where job like 'Manager');

11.
select comm from emp where ename like 'Martin';

12.
select ename from emp where sal>(select max(sal) from emp where dept_no=(select dept_no from dept where loc like 'Dallas'));

13.
select dname from dept where dept_no=(select dept_no from emp group by dept_no having count(ename)=0);

14.
select ename from emp where hiredate=(select hiredate from emp where ename like 'Adams');

15.
select dname from dept where dept_no in (select dept_no from emp where comm is not null);

16.
select ename from emp where sal in (select min(sal) from emp group by dept_no); 

17.
select dname from dept where dept_no in (select dept_no from emp group by dept_no having count(ename)>1);

query using join_
    |
    |
    V
select distinct(dname) from dept,emp where dept.dept_no=emp.dept_no;
