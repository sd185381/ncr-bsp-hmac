# HMAC C++ Examples

The example helper function lives in `HMACHelper.cpp` (and `HMACHelper.h`) which contains the details on how to use HMAC to generate an `AccessKey`. 
The Auth3 console app references the HMACHelper library.

### Getting Started

1. Make sure `POCO C++ Library` is installed. Instructions for installation can be found [here](https://pocoproject.org/download.html).
2. Inside of `Auth3.cpp` update the `nepOrganization`, `secretKey`, and `sharedKey` with your values:

   ```
   secretKey = 'INSERT_SECRET'
   sharedKey = 'INSERT_SHARED'
   nepOrganization = 'INSERT_ORGANIZATION'
   ```

3. To test, run Auth3.cpp. This will test both the exampleGET and examplePOST functions.


© 2021 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
