<?php
$testing = FALSE;
function checkDomain(){
	$valid = FALSE;
	$acceptedDomains = array(
		'boston.gov',
		'bostonci.prod.acquia-sites.com'
	);
	foreach($acceptedDomains as $value){
		if(strpos($_SERVER['HTTP_HOST'], $value) !== FALSE){
			$valid = TRUE;
		}	
	}
	return $valid;
}
if (checkDomain() == TRUE || $testing == TRUE ){
	$ch = curl_init();
	$data = array("client_id" => "f3d3a706","client_secret" => "ad8d245fdeba1c7af2f263407c21cc22");
	function preparePostFields($items) {
	  $params = array();
	  foreach ($items as $key => $value) {
	    $params[] = $key . '=' . urlencode($value);
	  }
	  return implode('&', $params);
	}

	curl_setopt($ch, CURLOPT_URL, "https://api.bibblio.org/v1/token");
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
	curl_setopt($ch, CURLOPT_HEADER, FALSE);
	curl_setopt($ch, CURLOPT_POST, TRUE);
	curl_setopt($ch, CURLOPT_POSTFIELDS, preparePostFields($data) );
	curl_setopt($ch, CURLOPT_HTTPHEADER, array(
	  "Content-Type: application/x-www-form-urlencoded"
	));
	
	$response = curl_exec($ch);
	curl_close($ch);
	print '{"index":'.$response.',"status":"ok"}';

} else {
	print '{"status":"not authorized"}';
}
?>