/*   ---数据库视图创建---
	 本文件用于创建数据库课设所用的视图
	 View 1
	 用于Guest用户和普通学生用户的视图，
	 ------*/
USE ShareBookcase;
CREATE VIEW can_operate_book AS
SELECT book.Bk_No, Bk_Name, Bk_Author, Bk_Status, Bk_Press, Bk_Date, Op_Price
FROM book, operate
WHERE book.Bk_No = operate.Bk_No
	AND Bk_Status != 1;
