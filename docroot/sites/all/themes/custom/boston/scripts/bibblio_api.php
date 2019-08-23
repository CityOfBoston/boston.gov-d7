<?php
// Check for server environment
if (!isset($_SERVER["AH_SITE_NAME"])){
	// Local env
	define('DRUPAL_ROOT', $_SERVER["DOCUMENT_ROOT"]);
	require_once DRUPAL_ROOT.'/includes/bootstrap.inc';
	drupal_bootstrap(DRUPAL_BOOTSTRAP_VARIABLES);
	$bibblio_id = variable_get('bibblio_id');
	$bibblio_secret = variable_get('bibblio_secret');
	$testing = TRUE;
} else {
	// Acquia env
	$bibblio_id = $_ENV['bibblio_id'];
	$bibblio_secret = $_ENV['bibblio_secret'];
	$testing = FALSE;
}

function checkDomain(){
	$allowed = array(
	'https://bostonuat.prod.acquia-sites.com',
	'https://bostonci.prod.acquia-sites.com',
	'boston.gov',
	); 

	if (isset($_SERVER['HTTP_ORIGIN']) && in_array($_SERVER['HTTP_ORIGIN'], $allowed)){
		return TRUE;
	} else {
		return FALSE;
	}
}
if (checkDomain() == TRUE || $testing == TRUE): 

	class Bibblio {
		
		function preparePostFieldsToken($items) {
		  	$params = array();
		  	foreach ($items as $key => $value) {
		    	$params[] = $key . '=' . urlencode($value);
		  	}
		  	return implode('&', $params);
		}

		function getToken(){
			$ch = curl_init();
			$data = array(
				'client_id' => $bibblio_id,
				'client_secret' => $bibblio_secret,
			);
			curl_setopt($ch, CURLOPT_URL, "https://api.bibblio.org/v1/token"); 
			curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
			curl_setopt($ch, CURLOPT_HEADER, FALSE);
			curl_setopt($ch, CURLOPT_POST, TRUE);
			curl_setopt($ch, CURLOPT_POSTFIELDS, $this->preparePostFieldsToken($data) );
			curl_setopt($ch, CURLOPT_HTTPHEADER, array(
				"Content-Type: application/x-www-form-urlencoded"
			));
			$response = curl_exec($ch);
			curl_close($ch);
			return $response;
		}

		function getItem($data_update){
			$ch = curl_init();
			$token = $this->getToken();
			$token = json_decode($token);
			curl_setopt($ch, CURLOPT_URL, "https://api.bibblio.org/v1/content-items/".$data_update['contentItemId']); 
			curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
			curl_setopt($ch, CURLOPT_HEADER, FALSE);
			curl_setopt($ch, CURLOPT_HTTPHEADER, array(
			  "Content-Type: application/json",
			  "Authorization: Bearer ".$token->{'access_token'}
			));

			$response = curl_exec($ch);
			$http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
			curl_close($ch);
			print '{"status" : "'.$http_code.'","response":'.$response.'}';
		}

		function createItem($data_update){
			$ch = curl_init();
			$data_json = json_encode($data_update['fields']);
			$token = $this->getToken();
			$token = json_decode($token);
			curl_setopt($ch, CURLOPT_URL, "https://api.bibblio.org/v1/content-item-url-ingestions"); 
			curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
			curl_setopt($ch, CURLOPT_HEADER, FALSE);
			curl_setopt($ch, CURLOPT_POSTFIELDS, $data_json);
			curl_setopt($ch, CURLOPT_HTTPHEADER, array(
			  "Content-Type: application/json",
			  "Authorization: Bearer ".$token->{'access_token'}
			));

			$response = curl_exec($ch);
			$http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
			curl_close($ch);
			print '{"status" : "'.$http_code.'","response":'.$response.'}';
		}

		function updateItem($data_update){
			$ch = curl_init();
			$data = $data_update;
			$data_json = json_encode($data_update['fields']);
			$token = $this->getToken();
			$token = json_decode($token);
			curl_setopt($ch, CURLOPT_URL, "https://api.bibblio.org/v1/content-items/".$data['contentItemId']); 
			curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
			curl_setopt($ch, CURLOPT_HEADER, FALSE);
			curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "PUT");
			curl_setopt($ch, CURLOPT_POSTFIELDS, $data_json);
			curl_setopt($ch, CURLOPT_HTTPHEADER, array(
			  "Content-Type: application/json",
			  "Authorization: Bearer ".$token->{'access_token'}
			));

			$response = curl_exec($ch);
			$http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
			curl_close($ch);
			//return $http_code;
			print '{"status" : "'.$http_code.'","response":'.$response.'}';
		}

	}
	
	// Get POST data and perform API request to specific Bibblio endpoint
	$bibblio = new Bibblio ();
	$getPostData = json_decode(file_get_contents('php://input'), true);
	if (isset($getPostData)){
			if ($getPostData['operation'] == "update"){
				$bibblio->updateItem($getPostData);

			} else if($getPostData['operation'] == "create"){
				$bibblio->createItem($getPostData);

			} else if($getPostData['operation'] == "get"){
				$bibblio->getItem($getPostData);

			} else{
				print '{"status" : "error","response":"no post operation found"}';
			}
			//print $getPostData['payload']['name'];
	} else{
		print '{"status" : "error","response":"no post data"}';	
	}
	
else:
	print '{"status":"error", "response":"not authroized"}';
endif;
?>
