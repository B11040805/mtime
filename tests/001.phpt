--TEST--
Check if mtime is loaded
--SKIPIF--
<?php
if (!extension_loaded('mtime')) {
	echo 'skip';
}
?>
--FILE--
<?php 
echo 'The extension "mtime" is available';
?>
--EXPECT--
The extension "mtime" is available
