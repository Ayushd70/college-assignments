CREATE TABLE CLIENT_MASTER(
CLIENTNO VARCHAR2(6) PRIMARY KEY CHECK(CLIENTNo LIKE 'C%'),
NAME VARCHAR2(20) NOT NULL,
CITY VARCHAR2(15),
PINCODE NUMBER(8),
STATE VARCHAR2(15),
BALANCEDUE NUMBER(10,2));

CREATE TABLE PRODUCT_MASTER(
PRODUCTNO VARCHAR2(6) PRIMARY KEY CHECK(PRODUCTNo LIKE 'P%'),
DESCRIPTION VARCHAR2(15) NOT NULL,
PROFITPERCENT NUMBER(4,2) NOT NULL,
UNITMEASURE VARCHAR2(10) NOT NULL,
QTYINHAND NUMBER(8) NOT NULL,
REORDERLVL NUMBER(8) NOT NULL,
SELLPRICE NUMBER(8,2) NOT NULL CHECK(SELLPRICE<>0),
COSTPRICE NUMBER(8,2) NOT NULL CHECK(COSTPRICE<>0));

CREATE TABLE SALESMAN_MASTER(
SALESMANNO VARCHAR2(6) PRIMARY KEY CHECK(SALESMANNO LIKE 'S%'),
NAME VARCHAR2(20) NOT NULL,
ADDRESS1 VARCHAR2(10) NOT NULL,
ADDRESS2 VARCHAR2(10),
CITY VARCHAR2(20),
PINCODE NUMBER(7),
STATE VARCHAR2(20),
SAL NUMBER(8,2) NOT NULL CHECK(SAL<>0),
TGTTOGET NUMBER(6,2) NOT NULL CHECK(TGTTOGET<>0),
YTDSALES NUMBER(6,2) NOT NULL,
REMARKS VARCHAR2(20));

CREATE TABLE SALES_ORDER(
ORDERNO VARCHAR2(6) PRIMARY KEY CHECK(ORDERNO LIKE 'O%'),
ORDERDATE DATE,
CLIENTNO VARCHAR2(6) REFERENCES CLIENT_MASTER(CLIENTNO),
DELYADDRESS VARCHAR2(25),
SALESMANNO VARCHAR2(6) REFERENCES SALESMAN_MASTER(SALESMANNO),
DELYTYPE CHAR(1) DEFAULT('F') CHECK(DELYTYPE IN ('P','F')),
BILLEDYN CHAR(1),
DELYDATE DATE ,
ORDERSTATUS VARCHAR2(10) CHECK(ORDERSTATUS IN ('Fullfilled','Backorder','Cancelled','In Process')),
CHECK(DELYDATE >= ORDERDATE));

CREATE TABLE SALES_ORDER_DETAILS(
ORDERNO VARCHAR2(6) REFERENCES SALES_ORDER(ORDERNO),
PRODUCTNO VARCHAR2(6) REFERENCES PRODUCT_MASTER(PRODUCTNO),
QTYORDERED NUMBER(8),
QTYDISP NUMBER(8),
PRODUCTRATE NUMBER(10,2),
PRIMARY KEY(ORDERNO,PRODUCTNO));

INSERT INTO CLIENT_MASTER VALUES('C00001','Ivan Bayross','Mumbai',400054,'Maharashtra',15000);
INSERT into CLIENT_MASTER VALUES('C00002','MamataMazumdar','Madras',780001,'Tamil Nadu',0);
INSERT into CLIENT_MASTER VALUES('C00003','ChhayaBankar','Mumbai',400057,'Maharastra',5000);
INSERT into CLIENT_MASTER VALUES('C00004','Ashwini Joshi','Bangalore',560001,'karnataka',0);
INSERT into CLIENT_MASTER VALUES('C00005','hansei Colaco','Mumbai',400060,'Maharastra',2000);
INSERT into CLIENT_MASTER VALUES('C00006','Deepak Sharma','Mangalore',5600050,'Karnataka',0);

