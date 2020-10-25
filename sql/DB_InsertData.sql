/*	---数据库课程设计数据板块---
	为了测试功能，需要插入一些数据来进行实际测试
	------*/
USE ShareBookcase;

INSERT INTO Student
VALUES
('20181680101', 'Aidan', '18', 1, 'Computer Sciense', '10', '110', '123'),
('20181680102', 'Alex', '18', 0, 'Computer Sciense', '8', '210', '123'),
('20181680105', 'Alice', '18', 0, 'Computer Sciense', '8', '211', '123'),
('20181680107', 'Bob', '18', 1, 'Computer Sciense', '10', '330', '123'),
('20181680108', 'Brant', '18', 1, 'Computer Sciense', '10', '215', '123'),
('20181680109', 'Brent', '19', 1, 'Computer Sciense', '10', '216', '123'),
('20181680110', 'Cray', '18', 0, 'Computer Sciense', '8', '210', '123'),
('20181680113', 'Cody', '18', 1, 'Computer Sciense', '10', '216', '123'),
('20181680115', 'Cole', '19', 1, 'Computer Sciense', '10', '110', '123'),
('20181680116', 'Colin', '18', 1, 'Computer Sciense', '10', '330', '123'),
('20181680117', 'Cosmo', '18', 1, 'Computer Sciense', '10', '333', '123'),
('20183680007', 'Billy', '19', 1, 'Software',  '10', '321', '123'),
('20181690008', 'Cara', '19', 0, 'Software', '9', '129', '123'),
('20181690011', 'Daniel', '18', 1, 'Software', '10', '321', '123'),
('20181690013', 'Daphne', '18', 0, 'Software', '9', '129', '123'),
('20181690007', 'Edith', '18', 1, 'Software', '10', '321', '123'),
('20182680125', 'Alan', '18', 0, 'Mathenatics', '8', '118', '123'),
('20182680126', 'Andy', '19', 0, 'Mathenatics', '8', '218', '123'),
('20182680129', 'Bert', '18', 1, 'Mathenatics', '10', '330', '123'),
('20182680130', 'Betty', '18', 0, 'Mathenatics', '8', '118', '123'),
('20182680131', 'Bill', '19', 1, 'Mathenatics', '10', '110', '123'),
('20182680132', 'Bonnie', '18', 0, 'Mathenatics', '8', '119', '123'),
('20182680133', 'Brown', '18', 1, 'Mathenatics', '10', '341', '123'),
('20182680137', 'Carina', '18', 0, 'Mathenatics', '8', '119', '123'),
('20182680139', 'Carmen', '18', 1, 'Mathenatics', '10', '330', '123');

INSERT INTO Book
VALUES
('020001', 'Data Structure', 128, 'TP', 'Deng Junhui', 'Tsinghua Publishing House', '2014-09-01'),
('000001', 'Learn OpenCV', 0, 'TP', 'Adrian kaehler', 'Tsinghua Publishing House', '2008-07-01'),
('000002', 'Learn OpenCV 3', 0,'TP', 'Adrian kaehler', 'Tsinghua Publishing House', '2017-09-01'),
('020002', 'C Primer Plus', 64, 'TP', 'Stephen Prata', 'Post & Telecom Press', '2013-05-10'),
('020003', 'C++ Primer Plus', 64, 'TP', 'Stephen Prata', 'Post & Telecom Press', '2015-05-10'),
('020004', 'Algorithms', 4, 'TP', 'Robert Sedgewick', 'Post & Telecom Press', '2018-02-01'),
('020005', 'Computer Network', 32, 'TP', 'Xie Renxi', 'Electronic Industry Press', '2017-12-01');

INSERT INTO Operate
VALUES
('20181680108', '020003', 30, 35.0),
('20181680108', '020002', 30, 50.0),
('20181690011', '000001', 30, 0),
('20181690013', '000002', 30, 0),
('20182680130', '020004', NULL, 60.0),
('20182680131', '020005', 30, NULL),
('20182680137', '020001', 30, 10.0);
