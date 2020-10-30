<?php

$Temp=$_GET["Temp"];
$Hum=$_GET["Hum"];
$Pre=$_GET["Pre"];
if($Temp==NULL || $Hum==NULL || $Pre==NULL)
{
	echo "NULL data received.";
	header("HTTP/1.1 404 NOT FOUND");
}
else
{
	header("HTTP/1.1 200 OK");
	echo "Temp:".$Temp."<br>";
	echo "Hum:".$Hum."<br>";
	echo "Pre:".$Pre."<br>";

	date_default_timezone_set('Asia/Kolkata');
	$current_date = date('d-m-Y');
	$current_time = date('H:i:s');
	$pre_time = date('H:i:s',strtotime('-1 minute'));

	$server="localhost";
	$user="id8493294_shuva";
	$pass="39039820";
	$dbname="id8493294_sensors";

	$conn=mysqli_connect($server,$user,$pass,$dbname);

	if($conn)
	echo "connected succesfully";
	else
	die("do not connect to server".mysqli_connect_error());
	echo "</br>";

	$qury="DELETE from sensortable where Date <= '".$current_date."' and Time<'".$pre_time."'";

	mysqli_query($conn,$qury);

	$qury="INSERT INTO sensortable(Temp,Hum,Pre,Date,Time)VALUES('$Temp','$Hum','$Pre','$current_date','$current_time')";//INSERT INTO `sensortable` (`id`, `Temp`, `Hum`, `Pre`) VALUES (NULL, '25', '45', '123456');

	$result=mysqli_query($conn,$qury);

	if($result)
	echo "NEW RECORD INSERTED SUCCESSFULLY";
	else
	echo "ERROR SEND DATA".mysqli_error($conn);
}
?>