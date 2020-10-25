# 数据库课程设计
本文档用于记录自己在对于课设的一些思量

## 说明
代码中有一个数据库连接函数，其中有数据库地址和用户名以及密码，上传到 GitHub 上后被 GitGuardian 告知 MySQL Assignment 泄漏，但是没关系，那个数据库是刚开始接触云服务器时租赁阿里云轻量应用服务器，现在已经没在用了。

## 课设题目--共享书柜
共享书柜意在帮助在校学生之间建立一个图书转借、购买、赠送的多方面交易平台。

## 需求分析
旧书的浪费，图书馆经典书籍的常年“离馆”，学生手中好书的闲置

## E-R图
见笔记本

## 二维表
- Student
- Book
   - 以自己有和借的书为原型建立表
- Operate
   - Bk_Status  
   0,1,2,3,4,8,16,32,64,128
- Record
   - 记录需要仔细生成

## 测试数据
30-50个学生，15-30本书的样子就行了  
见'InsertData.sql'

## 触发器
- Bk_Status_Update_Rd
- Rd_Time_End_Notice
- Rd_Time_St_Request

## GUI
2019年5月2日  
界面的话，设计一个普通就够了  
对于用户信息数据库，就使用'Student'表，这个表再加一个'St_Password'项  
图书交易的话采用实时交易，也就是'Rd_Time'和'Rd_Time_St'采用一样的值  
2019年5月14日  
主界面设计完毕，下一步实现登录界面（包含登录失败和成功的情形），需要用到界面的跳转或者转变
其他不重要界面先弄个基本的框架，其他的先不弄    
图标看情况  
2019年5月21日
应该加快进度，改用MySQL数据库看能不能解决无法连接的问题  
2019年6月3日
MySQL数据库能成功连接，改用MySQL完成课程设计  
还有两周就要答辩了，必须在端午节结束前完成课设程序，再用一周写课程报告及排错  

