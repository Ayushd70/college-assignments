TABLES:
CLIENT_MASTER
PRODUCT_MASTER
SALESMAN_MASTER
SALES_ORDER
SALES_ORDER_DETAILS

SELECT NAME FROM CLIENT_MASTER WHERE NAME LIKE '_a%';

SELECT * FROM CLIENT_MASTER WHERE CITY LIKE '_a%';

SELECT * FROM CLIENT_MASTER WHERE City IN ('Bombay', 'Delhi');

SELECT * FROM CLIENT_MASTER WHERE BalanceDue > 10000;

SELECT * FROM SALES_ORDER WHERE EXTRACT(month FROM OrderDate) = 1;

SELECT * FROM SALES_ORDER WHERE ClientNo IN ('C00001', 'C00002');

SELECT * FROM PRODUCT_MASTER WHERE (SellPrice > 2000 AND SellPrice <= 5000);

SELECT * FROM PRODUCT_MASTER WHERE SellPrice > 1500;
SELECT SellPrice * 0.15 AS new_price FROM PRODUCT_MASTER;

SELECT Name, City, State FROM CLIENT_MASTER WHERE State <> 'Maharashtra';

SELECT COUNT(OrderNo) FROM SALES_ORDER;

SELECT AVG(SellPrice) AS average_price FROM PRODUCT_MASTER;  

SELECT MAX(SellPrice) AS max_price, MIN(SellPrice) AS min_price FROM PRODUCT_MASTER;

SELECT COUNT(SellPrice) FROM PRODUCT_MASTER WHERE SellPrice >= 1500;
