<?php
$server="localhost";
$user="id8493294_shuva";
$pass="39039820";
$dbname="id8493294_sensors";

$conn=mysqli_connect($server,$user,$pass,$dbname);

if(!$conn)
	die("<center>do not connect to server".mysqli_connect_error());

date_default_timezone_set('Asia/Kolkata');

$data = new \stdClass();

$current_date = date('d-m-Y');
$current_time = date('H:i:s',strtotime('-1 minute'));

$last_update_date = 0;
$last_update_time = 0;

$data->current_date = $current_date;


$qury="SELECT * from sensortable";

$result=mysqli_query($conn,$qury);
$num_rows=mysqli_num_rows($result);
if($num_rows>=1)
{
	while($rows=mysqli_fetch_array($result))
	{
		$data->temp = $rows['Temp'];
		$data->hum = $rows['Hum'];
		$data->pre = $rows['Pre'];
		$last_update_date = $rows['Date'];
		$last_update_time = $rows['Time'];
	}
}
if(($current_date == $last_update_date)&&($last_update_time>=$current_time))
{
	$data->status_text = "Status Online";
	$data->status_colour = "lime";
	$data->status_img = "pictures/online.png";
}

else if(($current_date != $last_update_date)||($current_date == $last_update_date)&&($last_update_time<$current_time))
{
	$data->status_text = "Status Offline";
	$data->status_colour = "red";
	$data->status_img = "pictures/offline.png";
}

$json_data = json_encode($data);

echo $json_data;
?>