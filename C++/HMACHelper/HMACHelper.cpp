#include "stdafx.h"
#include "hmacHelper.h"
#include <chrono>
#include "date.h"
#include <iostream>
#include "POCO/URI.h"
#include "Poco/HMACEngine.h"
#include "Poco/DigestEngine.h"
#include "Poco\Crypto\DigestEngine.h"
#include "Poco/Base64Encoder.h"

HMACHelper::HMACHelper()
{

};

HMACHelper::~HMACHelper()
{

};


std::string HMACHelper::hmacHelper(std::string sharedKey, std::string secretKey, std::chrono::system_clock::time_point date, std::string httpMethod, std::string requestURL,
    std::string contentType, std::string nepApplicationKey, std::string nepCorrelationID, std::string nepOrganization, std::string nepServiceVersion)
{
    std::string isoDate = date::format("%FT%T.000Z", date::floor<std::chrono::seconds>(date));
    std::string key = secretKey + isoDate;
    Poco::URI uri(requestURL);
    std::string pathAndQuery = uri.getPathAndQuery();
    std::string toSign = httpMethod + "\n" + pathAndQuery;
    if (contentType != "") {
        toSign += "\n" + contentType;
    }
    if (nepApplicationKey != "") {
        toSign += "\n" + nepApplicationKey;
    }
    if (nepCorrelationID != "") {
        toSign += "\n" + nepCorrelationID;
    }
    if (nepOrganization != "") {
        toSign += "\n" + nepOrganization;
    }
    if (nepServiceVersion != "") {
        toSign += "\n" + nepServiceVersion;
    }

    Poco::HMACEngine<SHA512Engine> hmacEng{ key };
    hmacEng.update(toSign);
    std::vector<unsigned char> digest = hmacEng.digest();
    std::string hexs = hmacEng.digestToHex(digest);
    std::stringstream ss;
    Poco::Base64Encoder b64Enc(ss);
    b64Enc.write((const char*) digest.data(), digest.size());
    b64Enc.close();
    std::string signature = ss.str().substr(0, 72) + ss.str().substr(74, 16);
    std::string auth = sharedKey + ":" + signature;
    return auth;
}

