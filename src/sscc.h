#ifndef DAMONDENG_SSCC
#define DAMONDENG_SSCC


#include <iostream>
#include <string>

using namespace std;

namespace damonsscc{
  class S3Client{

    public:
      S3Client();
      
      int connectTo();

      string getEndPoint(string regionName);

      static const string CN_REGION = "cn-north-1";
      
      static const string US_EAST_1 = "us-east-1";
      static const string US_WEST_1 = "us-west-1";
      static const string US_WEST_2 = "us-west-2";
      static const string EU_WEST_1 = "eu-west-1";
      static const string AP_SOUTHEAST_1 = "ap-southeast-1";
      static const string AP_SOUTHEAST_2 = "ap-southeast-2";
      static const string AP_NORTHEAST_1 = "ap-northeast-1";
      static const string SA_EAST_1 = "sa-east-1";
      static const string US_GOV_WEST_1 = "us-gov-west-1";
      static const string FIPS_US_GOV_WEST_1 = "fips-us-gov-west-1";

      static const string EP_US_EAST_1 = "s3.amazonaws.com";
      static const string EP_US_WEST_1 = "s3-us-west-1.amazonaws.com";
      static const string EP_US_WEST_2 = "s3-us-west-2.amazonaws.com";
      static const string EP_EU_WEST_1 = "s3-eu-west-1.amazonaws.com";
      static const string EP_AP_SOUTHEAST_1 = "s3-ap-southeast-1.amazonaws.com";
      static const string EP_AP_SOUTHEAST_2 = "s3-ap-southeast-2.amazonaws.com";
      static const string EP_AP_NORTHEAST_1 = "s3-ap-northeast-1.amazonaws.com";
      static const string EP_SA_EAST_1 = "s3-sa-east-1.amazonaws.com";
      static const string EP_US_GOV_WEST_1 = "s3-us-gov-west-1.amazonaws.com";
      static const string EP_FIPS_US_GOV_WEST_1 = "s3-fips-us-gov-west-1.amazonaws.com";

      
    private:

    
  };
}

#endif