#ifndef CLIENT_ENCODERDECODER_H
#define CLIENT_ENCODERDECODER_H

#include <string>
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace std;

class EncoderDecoder {
public:
    EncoderDecoder();

    const char* encode(string& msg); //returns bytes[]
    const string decode(const char bytes[]);
    /*
    short bytesToShort(char* bytesArr)
       {
           short result = (short)((bytesArr[0] & 0xff) << 8);
           result += (short)(bytesArr[1] & 0xff);
           return result;
       }

    void shortToBytes(short num, char* bytesArr)
       {
           bytesArr[0] = ((num >> 8) & 0xFF);
           bytesArr[1] = (num & 0xFF);
       }
     */




};
#endif //CLIENT_ENCODERDECODER_H
