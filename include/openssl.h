#ifndef GITOPENSSL_H
#define GITOPENSSL_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
#include <git2/sys/openssl.h>
}


using namespace node;
using namespace v8;

class GitOpenssl : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

   

  private:


   
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(SetLocking);
};

#endif
