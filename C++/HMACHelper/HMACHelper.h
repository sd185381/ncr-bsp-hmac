#pragma once
#include <string>
#include <chrono>
#include "Poco/Crypto/DigestEngine.h"

class HMACHelper
{
public:
    HMACHelper();

    virtual ~HMACHelper();

    /**
    * Function to generate HMAC Key.
    * @param {string} sharedKey - A user's Shared Key
    * @param {string} secretKey - A user's Secret Key
    * @param {time_point} date - An unformated date object
    * @param {string} httpMethod - GET/POST/PUT
    * @param {string} requestURL - The API url requesting against
    * @param {string} [contentType=application/json] - Optional
    * @param {string} [nepApplicationKey] - Optional
    * @param {string} [nepCorrelationID] - Optional
    * @param {string} [nepOrganization] - Optional
    * @param {string} [nepServiceVersion] - Optional
    * @returns {string} sharedkey:hmac
    */
    std::string hmacHelper(std::string sharedKey, std::string secretKey, std::chrono::system_clock::time_point date, std::string httpMethod, std::string requestURL,
        std::string contentType = "application/json", std::string nepApplicationKey = "", std::string nepCorrelationID = "", std::string nepOrganization = "", std::string nepServiceVersion = "");
};


class SHA512Engine : public Poco::Crypto::DigestEngine
{
public:
    enum
    {
        BLOCK_SIZE = 128,
        DIGEST_SIZE = 64
    };

    SHA512Engine()
        : DigestEngine("SHA512")
    {
    }

};
