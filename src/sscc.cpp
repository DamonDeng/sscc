#include "sscc.h"
#include <glog/logging.h>
#include <curl/curl.h>

namespace damonsscc{
  
  S3Client::S3Client(){

  }

  static const char* EQ = "=";
  static const char* SIGNATURE = "Signature";
  static const char* AWS_HMAC_SHA256 = "AWS4-HMAC-SHA256";
  static const char* AWS4_REQUEST = "aws4_request";
  static const char* SIGNED_HEADERS = "SignedHeaders";
  static const char* CREDENTIAL = "Credential";
  static const char* NEWLINE = "\n";
  static const char* X_AMZ_SIGNED_HEADERS = "X-Amz-SignedHeaders";
  static const char* X_AMZ_ALGORITHM = "X-Amz-Algorithm";
  static const char* X_AMZ_CREDENTIAL = "X-Amz-Credential";
  static const char* UNSIGNED_PAYLOAD = "UNSIGNED-PAYLOAD";
  static const char* X_AMZ_SIGNATURE = "X-Amz-Signature";
  static const char* SIGNING_KEY = "AWS4";
  static const char* LONG_DATE_FORMAT_STR = "%Y%m%dT%H%M%SZ";
  static const char* SIMPLE_DATE_FORMAT_STR = "%Y%m%d";
  static const char* EMPTY_STRING_SHA256 = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";
  
  size_t http_data_writer(void* data, size_t size, size_t nmemb, void* content);

  const string S3Client::CN_REGION = "cn-north-1";
  
  const string S3Client::US_EAST_1 = "us-east-1";
  const string S3Client::US_EAST_2 = "us-east-2";
  const string S3Client::US_WEST_1 = "us-west-1";
  const string S3Client::US_WEST_2 = "us-west-2";
  const string S3Client::AP_SOUTH_1 = "ap-south-1";
  const string S3Client::EU_WEST_1 = "eu-west-1";
  const string S3Client::EU_WEST_2 = "eu-west-2";
  const string S3Client::AP_SOUTHEAST_1 = "ap-southeast-1";
  const string S3Client::AP_SOUTHEAST_2 = "ap-southeast-2";
  const string S3Client::AP_NORTHEAST_1 = "ap-northeast-1";
  const string S3Client::AP_NORTHEAST_2 = "ap-northeast-2";
  const string S3Client::CA_CENTRAL_1 = "ca-central-1";
  const string S3Client::EU_CENTRAL_1 = "eu-central-1";
  const string S3Client::SA_EAST_1 = "sa-east-1";
  const string S3Client::US_GOV_WEST_1 = "us-gov-west-1";
  const string S3Client::FIPS_US_GOV_WEST_1 = "fips-us-gov-west-1";


  int S3Client::connectTo(){
    LOG(INFO) << "Starting to connect to S3" << endl;

    curl_global_init(CURL_GLOBAL_ALL);
    CURL *ecurl_ = curl_easy_init();

    string s3EndPoint = getEndPoint("ap-northeast-1"); 

    std::string buffer_;

    if(ecurl_){
      curl_easy_setopt(ecurl_, CURLOPT_URL, s3EndPoint.c_str());//url地址  
      //curl_easy_setopt(ecurl_,CURLOPT_POST,0); //设置问非0表示本次操作为post 
      curl_easy_setopt(ecurl_, CURLOPT_WRITEFUNCTION, http_data_writer); 
      curl_easy_setopt(ecurl_, CURLOPT_WRITEDATA, &buffer_);

      int res = curl_easy_perform(ecurl_);

      LOG(INFO) << "the response code: " << res << endl;

      LOG(INFO) << "The response: " << endl;

      LOG(INFO) << buffer_ << endl;
    }else{
      LOG(WARNING) << "Failed to make the request" << endl;
    }

    return 0;
  }

  string S3Client::getEndPoint(string regionName){
    
    string endPoint = "s3." + regionName + ".amazonaws.com";

    
    if(regionName == CN_REGION)
    {
      endPoint = endPoint + ".cn"; 
    }

    return endPoint;
  }

  size_t http_data_writer(void* data, size_t size, size_t nmemb, void* content)  
  {  
      long totalSize = size*nmemb;  
      std::string* symbolBuffer = (std::string*)content;  
      if(symbolBuffer)  
      {  
          symbolBuffer->append((char *)data, ((char*)data)+totalSize);  
      }  
      return totalSize;  
  }  


}