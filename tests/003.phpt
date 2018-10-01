--TEST--
mtime_test2() Basic test
--SKIPIF--
<?php
if (!extension_loaded('mtime')) {
	echo 'skip';
}
?>
--FILE--
<?php 
var_dump(mtime_test2());
var_dump(mtime_test2('PHP'));
?>
--EXPECT--
string(11) "Hello World"
string(9) "Hello PHP"
