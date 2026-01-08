CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT SALARY FROM (
      SELECT SALARY , DENSE_RANK() OVER ( ORDER BY SALARY DESC) AS RNK
      FROM EMPLOYEE
      ) temp
      WHERE RNK =N

  );
END