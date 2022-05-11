#include <node.h>
#include "random.hpp"

using v8::Context;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Exception;

void node_random_number_export(const FunctionCallbackInfo<Value> &args) {
    srand((unsigned)time(NULL) * getpid());

    Isolate *isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();

    double min = args[0].As<Number>()->Value();
    double max = args[1].As<Number>()->Value();

    if (args.Length() < 2) {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Expected 2 arguments").ToLocalChecked()));
        return;
    }

    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Expected type number").ToLocalChecked()));
        return;
    }

    int random_number = random_generator::number(min, max);
    Local<Number> output = Number::New(isolate, random_number);

    args.GetReturnValue().Set(output);
}

void node_random_string_export(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();

    if (args.Length() < 1) {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Expected argument length").ToLocalChecked()));
        return;
    }

    if (!args[0]->IsNumber()) {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Expected type number").ToLocalChecked()));
        return;
    }

    double length = args[0].As<Number>()->Value();

    std::string allowed_chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    if (args.Length() > 1) {
        v8::String::Utf8Value inputType(isolate, args[1]);
        std::string diff_allowed_chars(*inputType);

        allowed_chars = diff_allowed_chars;
    }
    
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, random_generator::string(int(length), allowed_chars).c_str()).ToLocalChecked());
}

void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "number", node_random_number_export);
    NODE_SET_METHOD(exports, "string", node_random_string_export);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)