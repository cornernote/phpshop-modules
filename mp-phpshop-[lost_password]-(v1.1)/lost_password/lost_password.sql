ALTER TABLE `auth_user_md5` 
  ADD `reset_key` VARCHAR( 32 ) ,
  ADD `reset_password` VARCHAR( 32 );
