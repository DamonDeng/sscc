#include <iostream>
#include "sscc.h"
#include <glog/logging.h>


using namespace std;
using namespace sscc;

int regionNameTest();

int main(int argc, char * argv[]){
  int result = 0;
  
  google::InitGoogleLogging(argv[0]);
  google::LogToStderr();

  //regionNameTest();

  LOG(INFO) << "INFO:"<<"Starting the test of SSCC" << endl;
 
  S3Client s3Client;

  s3Client.connectTo("ap-southeast-1", "testing.sig.damondeng.com");

 
  google::ShutdownGoogleLogging();


  return 0;
}

int regionNameTest(){
  S3Client s3Client;

  LOG(INFO) << s3Client.getEndPoint("cn-north-1") << endl;
  LOG(INFO) << s3Client.getEndPoint("ap-sourtheast-1") << endl;
  LOG(INFO) << s3Client.getEndPoint("ap-northest-1") << endl;
  LOG(INFO) << s3Client.getEndPoint("ap-northest-2") << endl;
  LOG(INFO) << s3Client.getEndPoint("ap-sourtheast-1") << endl;
  LOG(INFO) << s3Client.getEndPoint("ap-sourtheast-2") << endl;
  LOG(INFO) << s3Client.getEndPoint("us-east-2") << endl;
  LOG(INFO) << s3Client.getEndPoint("us-east-1") << endl;
  LOG(INFO) << s3Client.getEndPoint("us-west-1") << endl;
  LOG(INFO) << s3Client.getEndPoint("us-west-2") << endl;
  LOG(INFO) << s3Client.getEndPoint("ca-central-1") << endl;
  LOG(INFO) << s3Client.getEndPoint("eu-central-1") << endl;
  LOG(INFO) << s3Client.getEndPoint("") << endl;
  LOG(INFO) << s3Client.getEndPoint("") << endl;
  
  return 0;
  
}