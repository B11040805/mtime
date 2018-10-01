--TEST--
mtime_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('mtime')) {
	echo 'skip';
}
?>
--FILE--
<?php 
$ret = mtime_test1();

var_dump($ret);
?>
--EXPECT--
The extension mtime is loaded and working!
NULL
