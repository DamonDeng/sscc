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

  int S3Client::connectTo(){
    LOG(INFO) << "Starting to connect to S3" << endl;

    curl_global_init(CURL_GLOBAL_ALL);
    CURL *ecurl_ = curl_easy_init();

    const char pURL[] = "http://www.baidu.com/"; 

    std::string buffer_;

    if(ecurl_){
      curl_easy_setopt(ecurl_, CURLOPT_URL, pURL);//url地址  
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
    if(regionName == US_EAST_1){
      return EP_US_EAST_1;
    }
    else if(regionName == US_WEST_1){
      return EP_US_WEST_1;
    }
    else if(regionName == US_WEST_2){
      return EP_US_WEST_2;
    }
    else if(regionName == EU_WEST_1){
      return EP_EU_WEST_1;
    }
    else if(regionName == AP_SOUTHEAST_1){
      return EP_AP_SOUTHEAST_1;
    }
    else if(regionName == AP_SOUTHEAST_2){
      return EP_AP_SOUTHEAST_2;
    }
    else if(regionName == AP_NORTHEAST_1){
      return EP_AP_NORTHEAST_1;
    }
    else if(regionName == SA_EAST_1){
      return EP_SA_EAST_1;
    }
    else if(regionName == US_GOV_WEST_1){
      return EP_US_GOV_WEST_1;
    }
    else if(regionName == FIPS_US_GOV_WEST_1){
      return EP_FIPS_US_GOV_WEST_1;
    }
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