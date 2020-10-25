/*	---数据库课程设计触发器板块---
	Trigger 1
	Bk_Status_Updata_Rd		当修改Bk_Status时更新一条Rd记录，因为MySQL没有语句级触发器，所以这个用语句实现
	Trigger 2
	Rd_Time_End_Notice		当当前时间迫近服务结束日期时把图书状态从 0 修改为 -1。
	------*/
USE ShareBookcase;
CREATE TRIGGER Rd_Time_End_Notice
AFTER INSERT
ON record FOR EACH ROW
BEGIN
	SET @id=(SELECT Bk_No FROM record WHERE Bk_Status_N=0 AND DATEDIFF(Rd_Time_End,CURRENT_DATE)<7);
	UPDATE Book SET Bk_Status=-1 WHERE Bk_No=@id;
END

CREATE TRIGGER Rd_Time_S_C
AFTER UPDATE
ON Book FOR EACH ROW

BEGIN
	IF(SELECT St_No_C FROM record WHERE Bk_Status_N=0 AND DATEDIFF(Rd_Time_End,CURRENT_DATE)<0) THEN
    SET @id=(SELECT St_No_C FROM record WHERE Bk_Status_N=0 AND DATEDIFF(Rd_Time_End,CURRENT_DATE)<0);
    SET @id2=(SELECT St_No_S FROM record WHERE Bk_Status_N=0 AND DATEDIFF(Rd_Time_End,CURRENT_DATE)<0);
	UPDATE operate SET St_No=@id2 WHERE St_No=@id;
	INSERT INTO record(Bk_No,St_No_S,St_No_C,Rd_Time,Bk_Status_O,Bk_Status_N) VALUE ('100001',@id,@id2,CURRENT_DATE,-1,2);
    END IF;
END
