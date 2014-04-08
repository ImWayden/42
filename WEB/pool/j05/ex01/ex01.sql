DROP TABLE IF EXISTS ft_table;
CREATE TABLE ft_table (
	  login VARCHAR(8) DEFAULT 'toto' NOT NULL,
	  id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
	  groupe  ENUM ('staff', 'student', 'other') NOT NULL,
	  date_de_creation DATE  NOT NULL,
);
