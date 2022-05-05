#include <node.h>
#include <random>
#include <string>
#include <unistd.h>

int randomNumber(int min, int max) {
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do {
        x = rand();
    } while (x >= RAND_MAX - remainder);
    return min + x % n;
}

std::string randomString(int len) {
   std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   std::string newstr;
   int pos;

   while(newstr.size() != len) {
    pos = ((rand() % (str.size() - 1)));
    newstr += str.substr(pos,1);
   }
   
   return newstr;
}

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Number;
using v8::Context;

void Random(const FunctionCallbackInfo<Value>& args) {
    srand((unsigned)time(NULL) * getpid());     

    Isolate* isolate = args.GetIsolate();
    Local<Context> context = isolate -> GetCurrentContext();

    double value1 = args[1].As<Number>() -> Value();
    double value2 = args[2].As<Number>() -> Value();

    v8::String::Utf8Value inputType(isolate, args[0]);
    std::string inputTypeString(*inputType);

    if (inputTypeString == "") {
        inputTypeString = "number";
    }

    if (inputTypeString == "string") {
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, randomString(int(value1)).c_str()).ToLocalChecked());
    } else if (inputTypeString == "number") {
        int random_number = randomNumber(value1, value2);
        Local<Number> output = Number::New(isolate, random_number);

        args.GetReturnValue().Set(output);
    } else if (inputTypeString == "random") {
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, randomString(int(randomNumber(1, 1000))).c_str()).ToLocalChecked());
    }
}

void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "random", Random);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)