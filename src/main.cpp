#include <iostream>
#include "sscc.h"
#include <glog/logging.h>
#include <curl/curl.h>


using namespace std;
using namespace damonsscc;


int main(int argc, char * argv[]){
  int result = 0;
  
  google::InitGoogleLogging(argv[0]);
  google::LogToStderr();

  LOG(INFO) << "INFO:"<<"Starting the test of SSCC" << endl;
 
  S3Client s3Client;

  s3Client.connectTo();

  google::ShutdownGoogleLogging();


  return 0;
}