INSERT INTO PRODUCT_MASTER VALUES('P00001','T-Shirt',5,'Piece',200,50,350,250);
INSERT INTO PRODUCT_MASTER VALUES('P0345','Shirts',6,'Piece',150,50,500,350);
INSERT INTO PRODUCT_MASTER VALUES('P06734','Cotton Jeans',5,'Piece',100,20,600,450);
INSERT INTO PRODUCT_MASTER VALUES('P07865','Jeans',5,'Piece',100,20,750,500);
INSERT INTO PRODUCT_MASTER VALUES('P07868','Trousers',2,'Piece',150,50,850,550);
INSERT INTO PRODUCT_MASTER VALUES('P07885','Pullovers',3,'Piece',80,30,700,450);
INSERT INTO PRODUCT_MASTER VALUES('P07965','Denim Shirts',4,'Piece',100,50,350,250);
INSERT INTO PRODUCT_MASTER VALUES('P07975','Lyers Tops',5,'Piece',70,40,300,175);
INSERT INTO PRODUCT_MASTER VALUES('P08865','Skirts',5,'Piece',75,30,450,300);

INSERT INTO SALESMAN_MASTER VALUES('S00001','Omkar','A/14','Jadavpur','Kolkata',700032,'West Bengal',3000,100,50,'Good');
INSERT INTO SALESMAN_MASTER VALUES('S00002','Omkar','65','Chandni','Delhi',110006,'Delhi',3000,200,100,'Good');
INSERT INTO SALESMAN_MASTER VALUES('S00003','Raj','P-7','Bandra','Mumbai',400032,'Maharastra',3000,200,100,'Good');
INSERT INTO SALESMAN_MASTER VALUES('S00004','AShish','A/5','Agara','Bengaluru',560034,'Karnataka',3000,200,150,'Good');

INSERT INTO SALES_ORDER VALUES('O19001','10-July-02','C00001','Haldia','S00001','F','N','20-July-02','IN Process');
INSERT INTO SALES_ORDER VALUES('O19002','15-Jun-02','C00002','Bakura','S00002','P','N','27-Jun-02','Cancelled');
INSERT INTO SALES_ORDER VALUES('O46865','11-Feb-02','C00003','Garia','S00003','F','Y','20-Feb-02','Fullfilled');
INSERT INTO SALES_ORDER VALUES('O19003','15-Mar-02','C00001','New Garia','S00001','F','Y','7-Apr-02','Fullfilled');
INSERT INTO SALES_ORDER VALUES('O46866','12-May-02','C00004','Santoshpur','S00002','P','N','22-May-02','Cancelled');
INSERT INTO SALES_ORDER VALUES('O19008','14-Jul-02','C00005','Dhakuria','S00004','F','N','26-Jul-02','In Process');

INSERT INTO SALES_ORDER_DETAILS VALUES('O19001','P00001',4,4,525);
INSERT INTO SALES_ORDER_DETAILS VALUES('O19001','P07965',2,1,8400);
INSERT INTO SALES_ORDER_DETAILS VALUES('O19001','P07885',2,1,5250);
INSERT INTO SALES_ORDER_DETAILS VALUES('O19002','P00001',10,0,525);
INSERT INTO SALES_ORDER_DETAILS VALUES('O46865','P07868',3,3,3150);
INSERT INTO SALES_ORDER_DETAILS VALUES('O46865','P07885',3,1,5250);
INSERT INTO SALES_ORDER_DETAILS VALUES('O46865','P00001',10,10,525);
INSERT INTO SALES_ORDER_DETAILS VALUES('O46865','P0345',4,4,1050);
INSERT INTO SALES_ORDER_DETAILS VALUES('O19003','P0345',2,2,1050);
INSERT INTO SALES_ORDER_DETAILS VALUES('O19003','P06734',1,1,12000);
INSERT INTO SALES_ORDER_DETAILS VALUES('O46866','P07965',1,0,8400);
INSERT INTO SALES_ORDER_DETAILS VALUES('O46866','P07975',1,0,1050);
INSERT INTO SALES_ORDER_DETAILS VALUES('O19008','P00001',10,5,525);
INSERT INTO SALES_ORDER_DETAILS VALUES('O19008','P07975',5,3,1050);