// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/fetch.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/fetch_options.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitFetch::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "initOptions", InitOptions);
  
    Nan::Set(target, Nan::New<String>("Fetch").ToLocalChecked(), object);
  }

  
/*
 * @param FetchOptions opts
   * @param Number version
     * @return Number  result    */
NAN_METHOD(GitFetch::InitOptions) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("FetchOptions opts is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number version is required.");
  }

// start convert_from_v8 block
  git_fetch_options * from_opts;
  from_opts = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  unsigned int from_version;
  from_version = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_fetch_init_options(
from_opts
,from_version
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitFetch::constructor_template;
 