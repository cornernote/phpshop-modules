#
# Table structure for table 'newsletter_email'
#

CREATE TABLE newsletter_email (
   email_id varchar(32) NOT NULL,
   email_name varchar(64),
   email_address varchar(64),
   email_done tinyint(4) DEFAULT '1' NOT NULL,
   mdate timestamp(14),
   PRIMARY KEY (email_id)
);

#
# Table structure for table 'newsletter_letter'
#

CREATE TABLE newsletter_letter (
   letter_id int(11) NOT NULL auto_increment,
   letter_subject varchar(32),
   letter_detail text,
   letter_done tinyint(4) DEFAULT '0' NOT NULL,
   mdate timestamp(14),
   PRIMARY KEY (letter_id)
);

