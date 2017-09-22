#ifndef DAMONDENG_SSCC
#define DAMONDENG_SSCC


#include <iostream>
#include <string>

using namespace std;

namespace sscc{
  class S3Client{

    public:
      S3Client();
      
      int connectTo(string bucketName);
      int connectTo(string regionName, string bucketName);


      string getEndPoint(string regionName);

      static const string CN_REGION;
      
      static const string US_EAST_1;
      static const string US_EAST_2;
      static const string US_WEST_1;
      static const string US_WEST_2;
      static const string AP_SOUTH_1;//ap-south-1
      static const string EU_WEST_1;
      static const string EU_WEST_2;
      static const string AP_SOUTHEAST_1;
      static const string AP_SOUTHEAST_2;
      static const string AP_NORTHEAST_1;
      static const string AP_NORTHEAST_2;
      static const string CA_CENTRAL_1; //ca-central-1
      static const string EU_CENTRAL_1; //eu-central-1
      static const string SA_EAST_1;
      static const string US_GOV_WEST_1;
      static const string FIPS_US_GOV_WEST_1;

  
      
    private:

      string getURL(string endPoint, string bucketName);
      
    
  };
}

#endif