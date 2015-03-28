#
# Table structure for table 'session_stats'
#

CREATE TABLE session_stats (
   sid varchar(32) NOT NULL,
   start_time varchar(20) DEFAULT '0' NOT NULL,
   page varchar(255),
   uri varchar(255),
   referer varchar(250) NOT NULL,
   addr varchar(15) NOT NULL,
   browser varchar(100),
   browser_image varchar(100),
   os varchar(100),
   os_image varchar(100),
   product_id int(11) DEFAULT '0' NOT NULL,
   user_id varchar(32),
   KEY session_identifier (sid),
   KEY start_time (start_time)
);

#
# Table structure for table 'stutter'
#

CREATE TABLE stutter (
   id int(13) NOT NULL auto_increment,
   date timestamp(14),
   username varchar(100),
   room varchar(100),
   message text,
   private varchar(100),
   action varchar(10),
   PRIMARY KEY (id)
);

#
# Table structure for table 'stutter_page'
#

CREATE TABLE stutter_page (
   sid varchar(32) DEFAULT '0' NOT NULL,
   page_time varchar(20) DEFAULT '0' NOT NULL
);

