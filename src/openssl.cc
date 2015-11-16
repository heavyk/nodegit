// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/openssl.h>
 }

#include "../include/functions/copy.h"
#include "../include/openssl.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitOpenssl::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "setLocking", SetLocking);
  
    Nan::Set(target, Nan::New<String>("Openssl").ToLocalChecked(), object);
  }

  
/*
   * @return Number  result    */
NAN_METHOD(GitOpenssl::SetLocking) {
  Nan::EscapableHandleScope scope;

   int result = git_openssl_set_locking(
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitOpenssl::constructor_template;
 