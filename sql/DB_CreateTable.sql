/*	-- -数据库课程设计二维表板块-- -
	共四个表
		- Student
		- Book
		- Operate
		- Record
	-- -- -- */
USE ShareBookcase;

CREATE TABLE Student(					-- 学生表
	St_No			char(11) NOT NULL,	-- 学号
	St_Name			char(20) NOT NULL,	-- 用户名
	St_Age			tinyint	NOT NULL,	-- 年龄
	St_Sex			bit		NOT NULL,	-- 性别
	St_Profession	char(30),			-- 专业
	St_Building		char(2),			-- 宿舍楼
	St_Room			char(4),			-- 宿舍号
	St_Password		char(16),			-- 用户密码
	PRIMARY KEY(St_No),					-- 学号是主码	
	CHECK(								-- 约束条件
		St_Age >= 18					-- 学生年龄必须大于18岁
		)
	);

CREATE TABLE Book(
	Bk_No			char(11) NOT NULL,	-- 图书编号
	Bk_Name			char(20) NOT NULL,	-- 图书名称
	Bk_Status		tinyint  NOT NULL,	-- 图书状态
	Bk_Type			char(5),			-- 图书类型
	Bk_Author		char(20),			-- 图书作者
	Bk_Press		char(30),			-- 图书出版社
	Bk_Date			date,				-- 图书出版时间
	/*采用数字标识
	-1	图书快到期了，需要尽快归还
	0	从此平台借的书，需要归还
	1	图书是学生通过此平台(买卖或赠送)获得的
	2	图书只可以借
	4	图书只可以卖，卖包括送
	8	图书可以借或卖(2×4)
	2^x	符合此表达式表示书的所有权在于St_No
	*/
	PRIMARY KEY(Bk_No)					-- 图书编号是主码
	);

CREATE TABLE Operate(
	St_No			char(11) NOT NULL,	-- 学生学号
	Bk_No			char(11) NOT NULL,	-- 图书编号
	Op_Day			tinyint,			-- 借阅时限(多少天)
	/*当Op_type = (2 or 8) 时才有效*/
	Op_Price		float,				-- 价格
	/*当Op_type = (4 or 8) 时才有效*/
	PRIMARY KEY(St_No, Bk_No),	-- 三个属性构成主码
	FOREIGN KEY(St_No) REFERENCES Student(St_No),	-- 学生学号参照学生表
	FOREIGN KEY(Bk_No) REFERENCES Book(Bk_No)		-- 图书编号参照图书表
	);

CREATE TABLE Record(
	Rd_No			int NOT NULL AUTO_IC,		-- 记录编号
	Bk_No			char(11) NOT NULL,	-- 图书编号
	St_No_S			char(11) NOT NULL,	-- 学生服务端
	St_No_C			char(11) NOT NULL,	-- 学生客户端
	Rd_Time			datetime NOT NULL,	-- 记录生成时间
	Bk_Status_O		tinyint NOT NULL,	-- 
	Bk_Status_N		tinyint NOT NULL,	-- 
	Rd_Time_End		datetime,			-- 服务结束时间
	PRIMARY KEY(Rd_No),					-- 记录编号是主码
	FOREIGN KEY(Bk_No) REFERENCES Book(Bk_No),		-- 图书编号参照图书表
	FOREIGN KEY(St_No_S) REFERENCES Student(St_No),	-- 参照学生表
	FOREIGN KEY(St_No_C) REFERENCES Student(St_No)	-- 参照学生表
	);
